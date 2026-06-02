/*
 * Copyright (c) 2008-2025 Stefan Krah. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#if defined(__GNUC__) || defined(__COMPCERT__)
  #define _GNU_SOURCE
#endif


#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mpdecimal.h"
#include "test.h"
#include "vctest.h"


#define MAXLINE 400000
#define MAXTOKEN 32

#ifndef _MSC_VER
  #include <inttypes.h>
  #define ASSERT(p) if (!(p)) {abort();}
#else
  #define ASSERT(p) if (!(p)) {mpd_err_fatal("assertion failed");}
#endif


static int extended = 1;
static int global_failure = 0;
static int file_failure = 0;

static mpd_ssize_t
strtossize(const char *s, char **end, int base)
{
    int64_t retval;

    errno = 0;
    retval = _mpd_strtossize(s, end, base);
    if (errno == 0 && (retval > MPD_SSIZE_MAX || retval < MPD_SSIZE_MIN)) {
        errno = ERANGE;
    }
    if (errno == ERANGE) {
        return (retval < 0) ? MPD_SSIZE_MIN : MPD_SSIZE_MAX;
    }

    return (mpd_ssize_t)retval;
}

static void
mpd_init_rand(mpd_t *x)
{
    long r = random() % 100;
    uint8_t sign = random()%2;

    if (r >= 80) {
        mpd_minalloc(x);
    }
    else if (r >= 60) {
        mpd_minalloc(x);
        mpd_set_flags(x, sign);
    }
    else if (r >= 40) {
        mpd_setspecial(x, sign, MPD_NAN);
    }
    else if (r >= 20) {
        mpd_setspecial(x, sign, MPD_SNAN);
    }
    else {
        mpd_setspecial(x, sign, MPD_INF);
    }
}

/* These ranges are needed for the official test suite
 * and are generally not problematic at all. */
#if defined(MPD_CONFIG_64)
  #define MPD_READ_MAX_PREC 1070000000000000000LL
#elif defined(MPD_CONFIG_32)
  #define MPD_READ_MAX_PREC 1070000000
#else
  #error "config not defined"
#endif

static void
mpd_readcontext(mpd_context_t *ctx)
{
    if (extended) {
        ctx->prec=MPD_READ_MAX_PREC;
        ctx->emax=MPD_READ_MAX_PREC;
        ctx->emin=-MPD_READ_MAX_PREC;
    }
    else {
        ctx->prec=MPD_MAX_PREC;
        ctx->emax=MPD_MAX_EMAX;
        ctx->emin=MPD_MIN_EMIN;
    }

    ctx->round=MPD_ROUND_HALF_UP;
    ctx->traps=MPD_Traps;
    ctx->status=0;
    ctx->newtrap=0;
    ctx->clamp=0;
    ctx->allcr=1;
}

static void
mpd_testcontext(mpd_context_t *ctx)
{
    if (extended) {
    #if defined(MPD_CONFIG_64)
        ctx->prec=MPD_MAX_PREC;
        ctx->emax=MPD_MAX_EMAX;
        ctx->emin=MPD_MIN_EMIN;
    #elif defined(MPD_CONFIG_32)
        /* These ranges are needed for the official test suite. */
        ctx->prec=999999999;
        ctx->emax=999999999;
        ctx->emin=-999999999;
    #else
      #error "config not defined"
    #endif
    }
    else {
        ctx->prec=MPD_MAX_PREC;
        ctx->emax=MPD_MAX_EMAX;
        ctx->emin=MPD_MIN_EMIN;
    }

    ctx->round=MPD_ROUND_HALF_UP;
    ctx->traps=MPD_Traps;
    ctx->status=0;
    ctx->newtrap=0;
    ctx->clamp=0;
    ctx->allcr=1;
}

static void
mpd_assert_context_ok(const mpd_context_t *ctx)
{
    ASSERT(0 < ctx->prec && ctx->prec <= MPD_READ_MAX_PREC);
    ASSERT(0 <= ctx->emax && ctx->emax <= MPD_READ_MAX_PREC);
    ASSERT(-MPD_READ_MAX_PREC <= ctx->emin && ctx->emin <= 0);
    ASSERT(0 <= ctx->round && ctx->round < MPD_ROUND_GUARD);
    ASSERT(ctx->traps <= MPD_Max_status);
    ASSERT(ctx->status <= MPD_Max_status);
    ASSERT(ctx->clamp == 0 || ctx->clamp == 1);
    ASSERT(ctx->allcr == 0 || ctx->allcr == 1);
}

/* Known differences that are within the spec. */
struct result_diff {
    const char *id;
    const char *calc;
    const char *expected;
};

struct status_diff {
    const char *id;
    uint32_t calc;
    uint32_t expected;
};

static struct result_diff ulp_cases[] = {
    /* Cases where the result is allowed to differ by less than one ULP.
     * Only needed if ctx->allcr is 0. */
    { "expx013", "1.001000", "1.001001" },
    { "expx020", "1.000000", "1.000001" },
    { "expx109", "0.999999910000004049999878", "0.999999910000004049999879" },
    { "expx1036", "1.005088", "1.005087" },
    { "expx350", "1.0000000", "1.0000001" },
    { "expx351", "1.0000000", "1.0000001" },
    { "expx352", "1.0000000", "1.0000001" },
    {NULL, NULL, NULL}
};

static struct status_diff status_cases[] = {
    /* With a reduced working precision in mpd_qpow() the status matches. */
    { "pwsx803", MPD_Inexact|MPD_Rounded|MPD_Subnormal|MPD_Underflow, MPD_Inexact|MPD_Rounded },
    {NULL, 0, 0}
};

static const char *skipit[] = {
    /* NULL reference, decimal16, decimal32, or decimal128 */
    "absx900",
    "addx9990",
    "addx9991",
    "clam090",
    "clam091",
    "clam092",
    "clam093",
    "clam094",
    "clam095",
    "clam096",
    "clam097",
    "clam098",
    "clam099",
    "clam189",
    "clam190",
    "clam191",
    "clam192",
    "clam193",
    "clam194",
    "clam195",
    "clam196",
    "clam197",
    "clam198",
    "clam199",
    "comx990",
    "comx991",
    "cotx9990",
    "cotx9991",
    "ctmx9990",
    "ctmx9991",
    "ddabs900",
    "ddadd9990",
    "ddadd9991",
    "ddcom9990",
    "ddcom9991",
    "ddcot9990",
    "ddcot9991",
    "ddctm9990",
    "ddctm9991",
    "dddiv9998",
    "dddiv9999",
    "dddvi900",
    "dddvi901",
    "ddfma2990",
    "ddfma2991",
    "ddfma39990",
    "ddfma39991",
    "ddlogb900",
    "ddmax900",
    "ddmax901",
    "ddmxg900",
    "ddmxg901",
    "ddmin900",
    "ddmin901",
    "ddmng900",
    "ddmng901",
    "ddmul9990",
    "ddmul9991",
    "ddnextm900",
    "ddnextm900",
    "ddnextp900",
    "ddnextp900",
    "ddnextt900",
    "ddnextt901",
    "ddqua998",
    "ddqua999",
    "ddred900",
    "ddrem1000",
    "ddrem1001",
    "ddrmn1000",
    "ddrmn1001",
    "ddsub9990",
    "ddsub9991",
    "ddintx074",
    "ddintx094",
    "divx9998",
    "divx9999",
    "dvix900",
    "dvix901",
    "dqabs900",
    "dqadd9990",
    "dqadd9991",
    "dqcom990",
    "dqcom991",
    "dqcot9990",
    "dqcot9991",
    "dqctm9990",
    "dqctm9991",
    "dqdiv9998",
    "dqdiv9999",
    "dqdvi900",
    "dqdvi901",
    "dqfma2990",
    "dqfma2991",
    "dqadd39990",
    "dqadd39991",
    "dqlogb900",
    "dqmax900",
    "dqmax901",
    "dqmxg900",
    "dqmxg901",
    "dqmin900",
    "dqmin901",
    "dqmng900",
    "dqmng901",
    "dqmul9990",
    "dqmul9991",
    "dqnextm900",
    "dqnextp900",
    "dqnextt900",
    "dqnextt901",
    "dqqua998",
    "dqqua999",
    "dqred900",
    "dqrem1000",
    "dqrem1001",
    "dqrmn1000",
    "dqrmn1001",
    "dqsub9990",
    "dqsub9991",
    "dqintx074",
    "dqintx094",
    "expx900",
    "fmax2990",
    "fmax2991",
    "fmax39990",
    "fmax39991",
    "lnx900",
    "logx900",
    "logbx900",
    "maxx900",
    "maxx901",
    "mxgx900",
    "mxgx901",
    "mnm900",
    "mnm901",
    "mng900",
    "mng901",
    "minx900",
    "mulx990",
    "mulx991",
    "nextm900",
    "nextp900",
    "nextt900",
    "nextt901",
    "plu900",
    "powx900",
    "powx901",
    "pwsx900",
    "quax1022",
    "quax1023",
    "quax1024",
    "quax1025",
    "quax1026",
    "quax1027",
    "quax1028",
    "quax1029",
    "quax0a2",
    "quax0a3",
    "quax998",
    "quax999",
    "redx900",
    "remx1000",
    "remx1001",
    "rmnx900",
    "rmnx901",
    "sqtx9900",
    "subx9990",
    "subx9991",
    /* operand range violations, invalid context */
    "expx901",
    "expx902",
    "expx903",
    "expx905",
    "lnx901",
    "lnx902",
    "lnx903",
    "lnx905",
    "logx901",
    "logx902",
    "logx903",
    "logx905",
    "powx1183",
    "powx1184",
    "powx4001",
    "powx4002",
    "powx4003",
    "powx4005",
    "powx4008",
    "powx4010",
    "powx4012",
    "powx4014",
    "scbx164",
    "scbx165",
    "scbx166",
#if defined(MPD_CONFIG_32) && MPD_MINALLOC_MAX <= 4
    /* Under the allocation failure tests, the result is numerically correct
       (1 == 1.00000) but without zero padding. This is by design, since in
       case of MPD_Malloc_error mpd_qsqrt() retries the operation with a lower
       context precision and allows all exact results.

       The MPD_MINALLOC_MAX < 64 feature is is officially unsupported but works
       (if the little-endian mpd_ln10_data arrays are adjusted).
    */
    "sqtx9045",
#endif
    /* skipped for decNumber, too */
    "powx4302",
    "powx4303",
    "powx4303",
    "powx4342",
    "powx4343",
    "pwsx805",
    /* disagreement for three arg power */
    "pwmx325",
    "pwmx326",
    NULL
};

static inline int
startswith(const char *token, const char *s)
{
    return token != NULL && strncasecmp(token, s, strlen(s)) == 0;
}

static inline int
eqtoken(const char *token, const char *s)
{
    return token != NULL && strcasecmp(token, s) == 0;
}

static int
check_skip(char *id)
{
    int i;

    for (i = 0; skipit[i] != NULL; i++) {
        if (eqtoken(id, skipit[i])) {
#if defined(RT_VERBOSITY) && RT_VERBOSITY == 2
            fprintf(stderr, "SKIP: %s\n", id);
#endif
            return 1;
        }
    }

    return 0;
}

static char *
nexttoken(char *cp)
{
    static char *start = NULL;
    static char *end = NULL;

    if (cp == NULL) {
        assert(end != NULL);
        cp = end;
    }

    for (; *cp != '\0'; cp++) {
        if (isspace((unsigned char)*cp)) {
            /* empty */
        }
        else if (*cp == '"') {
            start = end = cp+1;
            for (; *end != '\0'; end++) {
                if (*end == '"' && *(end+1) == '"')
                    end += 1;
                else if (*end == '"')
                    break;
            }
            if (*end == '\0')
                return NULL;
            *end++ = '\0';
            return start;
        }
        else if (*cp == '\'') {
            start = end = cp+1;
            for (; *end != '\0'; end++) {
                if (*end == '\'' && *(end+1) == '\'')
                    end += 1;
                else if (*end == '\'')
                    break;
            }
            if (*end == '\0')
                return NULL;
            *end++ = '\0';
            return start;
        }
        else {
            start = end = cp;
            for (; *end != '\0'; end++)
                if (isspace((unsigned char)*end))
                    break;
            if (*end == '\0')
                return NULL;
            *end++ = '\0';
            return start;
        }
    }

    return NULL;
}

/* split a line into tokens */
static int
split(char *token[], char line[])
{
    char *cp;
    size_t len;
    int n = 0;

    cp = nexttoken(line);
    while (n < MAXTOKEN && cp != NULL) {
        len = strlen(cp);
        if ((token[n] = malloc(len+1)) == NULL) {
            mpd_err_fatal("out of memory");
        }
        strcpy(token[n], cp);
        cp = nexttoken(NULL);
        n++;
    }
    token[n] = NULL;

    return n;
}

static void
freetoken(char **token)
{
    while (*token != NULL) {
        free(*token++);
    }
}

/* returns all expected conditions in a status flag */
static uint32_t
scan_conditions(char **token)
{
    char *condition = *token;
    uint32_t status = 0;

    while (condition != NULL) {

        if (startswith(condition, "--"))
            break;
        else if (eqtoken(condition, "Clamped"))
            status |= MPD_Clamped;
        else if (eqtoken(condition, "Conversion_syntax"))
            status |= MPD_Conversion_syntax;
        else if (eqtoken(condition, "Division_by_zero"))
            status |= MPD_Division_by_zero;
        else if (eqtoken(condition, "Division_impossible"))
            status |= MPD_Division_impossible;
        else if (eqtoken(condition, "Division_undefined"))
            status |= MPD_Division_undefined;
        else if (eqtoken(condition, "Fpu_error"))
            status |= MPD_Fpu_error;
        else if (eqtoken(condition, "Inexact"))
            status |= MPD_Inexact;
        else if (eqtoken(condition, "Invalid_context"))
            status |= MPD_Invalid_context;
        else if (eqtoken(condition, "Invalid_operation"))
            status |= MPD_Invalid_operation;
        else if (eqtoken(condition, "Malloc_error"))
            status |= MPD_Malloc_error;
        else if (eqtoken(condition, "Not_implemented"))
            status |= MPD_Not_implemented;
        else if (eqtoken(condition, "Overflow"))
            status |= MPD_Overflow;
        else if (eqtoken(condition, "Rounded"))
            status |= MPD_Rounded;
        else if (eqtoken(condition, "Subnormal"))
            status |= MPD_Subnormal;
        else if (eqtoken(condition, "Underflow"))
            status |= MPD_Underflow;
        else
            mpd_err_fatal("unknown status: %s", condition);

        condition = *(++token);
    }

    return status;
}

static void
compare_expected(const char *calc, const char *expected, uint32_t expected_status,
                 char *id, mpd_context_t *ctx)
{
    char ctxstatus[MPD_MAX_FLAG_STRING];
    char expstatus[MPD_MAX_FLAG_STRING];


#ifndef RT_VERBOSITY
    /* Do not print known pseudo-failures. */
    int i;

    /* known ULP diffs */
    if (ctx->allcr == 0) {
        for (i = 0; ulp_cases[i].id != NULL; i++) {
            if (eqtoken(id, ulp_cases[i].id) &&
                strcmp(expected, ulp_cases[i].expected) == 0 &&
                strcmp(calc, ulp_cases[i].calc) == 0) {
                return;
            }
        }
    }

    /* known status diffs */
    for (i = 0; status_cases[i].id != NULL; i++) {
        if (eqtoken(id, status_cases[i].id) &&
            expected_status == status_cases[i].expected &&
            ctx->status == status_cases[i].calc) {
            return;
        }
    }
#endif

    if (strcmp(calc, expected) != 0) {
        if (file_failure == 0) {
            fputs("\n\n", stderr);
        }
        fprintf(stderr, "FAIL: %s  calc: %s  expected: %s\n",
                        id, calc, expected);
        global_failure = file_failure = 1;
    }
    if (ctx->status != expected_status) {
        if (file_failure == 0) {
            fputs("\n\n", stderr);
        }
        mpd_snprint_flags(ctxstatus, MPD_MAX_FLAG_STRING, ctx->status);
        mpd_snprint_flags(expstatus, MPD_MAX_FLAG_STRING, expected_status);
        fprintf(stderr, "FAIL: %s: status:  calc: %s  expected: %s\n",
                id, ctxstatus, expstatus);
        global_failure = file_failure = 1;
    }
}

static int
equalmem(const mpd_t *a, const mpd_t *b)
{
    mpd_ssize_t i;

    if (a->flags != b->flags) return 0;
    if (a->exp != b->exp) return 0;
    if (a->len != b->len) return 0;
    if (a->digits != b->digits) return 0;
    for (i = 0; i < a->len; i++)
        if (a->data[i] != b->data[i])
            return 0;
    return 1;
}

static void
check_equalmem(const mpd_t *a, const mpd_t *b, const char *id)
{
    if (!equalmem(a, b)) {
        fprintf(stderr, "FAIL: const arg changed: %s\n", id);
    }
}

static unsigned long
get_testno(char *token)
{
    char *number;

    number = strpbrk(token, "0123456789");
    ASSERT(number != NULL);
    return strtoul(number, NULL, 10);
}

/* scan a single operand and the expected result */
static int
scan_1op_result(mpd_t *op1, char **result, char *token[], mpd_context_t *ctx)
{
    /* operand 1 */
    if (token[2] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }
    mpd_set_string(op1, token[2], ctx);

    /* discard "->" */
    if (token[3] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }

    /* expected result */
    if (token[4] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }
    *result = token[4];

    return 5;
}

/* scan a single operand and two results */
static int
scan_1op_2results(mpd_t *op1, char **result1, char **result2, char *token[], mpd_context_t *ctx)
{
    /* operand 1 */
    if (token[2] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }
    mpd_set_string(op1, token[2], ctx);

    /* discard "->" */
    if (token[3] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }

    /* expected result1 */
    if (token[4] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }
    *result1 = token[4];

    /* expected result2 */
    if (token[5] == NULL) {
        mpd_err_fatal("parse error at id %s", token[0]);
    }
    *result2 = token[5];

    return 6;
}

/* scan decimal operand, string operand and the expected result */
static int
scan_1op_str_result(mpd_t *op1, char **op2, char **result, char *token[], mpd_context_t *ctx)
{
    /* operand 1 */
    if (token[2] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op1, token[2], ctx);

    /* operand 2 */
    if (token[3] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    *op2 = token[3];

    /* discard "->" */
    if (token[4] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }

    /* expected result */
    if (token[5] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    *result = token[5];

    return 6;
}

/* scan two operands and the expected result */
static int
scan_2ops_result(mpd_t *op1, mpd_t *op2, char **result, char *token[], mpd_context_t *ctx)
{
    /* operand 1 */
    if (token[2] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op1, token[2], ctx);

    /* operand 2 */
    if (token[3] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op2, token[3], ctx);

    /* discard "->" */
    if (token[4] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }

    /* expected result */
    if (token[5] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    *result = token[5];

    return 6;
}

/* scan two operands and two results */
static int
scan_2ops_2results(mpd_t *op1, mpd_t *op2, char **result1, char **result2, char *token[], mpd_context_t *ctx)
{
    /* operand 1 */
    if (token[2] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op1, token[2], ctx);

    /* operand 2 */
    if (token[3] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op2, token[3], ctx);

    /* discard "->" */
    if (token[4] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }

    /* expected result1 */
    if (token[5] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    *result1 = token[5];

    /* expected result2 */
    if (token[6] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    *result2 = token[6];

    return 7;
}

/* scan three operands and the expected result */
static int
scan_3ops_result(mpd_t *op1, mpd_t *op2, mpd_t *op3, char **result, char *token[], mpd_context_t *ctx)
{
    /* operand 1 */
    if (token[2] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op1, token[2], ctx);

    /* operand 2 */
    if (token[3] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op2, token[3], ctx);

    /* operand 2 */
    if (token[4] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    mpd_set_string(op3, token[4], ctx);

    /* discard "->" */
    if (token[5] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }

    /* expected result */
    if (token[6] == NULL) {
        mpd_err_fatal("%s", token[0]);
    }
    *result = token[6];

    return 7;
}

static mpd_t *op, *op1, *op2, *op3;
static mpd_t *tmp, *tmp1, *tmp2, *tmp3;
static mpd_t *result, *result1, *result2;

/* Test triple conversion */
static void
_TripleTest(const mpd_t *a, mpd_context_t *ctx, const char *testno)
{
    mpd_uint128_triple_t triple;
    uint32_t status = 0;
    int ret = 0;

#ifdef MPD_CONFIG_32
    /*
     * 32-bit: as_triple() expects well-formed decimals. Skip test cases
     * that use the extended exponent, which is safe in the tests but not
     * in production.
     */
     if (a->exp < MPD_MIN_ETINY || a->exp > MPD_MAX_EMAX) {
         return;
     }
#endif

    triple = mpd_as_uint128_triple(a);
    switch (triple.tag) {
    case MPD_TRIPLE_QNAN: case MPD_TRIPLE_SNAN:
        ASSERT(triple.exp == 0)
        break;
    case MPD_TRIPLE_INF:
        ASSERT(triple.hi == 0 && triple.lo == 0 && triple.exp == 0)
        break;
    case MPD_TRIPLE_NORMAL:
        break;
    case MPD_TRIPLE_ERROR:
        ASSERT(triple.sign == 0 && triple.hi == 0 && triple.lo == 0 && triple.exp == 0)
        break;
    }

    /* Allocation failures in from_triple() */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(result);

        mpd_set_alloc_fail(ctx);
        status = 0;
        ret = mpd_from_uint128_triple(result, &triple, &status);
        mpd_set_alloc(ctx);

        if (!(status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(ret == -1)
        ASSERT(mpd_isnan(result))
    }

    if (triple.tag != MPD_TRIPLE_ERROR) {
        ASSERT(ret == 0)
        ASSERT(status == 0)
        check_equalmem(result, a, testno);
    }
    else {
        ASSERT(ret == -1)
        ASSERT(status == MPD_Conversion_syntax)
        ASSERT(mpd_isnan(result))
    }
}

/* Test both versions of mpd_to_sci. Do not use this if alloc_fail is set,
   since MPD_Malloc_error will only be triggered for one of the functions. */
static char *
_mpd_to_sci(const mpd_t *dec, int fmt)
{
    char *r, *s;
    mpd_ssize_t size;

    r = mpd_to_sci(dec, fmt);
    size = mpd_to_sci_size(&s, dec, fmt);

    if (r == NULL) {
        ASSERT(size == -1)
        ASSERT(s == NULL)
    }
    else {
        ASSERT(strcmp(r, s) == 0)
        ASSERT(size == (mpd_ssize_t)strlen(s))
    }

    mpd_free(s);
    return r;
}

/*
 * Test a function returning pointer to char, accepting:
 *     op1, context
 *
 * This function is used for "toSci", "toEng" and "apply"
 * and does not use a maxctx for the conversion of the operand.
 */
static void
_cp_MpdCtx(char **token, char *(*func)(const mpd_t *, int), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected, *expected_fail = NULL;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);

    mpd_context_t *workctx = ctx;
    workctx->status = 0;
    n = scan_1op_result(op, &expected, token, workctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);

    /* Allocation failures for mpd_set_string */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        workctx->status = 0;

        mpd_set_alloc_fail(workctx);
        (void)scan_1op_result(tmp, &expected_fail, token, workctx);
        mpd_set_alloc(workctx);

        if (!(workctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
    }
    ASSERT(strcmp(expected, expected_fail) == 0)
    ASSERT(mpd_cmp_total(tmp, op) == 0)


    /* make a copy of the operand */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, workctx);

    calc = func(tmp, 1);

    /* compare the calculated result to the expected result */
    compare_expected(calc, expected, expstatus, token[0], workctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, workctx);

        mpd_set_alloc_fail(workctx);
        calc = func(tmp, 1);
        mpd_set_alloc(workctx);

        if (calc != NULL) {
            break;
        }
    }
    compare_expected(calc, expected, expstatus, token[0], workctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);
}

/* Test mpd_to_sci_size() and mpd_to_eng_size(). */
static void
sci_eng_size(char **token, mpd_ssize_t (*func)(char **, const mpd_t *, int), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected, *expected_fail = NULL;
    uint32_t expstatus;
    mpd_ssize_t size;
    int n;

    mpd_readcontext(&maxctx);

    mpd_context_t *workctx = ctx;
    workctx->status = 0;
    n = scan_1op_result(op, &expected, token, workctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);

    /* Allocation failures for mpd_set_string */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        workctx->status = 0;

        mpd_set_alloc_fail(workctx);
        (void)scan_1op_result(tmp, &expected_fail, token, workctx);
        mpd_set_alloc(workctx);

        if (!(workctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
    }
    ASSERT(strcmp(expected, expected_fail) == 0)
    ASSERT(mpd_cmp_total(tmp, op) == 0)


    /* make a copy of the operand */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, workctx);

    size = func(&calc, tmp, 1);
    ASSERT(size == (mpd_ssize_t)strlen(calc))

    /* compare the calculated result to the expected result */
    compare_expected(calc, expected, expstatus, token[0], workctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, workctx);

        mpd_set_alloc_fail(workctx);
        size = func(&calc, tmp, 1);
        mpd_set_alloc(workctx);

        if (calc != NULL) {
            ASSERT(size == (mpd_ssize_t)strlen(calc))
            break;
        }
    }
    compare_expected(calc, expected, expstatus, token[0], workctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);
}

/* Quick and dirty: parse hex escape sequences */
static char *
parse_escapes(const char *s)
{
    char hex[5];
    char *res, *cp;
    unsigned int u;
    int n;

    cp = res = malloc(strlen(s)+1);
    if (res == NULL) {
        return NULL;
    }

    hex[0] = '0';
    hex[1] = '\0';
    while (*s) {
        if (*s == '\\' && *(s+1) == 'x') {
            for (n = 1; n < 4; n++) {
                if (!s[n]) {
                    free(res);
                    return NULL;
                }
                hex[n] = s[n];
            }
            hex[n] = '\0';
            sscanf(hex, "%x%n", &u, &n);
            *cp++ = (char)u;
            s += n;
        }
        else {
            *cp++ = *s++;
        }
    }

    *cp = '\0';
    return res;
}

/*
 * Test a function returning pointer to char, accepting:
 *     op1, fmt, context
 *
 * This function is used for "mpd_format".
 */
static void
_cp_MpdFmtCtx(char **token, char *(*func)(const mpd_t *, const char *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *fmt;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    /* conversion should be done as if there were no limits */
    n = scan_1op_str_result(op1, &fmt, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);

    fmt = parse_escapes(fmt);
    expected = parse_escapes(expected);

    expstatus = scan_conditions(token+n);

    mpd_init_rand(tmp);
    mpd_copy(tmp, op1, ctx);
    ctx->status = 0;

    calc = func(tmp, fmt, ctx);

    /* compare the calculated result to the expected result */
    if (calc == NULL) {
        compare_expected("NULL", expected, expstatus, token[0], ctx);
    }
    else {
        compare_expected(calc, expected, expstatus, token[0], ctx);
        mpd_free(calc);
    }
    check_equalmem(tmp, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op1, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        calc = func(tmp, fmt, ctx);
        mpd_set_alloc(ctx);
        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(calc == NULL)
    }
    if (calc == NULL) {
        compare_expected("NULL", expected, expstatus, token[0], ctx);
    }
    else {
        compare_expected(calc, expected, expstatus, token[0], ctx);
        mpd_free(calc);
    }
    check_equalmem(tmp, op1, token[0]);

    free(fmt);
    free(expected);
}

/*
 * Test a function returning pointer to const char, accepting:
 *     op1, context
 */
static void
_ccp_MpdCtx(char **token, const char *(*func)(const mpd_t *, const mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    const char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    /* conversion should be done as if there were no limits */
    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    calc = func(tmp, ctx);

    compare_expected(calc, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        calc = func(tmp, ctx);
        mpd_set_alloc(ctx);
        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(calc == NULL)
    }
    compare_expected(calc, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);
}

/* Test a unary function */
static void
_Res_Op_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n, incr;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* result and tmp are distinct decimals */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result, tmp, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))

        if (alloc_fail > 100) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);


    /* result equals operand */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp, tmp, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))

        if (alloc_fail > 100) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
}

/* Test a unary function, quantize the operand before applying the actual function */
static void
_Res_Op_CtxWithQuantize(char *token[], void (*func)(mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n, incr;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op, op1, &expected, token, &maxctx);
    mpd_quantize(op, op, op1, &maxctx);
    _TripleTest(op, ctx, token[0]);
    _TripleTest(op1, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* result and tmp are distinct decimals */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result, tmp, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);


    /* result equals operand */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp, tmp, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
}

static void
resolve_status_hack(uint32_t *expstatus, const uint32_t status)
{
    /* hack #1 to resolve disagreement with results generated by decimal.py */
    if ((*expstatus & MPD_Invalid_operation) &&
        (status & MPD_Division_impossible)) {
        *expstatus = MPD_Division_impossible;
    }

    /* hack #2 to resolve disagreement with results generated by decimal.py */
    if ((*expstatus & MPD_Invalid_operation) &&
        (status & MPD_Division_undefined)) {
        *expstatus = MPD_Division_undefined;
    }
}

/* Test a binary function */
static void
_Res_Binop_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *),
               mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n, incr;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);

    /* three distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp1, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp2, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
}

/* Test a binary function where op1 == op2. */
static void
_Res_EqualBinop_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *),
                    mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* equal operands, distinct result */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    func(result, tmp, tmp, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);


    /* all parameters equal */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    func(tmp, tmp, tmp, ctx);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp, tmp, tmp, ctx);
        mpd_set_alloc(ctx);
        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
}

/* Test a binary function with a binary result */
static void
_Binres_Binop_Ctx(char *token[], void (*func)(mpd_t *, mpd_t*, const mpd_t *, const mpd_t *, mpd_context_t *),
                  mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected1, *expected2;
    uint32_t expstatus;
    int n, incr;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_2results(op1, op2, &expected1, &expected2, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* four distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result1);
    mpd_init_rand(result2);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result1, result2, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    resolve_status_hack(&expstatus, ctx->status);

    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result1);
        mpd_minalloc(result2);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result1, result2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result1))
        ASSERT(mpd_isnan(result2))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result1 == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result2);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp1, result2, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail <= INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result2);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, result2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
        ASSERT(mpd_isnan(result2))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp2, op2, token[0]);


    /* result2 == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result1);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result1, tmp1, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result1);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result1, tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result1))
        ASSERT(mpd_isnan(tmp1))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp2, op2, token[0]);


    /* result1 == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result2);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp2, result2, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result2);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, result2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
        ASSERT(mpd_isnan(result2))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp1, op1, token[0]);


    /* result2 == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result1);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result1, tmp2, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result1);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result1, tmp2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result1))
        ASSERT(mpd_isnan(tmp2))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp1, op1, token[0]);


    /* result1 == tmp1, result2 == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp1, tmp2, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
        ASSERT(mpd_isnan(tmp2))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);


    /* result1 == tmp2, result2 == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp2, tmp1, tmp1, tmp2, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
        ASSERT(mpd_isnan(tmp1))

        if (alloc_fail > 50) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);
}

/* Test a binary function with a binary result; equal operands */
static void
_Binres_EqualBinop_Ctx(char *token[], void (*func)(mpd_t *, mpd_t*, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected1, *expected2;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_2results(op, &expected1, &expected2, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* distinct results */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result1);
    mpd_init_rand(result2);
    ctx->status = 0;

    func(result1, result2, tmp, tmp, ctx);

    resolve_status_hack(&expstatus, ctx->status);

    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result1);
        mpd_minalloc(result2);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result1, result2, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result1))
        ASSERT(mpd_isnan(result2))
    }
    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    check_equalmem(tmp, op, token[0]);


    /* result1 == tmp */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result2);
    ctx->status = 0;

    func(tmp, result2, tmp, tmp, ctx);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result2);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp, result2, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
        ASSERT(mpd_isnan(result2))
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(result2, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);


    /* result2 == tmp */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result1);
    ctx->status = 0;

    func(result1, tmp, tmp, tmp, ctx);

    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result1);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result1, tmp, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result1))
        ASSERT(mpd_isnan(tmp))
    }
    calc = _mpd_to_sci(result1, 1);
    compare_expected(calc, expected1, expstatus, token[0], ctx);
    mpd_free(calc);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected2, expstatus, token[0], ctx);
    mpd_free(calc);
}

/* Test a ternary function */
static void
_Res_Ternop_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n, incr;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_3ops_result(op1, op2, op3, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);
    _TripleTest(op3, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* four distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_init_rand(tmp3);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_copy(tmp3, op3, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(result, tmp1, tmp2, tmp3, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);
    check_equalmem(tmp3, op3, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_init_rand(tmp3);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_copy(tmp3, op3, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp1, tmp2, tmp3, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))

        if (alloc_fail > 100) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);
    check_equalmem(tmp3, op3, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_init_rand(tmp3);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_copy(tmp3, op3, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp1, tmp1, tmp2, tmp3, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);
    check_equalmem(tmp3, op3, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_init_rand(tmp3);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_copy(tmp3, op3, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp1, tmp2, tmp3, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))

        if (alloc_fail > 100) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);
    check_equalmem(tmp3, op3, token[0]);


    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_init_rand(tmp3);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_copy(tmp3, op3, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp2, tmp1, tmp2, tmp3, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp3, op3, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_init_rand(tmp3);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_copy(tmp3, op3, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, tmp1, tmp2, tmp3, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))

        if (alloc_fail > 100) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp3, op3, token[0]);


    /* result == tmp3 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_init_rand(tmp3);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_copy(tmp3, op3, ctx);
    ctx->status = 0;

    mpd_set_alloc_count(ctx);
    func(tmp3, tmp1, tmp2, tmp3, ctx);
    mpd_set_alloc(ctx);

    calc = _mpd_to_sci(tmp3, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    incr = 1;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_init_rand(tmp3);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_copy(tmp3, op3, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp3, tmp1, tmp2, tmp3, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp3))

        if (alloc_fail > 100) {
            incr = (int)(alloc_count*0.02) + 1;
        }
    }
    calc = _mpd_to_sci(tmp3, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);
}

/* Test a ternary function, first and second operand equal */
static void
_Res_EqEqOp_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* distinct result */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    func(result, tmp1, tmp1, tmp2, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    func(tmp1, tmp1, tmp1, tmp2, ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    func(tmp2, tmp1, tmp1, tmp2, ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
}

/* Test a ternary function, first and third operand equal */
static void
_Res_EqOpEq_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* distinct result */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    func(result, tmp1, tmp2, tmp1, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp1, tmp2, tmp1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    func(tmp1, tmp1, tmp2, tmp1, ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp1, tmp2, tmp1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    func(tmp2, tmp1, tmp2, tmp1, ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, tmp1, tmp2, tmp1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
}

/* Test a ternary function, second and third operand equal */
static void
_Res_OpEqEq_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* distinct result */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    func(result, tmp1, tmp2, tmp2, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp1, tmp2, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    func(tmp2, tmp1, tmp2, tmp2, ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp2, tmp1, tmp2, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    func(tmp1, tmp1, tmp2, tmp2, ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp1, tmp2, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp2, op2, token[0]);
}

/* Test a ternary function, first, second and third operand equal */
static void
_Res_EqEqEq_Ctx(char *token[], void (*func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* distinct result */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    func(result, tmp, tmp, tmp, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp, op, token[0]);


    /* result == tmp */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    func(tmp, tmp, tmp, tmp, ctx);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp, tmp, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
}

/*
 * Test a binary function that returns an additional integer result.
 * Used for the comparison functions.
 */
static void
_Int_Res_Binop_Ctx(char *token[], int (*func)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    int int_result;
    char buf[11];
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* three distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    int_result = func(result, tmp1, tmp2, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(result, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    int_result = func(tmp1, tmp1, tmp2, ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp1, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp2, op2, token[0]);



    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    int_result = func(tmp2, tmp1, tmp2, ctx);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp2, tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
}

/*
 * Test a binary function that returns an additional integer result.
 * Equal operands.
 * Used for the comparison functions.
 */
static void
_Int_Res_EqualBinop_Ctx(char *token[], int (*func)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    int int_result;
    char buf[11];
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* equal operands */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    int_result = func(result, tmp, tmp, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(result, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp, op, token[0]);


    /* all parameters equal */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    int_result = func(tmp, tmp, tmp, ctx);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp, tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
}

/*
 * Test a binary function that returns an additional integer result.
 * Function does not take a context argument.
 * Used for the comparison functions.
 */
static void
_Int_Res_Binop(char *token[], int (*func)(mpd_t *, const mpd_t *, const mpd_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    int int_result;
    char buf[11];
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* three distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    int_result = func(result, tmp1, tmp2);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(result, tmp1, tmp2);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    int_result = func(tmp1, tmp1, tmp2);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp1, tmp1, tmp2);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp2, op2, token[0]);


    /* result == tmp2 */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    int_result = func(tmp2, tmp1, tmp2);

    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp2, tmp1, tmp2);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp2))
    }
    calc = _mpd_to_sci(tmp2, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
}

/*
 * Test a binary function that returns an additional integer result.
 * Function does not take a context argument.
 * Equal operands.
 * Used for the comparison functions.
 */
static void
_Int_Res_EqualBinop(char *token[], int (*func)(mpd_t *, const mpd_t *, const mpd_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    int int_result;
    char buf[11];
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* equal operands */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    int_result = func(result, tmp, tmp);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(result, tmp, tmp);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp, op, token[0]);


    /* all parameters equal */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    int_result = func(tmp, tmp, tmp);

    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp, tmp, tmp);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp))
    }
    calc = _mpd_to_sci(tmp, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    snprintf(buf, 11, "%d", int_result);
    if (int_result != INT_MAX) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
}

/*
 * Test a binary function that returns only an integer result.
 * Used for the cmp functions.
 */
enum {SKIP_NONE, SKIP_NAN, SKIP_NONINT};
static void
_Int_Binop_Ctx(int skip, char *token[], int (*func)(const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    int int_result;
    char buf[11];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* two distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    int_result = func(tmp1, tmp2, ctx);

    snprintf(buf, 11, "%d", int_result);
    if (!(skip && int_result == INT_MAX)) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp1, tmp2, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(int_result== INT_MAX)
    }
    snprintf(buf, 11, "%d", int_result);
    if (!(skip && int_result == INT_MAX)) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);
}

/*
 * Test a binary function that returns only an integer result.
 * Equal operands.
 * Used for the cmp functions.
 */
static void
_Int_EqualBinop_Ctx(int skip, char *token[], int (*func)(const mpd_t *, const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    int int_result;
    char buf[11];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* equal operands */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    int_result = func(tmp, tmp, ctx);

    snprintf(buf, 11, "%d", int_result);
    if (!(skip && int_result == INT_MAX)) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp, tmp, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(int_result== INT_MAX)
    }
    snprintf(buf, 11, "%d", int_result);
    if (!(skip && int_result == INT_MAX)) { /* NaN cases are skipped for the int_retval */
        compare_expected(buf, expected, expstatus, token[0], ctx);
    }
    check_equalmem(tmp, op, token[0]);
}

/*
 * Test a binary function that returns an int.
 * The function does not take a context argument.
 */
static void
_Int_Binop(char *token[], int (*func)(const mpd_t *, const mpd_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    int int_result;
    char buf[11];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* two distinct decimals */
    mpd_init_rand(tmp1);
    mpd_init_rand(tmp2);
    mpd_copy(tmp1, op1, ctx);
    mpd_copy(tmp2, op2, ctx);
    ctx->status = 0;

    int_result = func(tmp1, tmp2);

    snprintf(buf, 11, "%d", int_result);
    compare_expected(buf, expected, expstatus, token[0], ctx);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_copy(tmp1, op1, ctx);
        mpd_copy(tmp2, op2, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp1, tmp2);
        mpd_set_alloc(ctx);

        if (int_result != INT_MAX) {
            break;
        }
    }
    snprintf(buf, 11, "%d", int_result);
    compare_expected(buf, expected, expstatus, token[0], ctx);
    check_equalmem(tmp1, op1, token[0]);
    check_equalmem(tmp2, op2, token[0]);
}

/*
 * Test a binary function that returns an int.
 * Equal operands.
 * The function does not take a context argument.
 */
static void
_Int_EqualBinop(char *token[], int (*func)(const mpd_t *, const mpd_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    int int_result;
    char buf[11];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* equal operands */
    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    int_result = func(tmp, tmp);

    snprintf(buf, 11, "%d", int_result);
    compare_expected(buf, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp);
        mpd_copy(tmp, op, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        int_result = func(tmp, tmp);
        mpd_set_alloc(ctx);

        if (int_result != INT_MAX) {
            break;
        }
    }
    snprintf(buf, 11, "%d", int_result);
    compare_expected(buf, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);
}

static mpd_ssize_t
scan_ssize(char *token[])
{
    errno = 0;
    if (token[1] == NULL) {
        errno = 1;
        return MPD_SSIZE_MAX;
    }
    return strtossize(token[1], NULL, 10);
}

static void
_mpd_shiftl(mpd_t *res, const mpd_t *a, mpd_ssize_t n, mpd_context_t *ctx)
{
    ASSERT(!mpd_isspecial(a));
    mpd_shiftl(res, a, n, ctx);
}

static void
_mpd_shiftr(mpd_t *res, const mpd_t *a, mpd_ssize_t n, mpd_context_t *ctx)
{
    ASSERT(!mpd_isspecial(a));
    (void)mpd_shiftr(res, a, n, ctx);
}

/*
 * Test a function with an mpd_t and an mpd_ssize_t operand.
 * Used for the shift functions.
 */
static void
_Res_Op_Lsize_Ctx(int skip, char *token[], void (*func)(mpd_t *, const mpd_t *, mpd_ssize_t, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    mpd_ssize_t ssize;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_2ops_result(op1, op2, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);
    _TripleTest(op2, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* only integers are allowed for ssize */
    if (skip && (mpd_isspecial(op2) || op2->exp != 0)) {
        /* fprintf(stderr, "SKIP: %s\n", token[0]); */
        return;
    }
    ssize = mpd_get_ssize(op2, &maxctx);
    if (maxctx.status&MPD_Invalid_operation) {
        return;
    }

    /* two distinct decimals */
    mpd_init_rand(tmp1);
    mpd_copy(tmp1, op1, ctx);
    mpd_init_rand(result);
    ctx->status = 0;

    func(result, tmp1, ssize, ctx);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_copy(tmp1, op1, ctx);
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(result, tmp1, ssize, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    check_equalmem(tmp1, op1, token[0]);


    /* result == tmp1 */
    mpd_init_rand(tmp1);
    mpd_copy(tmp1, op1, ctx);
    ctx->status = 0;

    func(tmp1, tmp1, ssize, ctx);

    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_init_rand(tmp1);
        mpd_copy(tmp1, op1, ctx);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        func(tmp1, tmp1, ssize, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(tmp1))
    }
    calc = _mpd_to_sci(tmp1, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
}

/* test mpd_qln10() */
static void
_test_mpd_qln10(int skip, char *token[], mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    char *calc;
    char *expected;
    uint32_t expstatus;
    mpd_ssize_t ssize;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op1, &expected, token, &maxctx);
    _TripleTest(op1, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);


    /* only integers are allowed for ssize */
    if (skip && (mpd_isspecial(op1) || op1->exp != 0)) {
        /* fprintf(stderr, "SKIP: %s\n", token[0]); */
        return;
    }
    ssize = mpd_get_ssize(op1, &maxctx);
    if (maxctx.status&MPD_Invalid_operation) {
        return;
    }

    mpd_init_rand(result);
    ctx->status = 0;

    mpd_qln10(result, ssize, &ctx->status);

    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);

    /* Allocation failures */
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_qln10(result, ssize, &ctx->status);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
}

static void
_Baseconv(char *token[], mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    uint32_t base;
    uint16_t *data16;
    uint32_t *data32;
    size_t len16, len32;
    size_t expected_len16, expected_len32;
    char *expected;
    uint32_t expstatus;
    char *calc;
    int n = 0;
    int i, iter = 0;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    n = scan_1op_result(op1, &expected, token, &maxctx);
    ASSERT(mpd_isinteger(op1))
    _TripleTest(op1, ctx, token[0]);

    /* scan expected conditions */
    expstatus = scan_conditions(token+n);

    /*
     * base := (1<<15)
     * data16 := NULL
     * Allocation and deallocation on error by mpd_export_u16().
     */
    base = (1<<15);
    data16 = NULL;
    expected_len16 = mpd_export_u16(&data16, 0, base, op1, ctx);
    if (expected_len16 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data16);

    /*
     * base := (1<<15)
     * data16 := NULL
     * Test allocation failures.
     */
    base = (1<<15);
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        data16 = NULL;
        expected_len16 = mpd_export_u16(&data16, 0, base, op1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        /* If data16 == NULL, it is deallocated on failure. */
        ASSERT(expected_len16 == SIZE_MAX)
    }
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    mpd_free(data16);

    /*
     * base := (1<<15)
     * len(data16) := 1
     * Simulate result from sizeinbase() that is too small.
     */
    base = (1<<15);
    data16 = mpd_alloc(1, sizeof *data16);
    expected_len16 = mpd_export_u16(&data16, 1, base, op1, ctx);
    if (expected_len16 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data16);

    /*
     * base := (1<<15)
     * len(data16) == 1
     * Test allocation failures.
     */
    base = (1<<15);
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        ctx->status = 0;

        data16 = mpd_alloc(1, sizeof *data16);
        mpd_set_alloc_fail(ctx);
        expected_len16 = mpd_export_u16(&data16, 1, base, op1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        /* Caller must free the memory that was passed in. */
        mpd_free(data16);
        ASSERT(expected_len16 == SIZE_MAX)
    }
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    mpd_free(data16);


    /*
     * base := (1<<16)
     * len(data16) := mpd_sizeinbase()
     */
    base = (1U<<16);
    len16 = mpd_sizeinbase(op1, base);
    data16 = mpd_alloc((mpd_size_t)len16, sizeof *data16);
    len16 = mpd_export_u16(&data16, len16, base, op1, ctx);
    if (len16 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u16(result, data16, len16, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data16);


    /*
     * base := 9999
     * len(data16) := mpd_sizeinbase()
     */
    base = 9999;
    len16 = mpd_sizeinbase(op1, base);
    data16 = mpd_alloc((mpd_size_t)len16, sizeof *data16);
    expected_len16 = mpd_export_u16(&data16, len16, base, op1, ctx);
    if (expected_len16 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data16);


    /*
     * base := [2..16]
     * len(data16) := mpd_sizeinbase()
     */
    iter = 16;
    for (i = 2; i <= iter; i++) {

        base = (uint32_t)i;
        len16 = mpd_sizeinbase(op1, base);
        data16 = mpd_alloc((mpd_size_t)len16, sizeof *data16);
        len16 = mpd_export_u16(&data16, len16, base, op1, ctx);
        if (len16 == SIZE_MAX) {
            mpd_err_fatal("export_to_base failed");
        }

        mpd_import_u16(result, data16, len16, MPD_POS, base, ctx);
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);

        mpd_free(calc);
        mpd_free(data16);
    }

    /*
     * base := random(UINT_16_MAX)
     * len(data16) := mpd_sizeinbase()
     */
    iter = 5;
    for (i = 0; i < iter; i++) {

        base = random() % UINT16_MAX;
        if (base < 2) base = 2;

        len16 = mpd_sizeinbase(op1, base);
        data16 = mpd_alloc((mpd_size_t)len16, sizeof *data16);
        len16 = mpd_export_u16(&data16, len16, base, op1, ctx);
        if (len16 == SIZE_MAX) {
            mpd_err_fatal("export_to_base failed");
        }

        mpd_import_u16(result, data16, len16, MPD_POS, base, ctx);
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);

        mpd_free(calc);
        mpd_free(data16);

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ctx->status = 0;

            data16 = mpd_alloc(1, sizeof *data16);
            mpd_set_alloc_fail(ctx);
            expected_len16 = mpd_export_u16(&data16, 1, base, op1, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            /* Caller must free the memory that was passed in. */
            mpd_free(data16);
            ASSERT(expected_len16 == SIZE_MAX)
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            mpd_minalloc(result);
            ctx->status = 0;

            mpd_set_alloc_fail(ctx);
            mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            ASSERT(mpd_isnan(result))
        }
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);
        mpd_free(calc);
        mpd_free(data16);

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ctx->status = 0;

            data16 = mpd_alloc(1, sizeof *data16);
            mpd_set_alloc_fail(ctx);
            expected_len16 = mpd_export_u16(&data16, 1, base, op1, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            /* Caller must free the memory that was passed in. */
            mpd_free(data16);
            ASSERT(expected_len16 == SIZE_MAX)
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            mpd_minalloc(result);
            ctx->status = 0;

            mpd_set_alloc_fail(ctx);
            mpd_import_u16(result, data16, expected_len16, MPD_POS, base, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            ASSERT(mpd_isnan(result))
        }
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);
        mpd_free(calc);
        mpd_free(data16);
    }

    /* ================================================================ */
    /*                         uint32_t bases                           */
    /* ================================================================ */

    /*
     * base := (1<<30)
     * data32 := NULL
     */
    base = (1<<30);
    data32 = NULL;
    expected_len32 = mpd_export_u32(&data32, 0, base, op1, ctx);
    if (expected_len32 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data32);

    /*
     * base := (1<<30)
     * data32 := NULL
     * Test allocation failures. */
    base = (1<<30);
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        data32 = NULL;
        expected_len32 = mpd_export_u32(&data32, 0, base, op1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(expected_len32 == SIZE_MAX)
    }
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    mpd_free(data32);


    /*
     * base := (1<<30)
     * len(data32) := 1
     */
    base = (1<<30);
    data32 = mpd_alloc(1, sizeof *data32);
    expected_len32 = mpd_export_u32(&data32, 1, base, op1, ctx);
    if (expected_len32 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data32);

    /*
     * base := (1<<30)
     * len(data32) := 1
     * Test allocation failures.
     */
    base = (1<<30);
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        ctx->status = 0;

        data32 = mpd_alloc(1, sizeof *data32);
        mpd_set_alloc_fail(ctx);
        expected_len32 = mpd_export_u32(&data32, 1, base, op1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(expected_len32 == SIZE_MAX)
        mpd_free(data32);
    }
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    mpd_free(data32);


    /*
     * base := 10**9
     * len(data32) := mpd_sizeinbase()
     */
    base = 1000000000;
    len32 = mpd_sizeinbase(op1, base);
    data32 = mpd_alloc((mpd_size_t)len32, sizeof *data32);
    expected_len32 = mpd_export_u32(&data32, len32, base, op1, ctx);
    if (len32 == SIZE_MAX) {
        mpd_err_fatal("export_to_base failed");
    }

    mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);

    mpd_free(calc);
    mpd_free(data32);

    /*
     * base := 10**9
     * len(data32) := mpd_sizeinbase()
     * Test allocation failures.
     */
    base = 1000000000;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        data32 = NULL;
        expected_len32 = mpd_export_u32(&data32, 0, base, op1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(expected_len32 == SIZE_MAX)
    }
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    mpd_free(data32);

    /*
     * base := 10**9
     * len(data32) := 1
     * Test allocation failures.
     */
    base = 1000000000;
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        ctx->status = 0;

        data32 = mpd_alloc(1, sizeof *data32);
        mpd_set_alloc_fail(ctx);
        expected_len32 = mpd_export_u32(&data32, 1, base, op1, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(expected_len32 == SIZE_MAX)
        mpd_free(data32);
    }
    for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
        mpd_minalloc(result);
        ctx->status = 0;

        mpd_set_alloc_fail(ctx);
        mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
        mpd_set_alloc(ctx);

        if (!(ctx->status&MPD_Malloc_error)) {
            break;
        }
        ASSERT(mpd_isnan(result))
    }
    calc = _mpd_to_sci(result, 1);
    compare_expected(calc, expected, expstatus, token[0], ctx);
    mpd_free(calc);
    mpd_free(data32);

    for (i = 2; i <= 16; i++) {

        base = (uint32_t)i;
        len32 = mpd_sizeinbase(op1, base);
        data32 = mpd_alloc((mpd_size_t)len32, sizeof *data32);
        expected_len32 = mpd_export_u32(&data32, len32, base, op1, ctx);
        if (len32 == SIZE_MAX) {
            mpd_err_fatal("export_to_base failed");
        }

        mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);

        mpd_free(calc);
        mpd_free(data32);
    }

    for (i = 0; i < 5; i++) {

        base = random() % UINT32_MAX;
        if (base < 2) base = 2;

        len32 = mpd_sizeinbase(op1, base);
        data32 = mpd_alloc((mpd_size_t)len32, sizeof *data32);
        expected_len32 = mpd_export_u32(&data32, len32, base, op1, ctx);
        if (len32 == SIZE_MAX) {
            mpd_err_fatal("export_to_base failed");
        }

        mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);

        mpd_free(calc);
        mpd_free(data32);

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ctx->status = 0;

            data32 = mpd_alloc(1, sizeof *data32);
            mpd_set_alloc_fail(ctx);
            expected_len32 = mpd_export_u32(&data32, 1, base, op1, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            ASSERT(expected_len32 == SIZE_MAX)
            mpd_free(data32);
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            mpd_minalloc(result);
            ctx->status = 0;

            mpd_set_alloc_fail(ctx);
            mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            ASSERT(mpd_isnan(result))
        }
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);
        mpd_free(calc);
        mpd_free(data32);

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ctx->status = 0;

            data32 = mpd_alloc(1, sizeof *data32);
            mpd_set_alloc_fail(ctx);
            expected_len32 = mpd_export_u32(&data32, 1, base, op1, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            ASSERT(expected_len32 == SIZE_MAX)
            mpd_free(data32);
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            mpd_minalloc(result);
            ctx->status = 0;

            mpd_set_alloc_fail(ctx);
            mpd_import_u32(result, data32, expected_len32, MPD_POS, base, ctx);
            mpd_set_alloc(ctx);

            if (!(ctx->status&MPD_Malloc_error)) {
                break;
            }
            ASSERT(mpd_isnan(result))
        }
        calc = _mpd_to_sci(result, 1);
        compare_expected(calc, expected, expstatus, token[0], ctx);
        mpd_free(calc);
        mpd_free(data32);
    }
}

/*
 * Test a function returning a uint64_t, accepting:
 *     op, context
 *
 * This function is used for:
 *   - mpd_get_uint (64 bit)
 *   - mpd_abs_uint (64 bit)
 *   - mpd_get_u64
 */
#ifndef MPD_LEGACY_COMPILER
static void
_u64_MpdCtx(char **token, uint64_t (*func)(const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    uint64_t calc_uint;
    char calc[23];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    /* conversion should be done as if there were no limits */
    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    expstatus = scan_conditions(token+n);

    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    calc_uint = func(tmp, ctx);
    snprintf(calc, 23, "%" PRIu64, calc_uint);

    /* compare the calculated result to the expected result */
    compare_expected(calc, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);
}
#endif

/*
 * Test a function returning a uint64_t, accepting:
 *     op, context
 *
 * This function is used for:
 *   - mpd_get_uint (64 bit)
 *   - mpd_abs_uint (64 bit)
 *   - mpd_get_u64
 */
static void
_u32_MpdCtx(char **token, uint32_t (*func)(const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    uint32_t calc_uint;
    char calc[23];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    /* conversion should be done as if there were no limits */
    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    expstatus = scan_conditions(token+n);

    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    calc_uint = func(tmp, ctx);
    snprintf(calc, 23, "%" PRIu32, calc_uint);

    /* compare the calculated result to the expected result */
    compare_expected(calc, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);
}

/*
 * Test a function returning an mpd_ssize_t, accepting:
 *     op, fmt, context
 *
 * This function is used for:
 *   - mpd_get_ssize
 *   - mpd_get_i64
 *   - mpd_get_i32
 */
#ifndef MPD_LEGACY_COMPILER
static void
_i64_MpdCtx(char **token, int64_t (*func)(const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    int64_t calc_ssize;
    char calc[23];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    /* conversion should be done as if there were no limits */
    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    expstatus = scan_conditions(token+n);

    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    calc_ssize = func(tmp, ctx);
    snprintf(calc, 23, "%" PRIi64, calc_ssize);

    /* compare the calculated result to the expected result */
    compare_expected(calc, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);
}
#endif

/*
 * Test a function returning an mpd_ssize_t, accepting:
 *     op, fmt, context
 *
 * This function is used for:
 *   - mpd_get_ssize
 *   - mpd_get_i64
 *   - mpd_get_i32
 */
static void
_i32_MpdCtx(char **token, int32_t (*func)(const mpd_t *, mpd_context_t *), mpd_context_t *ctx)
{
    mpd_context_t maxctx;
    int32_t calc_ssize;
    char calc[23];
    char *expected;
    uint32_t expstatus;
    int n;

    mpd_readcontext(&maxctx);
    maxctx.traps = MPD_Malloc_error;

    /* conversion should be done as if there were no limits */
    n = scan_1op_result(op, &expected, token, &maxctx);
    _TripleTest(op, ctx, token[0]);

    expstatus = scan_conditions(token+n);

    mpd_init_rand(tmp);
    mpd_copy(tmp, op, ctx);
    ctx->status = 0;

    calc_ssize = func(tmp, ctx);
    snprintf(calc, 23, "%" PRIi32, calc_ssize);

    /* compare the calculated result to the expected result */
    compare_expected(calc, expected, expstatus, token[0], ctx);
    check_equalmem(tmp, op, token[0]);
}

static void
triple_cov(void)
{
    mpd_uint128_triple_t triple = { MPD_TRIPLE_QNAN, 2, 0, 0, 0 };
    uint32_t status = 0;

    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.sign = 0;
    triple.exp = 1;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = MPD_TRIPLE_INF;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = MPD_TRIPLE_NORMAL;
    triple.sign = 2;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = MPD_TRIPLE_NORMAL;
    triple.sign = 0;
    triple.exp = INT64_MAX;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = MPD_TRIPLE_NORMAL;
    triple.sign = 0;
    triple.exp = INT64_MIN;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = MPD_TRIPLE_NORMAL;
    triple.sign = 0;
    triple.exp = MPD_SSIZE_MAX;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = MPD_TRIPLE_NORMAL;
    triple.sign = 0;
    triple.exp = MPD_SSIZE_MIN;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))

    triple.tag = (enum mpd_triple_class)10;
    triple.sign = 0;
    status = 0;
    mpd_from_uint128_triple(op, &triple, &status);
    ASSERT(status == MPD_Conversion_syntax)
    ASSERT(mpd_isqnan(op))
}


/* process a file */
static void
doit(const char *filename)
{
    FILE *file;
    mpd_context_t ctx;
    char *line;
    char *tmpline;
    char *token[MAXTOKEN+1];
    uint32_t testno;
    mpd_ssize_t l;


    mpd_testcontext(&ctx);

    ctx.traps = MPD_Malloc_error;

    file_failure = 0;
    if (strcmp(filename, "-") == 0) {
        file = stdin;
    }
    else {
        if ((file = fopen(filename, "r")) == NULL) {
            mpd_err_fatal("could not open %s", filename);
        }
        if (!startswith(filename, "official") && !startswith(filename, "additional")) {
            printf("%s ...", filename);
            fflush(stdout);
        }
    }

    if ((line = mpd_alloc(MAXLINE+1, sizeof *line)) == NULL) {
        mpd_err_fatal("out of memory");
    }
    if ((tmpline = mpd_alloc(MAXLINE+1, sizeof *line)) == NULL) {
        mpd_err_fatal("out of memory");
    }


    while (fgets(line, MAXLINE+1, file) != NULL) {

        /* split a line into tokens */
        strcpy(tmpline, line);

        for (int i =0; i < MAXTOKEN+1; i++) {
            token[i] = NULL;
        }

        if (split(token, tmpline) == 0) {
            goto cleanup;
        }


        /* comments */
        if (startswith(token[0], "--")) {
            goto cleanup;
        }
        /* end comments */

        /* skip bool* tests in extra.decTest */
        if (startswith(token[0], "bool")) {
            goto cleanup;
        }
        /* end skips */


        /* directives */
        if (startswith(token[0], "ExtendedRange")) {
            ASSERT(token[1] != NULL);
            if (strcmp(token[1], "1") == 0) {
                extended = 1;
            }
            else if (strcmp(token[1], "0") == 0) {
                extended = 0;
            }
            else {
                mpd_err_fatal("%s: %s", filename, line);
            }
            goto cleanup;
        }

        if (startswith(token[0], "Precision")) {
            ASSERT(token[1] != NULL);
            if (strcmp(token[1], "MAX_PREC") == 0) {
                l = MPD_MAX_PREC;
            }
            else {
                l = scan_ssize(token);
                if (errno != 0) {
                    mpd_err_fatal("%s: %s", filename, line);
                }
            }
            ctx.prec = l;
            goto cleanup;
        }

        if (startswith(token[0], "Rounding")) {
            ASSERT(token[1] != NULL);
            if (eqtoken(token[1], "Ceiling"))
                ctx.round = MPD_ROUND_CEILING;
            else if (eqtoken(token[1], "Up"))
                ctx.round = MPD_ROUND_UP;
            else if (eqtoken(token[1], "Half_up"))
                ctx.round = MPD_ROUND_HALF_UP;
            else if (eqtoken(token[1], "Half_even"))
                ctx.round = MPD_ROUND_HALF_EVEN;
            else if (eqtoken(token[1], "Half_down"))
                ctx.round = MPD_ROUND_HALF_DOWN;
            else if (eqtoken(token[1], "Down"))
                ctx.round = MPD_ROUND_DOWN;
            else if (eqtoken(token[1], "Floor"))
                ctx.round = MPD_ROUND_FLOOR;
            else if (eqtoken(token[1], "05up"))
                ctx.round = MPD_ROUND_05UP;
            else
                mpd_err_fatal("%s: %s", filename, line);
            goto cleanup;
        }

        if (startswith(token[0], "MaxExponent")) {
            ASSERT(token[1] != NULL);
            if (strcmp(token[1], "MAX_EMAX") == 0) {
                l = MPD_MAX_EMAX;
            }
            else {
                l = scan_ssize(token);
                if (errno != 0) {
                    mpd_err_fatal("%s: %s", filename, line);
                }
            }
            ctx.emax = l;
            goto cleanup;
        }

        if (startswith(token[0], "MinExponent")) {
            ASSERT(token[1] != NULL);
            if (strcmp(token[1], "MIN_EMIN") == 0) {
                l = MPD_MIN_EMIN;
            }
            else {
                l = scan_ssize(token);
                if (errno != 0) {
                    mpd_err_fatal("%s: %s", filename, line);
                }
            }
            ctx.emin = l;
            goto cleanup;
        }

        if (startswith(token[0], "Dectest")) {
            ASSERT(token[1] != NULL);
            if (token[1] == NULL) {
                mpd_err_fatal("%s: %s", filename, line);
            }
            doit(token[1]);
            goto cleanup;
        }
        /* end directives */

        /* optional directives */
        if (startswith(token[0], "Version")) {
            goto cleanup;
        }

        if (startswith(token[0], "Extended")) {
            goto cleanup;
        }

        if (startswith(token[0], "Clamp")) {
            ASSERT(token[1] != NULL);
            l = scan_ssize(token);
            if (errno != 0) {
                mpd_err_fatal("%s: %s", filename, line);
            }
            if (!mpd_qsetclamp(&ctx, (int)l)) {
                mpd_err_fatal("%s: %s", filename, line);
            }
            goto cleanup;
        }
        if (startswith(token[0], "Locale")) {
            ASSERT(token[1] != NULL);
            if (token[1] == NULL) {
                mpd_err_fatal("%s: %s", filename, line);
            }
            if (extended) {
                printf("locale: %s\n", token[1]);
                fflush(stdout);
            }
            if (setlocale(LC_NUMERIC, token[1]) == NULL) {
                mpd_err_fatal("%s: %s", filename, line);
            }
            goto cleanup;
        }

        mpd_assert_context_ok(&ctx);
        /* end optional directives */


        /*
         * Actual tests start here:
         *   - token[0] is the id
         *   - token[1] is the operation type
         *   - testno can be used for setting a watchpoint in the debugger
         */
        testno = (uint32_t)get_testno(token[0]);
        (void)testno;

        /* The id is in the skip list */
        if (check_skip(token[0])) {
            goto cleanup;
        }
#ifdef MPD_CONFIG_64
        /* Skip 32-bit specific coverage tests. */
        if (startswith(token[0], "cov32")) {
            goto cleanup;
        }
#else
        /* Skip 64-bit specific coverage tests. */
        if (startswith(token[0], "cov64")) {
            goto cleanup;
        }
#endif
        /* Translate operation type for powmod */
        if (startswith(token[0], "pwmx")) {
            free(token[1]);
            token[1] = malloc(sizeof("powmod"));
            strcpy(token[1], "powmod");
        }
        /* end skips */


        /* Unary functions with char * result */
        if (eqtoken(token[1], "tosci") || eqtoken(token[1], "apply")) {
            _cp_MpdCtx(token, mpd_to_sci, &ctx);
            sci_eng_size(token, mpd_to_sci_size, &ctx);
        }
        else if (eqtoken(token[1], "toeng")) {
            _cp_MpdCtx(token, mpd_to_eng, &ctx);
            sci_eng_size(token, mpd_to_eng_size, &ctx);
        }
        else if (eqtoken(token[1], "format")) {
            _cp_MpdFmtCtx(token, mpd_format, &ctx);
        }
        /* Unary function with const char * result */
        else if (eqtoken(token[1], "class")) {
            _ccp_MpdCtx(token, mpd_class, &ctx);
        }

        /* Unary functions with mpd_t * result */
        else if (eqtoken(token[1], "abs")) {
            _Res_Op_Ctx(token, mpd_abs, &ctx);
        }
        else if (eqtoken(token[1], "copy")) {
            _Res_Op_Ctx(token, mpd_copy, &ctx);
        }
        else if (eqtoken(token[1], "copyabs")) {
            _Res_Op_Ctx(token, mpd_copy_abs, &ctx);
        }
        else if (eqtoken(token[1], "copynegate")) {
            _Res_Op_Ctx(token, mpd_copy_negate, &ctx);
        }
        else if (eqtoken(token[1], "exp")) {
            if (extended) {
                if (testno != 126) {
                    ctx.allcr = 0;
                    /* exp: err < 1ulp, but not correctly rounded */
                    _Res_Op_Ctx(token, mpd_exp, &ctx);
                    ctx.allcr = 1;
                }
            }
            _Res_Op_Ctx(token, mpd_exp, &ctx);
        }
        else if (eqtoken(token[1], "invert")) {
            _Res_Op_Ctx(token, mpd_invert, &ctx);
        }
        else if (eqtoken(token[1], "invroot")) {
            _Res_Op_Ctx(token, mpd_invroot, &ctx);
        }
        else if (eqtoken(token[1], "ln")) {
            if (extended) {
                ctx.allcr = 0;
                _Res_Op_Ctx(token, mpd_ln, &ctx);
                ctx.allcr = 1;
            }
            _Res_Op_Ctx(token, mpd_ln, &ctx);
        }
        else if (eqtoken(token[1], "log10")) {
            if (extended) {
                ctx.allcr = 0;
                _Res_Op_Ctx(token, mpd_log10, &ctx);
                ctx.allcr = 1;
            }
            _Res_Op_Ctx(token, mpd_log10, &ctx);
        }
        else if (eqtoken(token[1], "logb")) {
            _Res_Op_Ctx(token, mpd_logb, &ctx);
        }
        else if (eqtoken(token[1], "minus")) {
            _Res_Op_Ctx(token, mpd_minus, &ctx);
        }
        else if (eqtoken(token[1], "nextminus")) {
            _Res_Op_Ctx(token, mpd_next_minus, &ctx);
        }
        else if (eqtoken(token[1], "nextplus")) {
            _Res_Op_Ctx(token, mpd_next_plus, &ctx);
        }
        else if (eqtoken(token[1], "plus")) {
            _Res_Op_Ctx(token, mpd_plus, &ctx);
        }
        else if (eqtoken(token[1], "reduce")) {
            _Res_Op_Ctx(token, mpd_reduce, &ctx);
        }
        else if (eqtoken(token[1], "squareroot")) {
            #ifdef MPD_CONFIG_32
                if (ctx.prec == MPD_MAX_PREC) mpd_set_alloc_limit(16000000);
            #endif
            _Res_Op_Ctx(token, mpd_sqrt, &ctx);
            #ifdef MPD_CONFIG_32
                if (ctx.prec == MPD_MAX_PREC) mpd_set_alloc_limit(SIZE_MAX);
            #endif
        }
        else if (eqtoken(token[1], "quantize_squareroot")) {
            #ifdef MPD_CONFIG_32
                if (ctx.prec == MPD_MAX_PREC) mpd_set_alloc_limit(16000000);
            #endif
            _Res_Op_CtxWithQuantize(token, mpd_sqrt, &ctx);
            #ifdef MPD_CONFIG_32
                if (ctx.prec == MPD_MAX_PREC) mpd_set_alloc_limit(SIZE_MAX);
            #endif
        }
        else if (eqtoken(token[1], "tointegral")) {
            _Res_Op_Ctx(token, mpd_round_to_int, &ctx);
        }
        else if (eqtoken(token[1], "tointegralx")) {
            _Res_Op_Ctx(token, mpd_round_to_intx, &ctx);
        }
        else if (eqtoken(token[1], "floor")) {
            _Res_Op_Ctx(token, mpd_floor, &ctx);
        }
        else if (eqtoken(token[1], "ceil")) {
            _Res_Op_Ctx(token, mpd_ceil, &ctx);
        }
        else if (eqtoken(token[1], "trunc")) {
            _Res_Op_Ctx(token, mpd_trunc, &ctx);
        }


        /* Binary function returning an int */
        else if (eqtoken(token[1], "samequantum")) {
            _Int_Binop(token, mpd_same_quantum, &ctx);
        }
        /* Binary function returning an int, equal operands */
        else if (eqtoken(token[1], "samequantum_eq")) {
            _Int_EqualBinop(token, mpd_same_quantum, &ctx);
        }

        /* Binary functions with mpd_t * result */
        else if (eqtoken(token[1], "add")) {
            _Res_Binop_Ctx(token, mpd_add, &ctx);
        }
        else if (eqtoken(token[1], "and")) {
            _Res_Binop_Ctx(token, mpd_and, &ctx);
        }
        else if (eqtoken(token[1], "copysign")) {
            _Res_Binop_Ctx(token, mpd_copy_sign, &ctx);
        }
        else if (eqtoken(token[1], "divide")) {
            #ifdef MPD_CONFIG_32
                if (ctx.prec == MPD_MAX_PREC) mpd_set_alloc_limit(16000000);
            #endif
            _Res_Binop_Ctx(token, mpd_div, &ctx);
            #ifdef MPD_CONFIG_32
                if (ctx.prec == MPD_MAX_PREC) mpd_set_alloc_limit(SIZE_MAX);
            #endif
        }
        else if (eqtoken(token[1], "divideint")) {
            _Res_Binop_Ctx(token, mpd_divint, &ctx);
        }
        else if (eqtoken(token[1], "max")) {
            _Res_Binop_Ctx(token, mpd_max, &ctx);
        }
        else if (eqtoken(token[1], "maxmag") || eqtoken(token[1], "max_mag")) {
            _Res_Binop_Ctx(token, mpd_max_mag, &ctx);
        }
        else if (eqtoken(token[1], "min")) {
            _Res_Binop_Ctx(token, mpd_min, &ctx);
        }
        else if (eqtoken(token[1], "minmag") || eqtoken(token[1], "min_mag")) {
            _Res_Binop_Ctx(token, mpd_min_mag, &ctx);
        }
        else if (eqtoken(token[1], "multiply")) {
            _Res_Binop_Ctx(token, mpd_mul, &ctx);
        }
        else if (eqtoken(token[1], "nexttoward")) {
            _Res_Binop_Ctx(token, mpd_next_toward, &ctx);
        }
        else if (eqtoken(token[1], "or")) {
            _Res_Binop_Ctx(token, mpd_or, &ctx);
        }
        else if (eqtoken(token[1], "power")) {
            if (extended) {
                ctx.allcr = 0;
                _Res_Binop_Ctx(token, mpd_pow, &ctx);
                ctx.allcr = 1;
            }
            _Res_Binop_Ctx(token, mpd_pow, &ctx);
        }
        else if (eqtoken(token[1], "quantize")) {
            _Res_Binop_Ctx(token, mpd_quantize, &ctx);
        }
        else if (eqtoken(token[1], "resc")) {
            _Res_Op_Lsize_Ctx(SKIP_NONINT, token, mpd_rescale, &ctx);
        }
        else if (eqtoken(token[1], "remainder")) {
            _Res_Binop_Ctx(token, mpd_rem, &ctx);
        }
        else if (eqtoken(token[1], "remaindernear")) {
            _Res_Binop_Ctx(token, mpd_rem_near, &ctx);
        }
        else if (eqtoken(token[1], "rotate")) {
            _Res_Binop_Ctx(token, mpd_rotate, &ctx);
        }
        else if (eqtoken(token[1], "scaleb")) {
            _Res_Binop_Ctx(token, mpd_scaleb, &ctx);
        }
        else if (eqtoken(token[1], "shift")) {
            _Res_Binop_Ctx(token, mpd_shift, &ctx);
            if (extended) {
                _Res_Op_Lsize_Ctx(SKIP_NONINT, token, mpd_shiftn, &ctx);
            }
        }
        else if (eqtoken(token[1], "subtract")) {
            _Res_Binop_Ctx(token, mpd_sub, &ctx);
        }
        else if (eqtoken(token[1], "xor")) {
            _Res_Binop_Ctx(token, mpd_xor, &ctx);
        }

        /* Binary functions with mpd_t result, equal operands */
        else if (eqtoken(token[1], "add_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_add, &ctx);
        }
        else if (eqtoken(token[1], "and_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_and, &ctx);
        }
        else if (eqtoken(token[1], "copysign_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_copy_sign, &ctx);
        }
        else if (eqtoken(token[1], "divide_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_div, &ctx);
        }
        else if (eqtoken(token[1], "divideint_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_divint, &ctx);
        }
        else if (eqtoken(token[1], "max_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_max, &ctx);
        }
        else if (eqtoken(token[1], "maxmag_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_max_mag, &ctx);
        }
        else if (eqtoken(token[1], "min_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_min, &ctx);
        }
        else if (eqtoken(token[1], "minmag_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_min_mag, &ctx);
        }
        else if (eqtoken(token[1], "multiply_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_mul, &ctx);
        }
        else if (eqtoken(token[1], "nexttoward_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_next_toward, &ctx);
        }
        else if (eqtoken(token[1], "or_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_or, &ctx);
        }
        else if (eqtoken(token[1], "power_eq")) {
            if (extended) {
                ctx.allcr = 0;
                _Res_EqualBinop_Ctx(token, mpd_pow, &ctx);
                ctx.allcr = 1;
            }
            _Res_EqualBinop_Ctx(token, mpd_pow, &ctx);
        }
        else if (eqtoken(token[1], "quantize_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_quantize, &ctx);
        }
        else if (eqtoken(token[1], "remainder_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_rem, &ctx);
        }
        else if (eqtoken(token[1], "remaindernear_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_rem_near, &ctx);
        }
        else if (eqtoken(token[1], "rotate_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_rotate, &ctx);
        }
        else if (eqtoken(token[1], "scaleb_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_scaleb, &ctx);
        }
        else if (eqtoken(token[1], "shift_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_shift, &ctx);
        }
        else if (eqtoken(token[1], "subtract_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_sub, &ctx);
        }
        else if (eqtoken(token[1], "xor_eq")) {
            _Res_EqualBinop_Ctx(token, mpd_xor, &ctx);
        }

        /* Binary function with binary result */
        else if (eqtoken(token[1], "divmod")) {
            _Binres_Binop_Ctx(token, mpd_divmod, &ctx);
        }

        /* Binary function with binary result, equal operands */
        else if (eqtoken(token[1], "divmod_eq")) {
            _Binres_EqualBinop_Ctx(token, mpd_divmod, &ctx);
        }


        /* Ternary functions with mpd_t result */
        else if (eqtoken(token[1], "fma")) {
            _Res_Ternop_Ctx(token, mpd_fma, &ctx);
        }
        else if (eqtoken(token[1], "powmod")) {
            _Res_Ternop_Ctx(token, mpd_powmod, &ctx);
        }

        /* Ternary functions with mpd_t result, eq_eq_op */
        else if (eqtoken(token[1], "fma_eq_eq_op")) {
            _Res_EqEqOp_Ctx(token, mpd_fma, &ctx);
        }
        else if (eqtoken(token[1], "powmod_eq_eq_op")) {
            _Res_EqEqOp_Ctx(token, mpd_powmod, &ctx);
        }

        /* Ternary functions with mpd_t result, eq_op_eq */
        else if (eqtoken(token[1], "fma_eq_op_eq")) {
            _Res_EqOpEq_Ctx(token, mpd_fma, &ctx);
        }
        else if (eqtoken(token[1], "powmod_eq_op_eq")) {
            _Res_EqOpEq_Ctx(token, mpd_powmod, &ctx);
        }

        /* Ternary functions with mpd_t result, op_eq_eq */
        else if (eqtoken(token[1], "fma_op_eq_eq")) {
            _Res_OpEqEq_Ctx(token, mpd_fma, &ctx);
        }
        else if (eqtoken(token[1], "powmod_op_eq_eq")) {
            _Res_OpEqEq_Ctx(token, mpd_powmod, &ctx);
        }

        /* Ternary functions with mpd_t result, eq_eq_eq */
        else if (eqtoken(token[1], "fma_eq_eq_eq")) {
            _Res_EqEqEq_Ctx(token, mpd_fma, &ctx);
        }
        else if (eqtoken(token[1], "powmod_eq_eq_eq")) {
            _Res_EqEqEq_Ctx(token, mpd_powmod, &ctx);
        }

        /* Special cases for the comparison functions */
        else if (eqtoken(token[1], "compare")) {
            _Int_Res_Binop_Ctx(token, mpd_compare, &ctx);
            _Int_Binop_Ctx(SKIP_NAN, token, mpd_cmp, &ctx);
        }
        else if (eqtoken(token[1], "comparesig")) {
            _Int_Res_Binop_Ctx(token, mpd_compare_signal, &ctx);
        }
        else if (eqtoken(token[1], "comparetotal")) {
            _Int_Res_Binop(token, mpd_compare_total, &ctx);
            _Int_Binop(token, mpd_cmp_total, &ctx);
        }
        else if (eqtoken(token[1], "comparetotmag")) {
            _Int_Res_Binop(token, mpd_compare_total_mag, &ctx);
            _Int_Binop(token, mpd_cmp_total_mag, &ctx);
        }

        /* Special cases for the comparison functions, equal operands */
        else if (eqtoken(token[1], "compare_eq")) {
            _Int_Res_EqualBinop_Ctx(token, mpd_compare, &ctx);
            _Int_EqualBinop_Ctx(SKIP_NAN, token, mpd_cmp, &ctx);
        }
        else if (eqtoken(token[1], "comparesig_eq")) {
            _Int_Res_EqualBinop_Ctx(token, mpd_compare_signal, &ctx);
        }
        else if (eqtoken(token[1], "comparetotal_eq")) {
            _Int_Res_EqualBinop(token, mpd_compare_total, &ctx);
            _Int_EqualBinop(token, mpd_cmp_total, &ctx);
        }
        else if (eqtoken(token[1], "comparetotmag_eq")) {
            _Int_Res_EqualBinop(token, mpd_compare_total_mag, &ctx);
            _Int_EqualBinop(token, mpd_cmp_total_mag, &ctx);
        }

        /* Special cases for the shift functions */
        else if (eqtoken(token[1], "shiftleft")) {
            _Res_Op_Lsize_Ctx(SKIP_NONINT, token, _mpd_shiftl, &ctx);
        }
        else if (eqtoken(token[1], "shiftright")) {
            _Res_Op_Lsize_Ctx(SKIP_NONINT, token, _mpd_shiftr, &ctx);
        }

        /* Special case for mpd_qln10() */
        else if (eqtoken(token[1], "ln10")) {
            _test_mpd_qln10(SKIP_NONINT, token, &ctx);
        }

        /* Special case for the base conversion functions */
        else if (eqtoken(token[1], "baseconv")) {
            _Baseconv(token, &ctx);
        }

        /* Special cases for the get_int functions */
#ifdef MPD_CONFIG_64
        else if (eqtoken(token[1], "get_uint64")) {
            _u64_MpdCtx(token, mpd_get_uint, &ctx);
        }
        else if (eqtoken(token[1], "get_uint64_abs")) {
            _u64_MpdCtx(token, mpd_abs_uint, &ctx);
        }
        else if (eqtoken(token[1], "get_ssize64")) {
            _i64_MpdCtx(token, mpd_get_ssize, &ctx);
        }
#else
        else if (eqtoken(token[1], "get_uint32")) {
            _u32_MpdCtx(token, mpd_get_uint, &ctx);
        }
        else if (eqtoken(token[1], "get_uint32_abs")) {
            _u32_MpdCtx(token, mpd_abs_uint, &ctx);
        }
        else if (eqtoken(token[1], "get_ssize32")) {
            _i32_MpdCtx(token, mpd_get_ssize, &ctx);
        }

#endif

#ifndef MPD_LEGACY_COMPILER
        else if (eqtoken(token[1], "get_u64")) {
            _u64_MpdCtx(token, mpd_get_u64, &ctx);
        }
        else if (eqtoken(token[1], "get_i64")) {
            _i64_MpdCtx(token, mpd_get_i64, &ctx);
        }
#endif

        else if (eqtoken(token[1], "get_u32")) {
            _u32_MpdCtx(token, mpd_get_u32, &ctx);
        }
        else if (eqtoken(token[1], "get_i32")) {
            _i32_MpdCtx(token, mpd_get_i32, &ctx);
        }

        else if (startswith(token[1], "get_")) {
            /* empty */
        }

        else if (eqtoken(token[1], "rescale")) {
            /* empty */
        }

        /* unknown operation */
        else {
            mpd_err_fatal("%s: unknown operation: %s", filename, line);
        }
        /* end tests */

        cleanup:
        freetoken(token);
    }

    mpd_free(line);
    mpd_free(tmpline);
    if (file != stdin) {
        fclose(file);
    }

    if (!startswith(filename, "official") &&
        !startswith(filename, "additional") &&
        !file_failure) {
        printf(" PASS\n");
    }
    else {
        printf("\n");
    }
    fflush(stdout);
}

static void
traphandler(mpd_context_t *ctx)
{
    if (ctx->newtrap & MPD_Malloc_error) {
        fprintf(stderr, "\n\n\
runtest: out of memory:\n\
    - bignum tests require 200MB heap and 300KB stack.\n\
    - normal tests require 10MB heap and 50KB stack.\n\n");
    }
    else {
        fprintf(stderr, "\n\nruntest: unexpected error: relevant traps: %u\n\n",
                        ctx->newtrap);
    }

    exit(1);
}

static void
usage(void)
{
    fputs("runtest: usage: runtest testfile [--custom] [--alloc]\n", stderr);
    exit(EXIT_FAILURE);
}


int
main(int argc, char *argv[])
{
    const char *filename = NULL;
    bool custom_alloc = false;
    bool check_alloc = false;

    for (int i = 1; i < argc; i++) {
        if (!filename && (strcmp(argv[i], "-") == 0 || !startswith(argv[i], "--"))) {
            filename = argv[i];
        }
        else if (!custom_alloc && strcmp(argv[i], "--custom") == 0) {
            custom_alloc = true;
        }
        else if (!check_alloc && strcmp(argv[i], "--alloc") == 0) {
            check_alloc = true;
        }
        else {
            usage();
        }
    }
    if (filename == NULL) {
        usage();
    }

    /* Test version */
    if (strcmp(mpd_version(), "4.0.1") != (0)) {
        fputs("runtest: error: mpd_version() != 4.0.1\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (strcmp(MPD_VERSION, "4.0.1") != (0)) {
        fputs("runtest: error: MPD_VERSION != 4.0.1\n", stderr);
        exit(EXIT_FAILURE);
    }

#ifdef _MSC_VER
  #pragma warning(push)
  #pragma warning(disable : 4127)
#endif
    if (MPD_MAJOR_VERSION != (4)) {
        fputs("runtest: error: MPD_MAJOR_VERSION != 4\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (MPD_MINOR_VERSION != (0)) {
        fputs("runtest: error: MPD_MINOR_VERSION != 0\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (MPD_MICRO_VERSION != (1)) {
        fputs("runtest: error: MPD_MICRO_VERSION != 1\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (MPD_VERSION_HEX != (0x4000100)) {
        fputs("runtest: error: MPD_VERSION_HEX != 0x4000100\n", stderr);
        exit(EXIT_FAILURE);
    }
#ifdef _MSC_VER
  #pragma warning(pop)
#endif

    extended = strcmp(filename, "-") != 0;

    /* Initialize random number generator */
    srandom((unsigned int)time(NULL));

    /* Initialize custom allocation functions */
    mpd_init_alloc(custom_alloc, check_alloc);

    /* Initialize MPD_MINALLOC (optional, default is 2) */
    MPD_MINALLOC = 2;

    /* Initialize trap handler */
    mpd_traphandler = traphandler;

    op = mpd_qnew();
    op1 = mpd_qnew();
    op2 = mpd_qnew();
    op3 = mpd_qnew();
    tmp = mpd_qnew();
    tmp1 = mpd_qnew();
    tmp2 = mpd_qnew();
    tmp3 = mpd_qnew();
    result = mpd_qnew();
    result1 = mpd_qnew();
    result2 = mpd_qnew();

    triple_cov();
    doit(filename);

    mpd_del(op);
    mpd_del(op1);
    mpd_del(op2);
    mpd_del(op3);
    mpd_del(tmp);
    mpd_del(tmp1);
    mpd_del(tmp2);
    mpd_del(tmp3);
    mpd_del(result);
    mpd_del(result1);
    mpd_del(result2);


    return global_failure;
}
