/*
 * Copyright (c) 2020-2025 Stefan Krah. All rights reserved.
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


#ifdef _AIX
  #define __STDC_FORMAT_MACROS
#endif

#ifndef _MSC_VER
  #include "config.h"
  #ifdef HAVE_PTHREAD_H
    #include <pthread.h>
  #endif
#endif

#include <cctype>
#include <cerrno>
#include <cinttypes>
#include <clocale>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <atomic>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "mpdecimal.h"

#include "decimal.hh"
#include "test.hh"
#include "vctest.hh"


using decimal::ValueError;
using decimal::MallocError;
using decimal::RuntimeError;
using decimal::InvalidOperation;
using decimal::Decimal;
using decimal::Context;
using decimal::context_template;
using decimal::context;

using decimal::util::safe_downcast;

#if defined(MPD_CONFIG_32)
using test::set_alloc_limit;
#endif
using test::set_alloc;
using test::set_alloc_fail;


enum skip_cmp {SKIP_NONE, SKIP_NAN, SKIP_NONINT};

/*
 * These extended ranges are required for the official test suite and are
 * not problematic for its specific test cases. However, they should not
 * be used in production code.
 *
 * The use of the directive "ExtendedRange" is not related to the "Extended"
 * directive that is briefly referred to in the official tests.
 */
#if defined(MPD_CONFIG_64)
  #define MPD_READ_MAX_PREC 1070000000000000000LL
#elif defined(MPD_CONFIG_32)
  #define MPD_READ_MAX_PREC 1070000000
#else
  #error "config not defined"
#endif

static mpd_context_t
readcontext(const bool extended)
{
    mpd_context_t c;

    if (extended) {
        c.prec = MPD_READ_MAX_PREC;
        c.emax = MPD_READ_MAX_PREC;
        c.emin = -MPD_READ_MAX_PREC;
    }
    else {
        c.prec = MPD_MAX_PREC;
        c.emax = MPD_MAX_EMAX;
        c.emin = MPD_MIN_EMIN;
    }

    c.traps = MPD_Malloc_error;
    c.status = 0;
    c.newtrap = 0;
    c.round = MPD_ROUND_HALF_UP;
    c.clamp = 0;
    c.allcr = 1;

    return c;
}

static mpd_context_t
testcontext(const bool extended)
{
    mpd_context_t c;

    if (extended) {
    #if defined(MPD_CONFIG_64)
        c.prec = MPD_MAX_PREC;
        c.emax = MPD_MAX_EMAX;
        c.emin = MPD_MIN_EMIN;
    #elif defined(MPD_CONFIG_32)
        c.prec = 999999999;
        c.emax = 999999999;
        c.emin = -999999999;
    #else
        #error "config not defined"
    #endif
    }
    else {
        c.prec = MPD_MAX_PREC;
        c.emax = MPD_MAX_EMAX;
        c.emin = MPD_MIN_EMIN;
    }

    c.traps = MPD_Malloc_error;
    c.status = 0;
    c.newtrap = 0;
    c.round = MPD_ROUND_HALF_UP;
    c.clamp = 0;
    c.allcr = 1;

    return c;
}

static void
mpd_assert_context_ok(const Context& c, const std::vector<std::string>& token)
{
    const mpd_context_t *ctx = c.getconst();

    DECIMAL_ASSERT(0 < ctx->prec && ctx->prec <= MPD_READ_MAX_PREC, token);
    DECIMAL_ASSERT(0 <= ctx->emax && ctx->emax <= MPD_READ_MAX_PREC, token);
    DECIMAL_ASSERT(-MPD_READ_MAX_PREC <= ctx->emin && ctx->emin <= 0, token);
    DECIMAL_ASSERT(0 <= ctx->round && ctx->round < MPD_ROUND_GUARD, token);
    DECIMAL_ASSERT(ctx->traps <= MPD_Max_status, token);
    DECIMAL_ASSERT(ctx->status <= MPD_Max_status, token);
    DECIMAL_ASSERT(ctx->clamp == 0 || ctx->clamp == 1, token);
    DECIMAL_ASSERT(ctx->allcr == 0 || ctx->allcr == 1, token);
}


/* Known differences that are within the spec */
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

static const struct result_diff ulp_cases[] {
    /* Cases where the result is allowed to differ by less than one ULP.
     * Only needed if ctx->allcr is 0. */
    { "expx013", "1.001000", "1.001001" },
    { "expx020", "1.000000", "1.000001" },
    { "expx109", "0.999999910000004049999878", "0.999999910000004049999879" },
    { "expx1036", "1.005088", "1.005087" },
    { "expx350", "1.0000000", "1.0000001" },
    { "expx351", "1.0000000", "1.0000001" },
    { "expx352", "1.0000000", "1.0000001" },
};

static const struct status_diff status_cases[] {
    /* With a reduced working precision in mpd_qpow() the status matches. */
    { "pwsx803", MPD_Inexact|MPD_Rounded|MPD_Subnormal|MPD_Underflow, MPD_Inexact|MPD_Rounded },
};

static const char *skipit[] {
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
};

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

    return static_cast<mpd_ssize_t>(retval);
}

static uint64_t
rnd(void)
{
    static thread_local std::mt19937_64 r(time(nullptr));

    return r();
}

static void
mpd_init_rand(Decimal &x)
{
    Context maxcontext{readcontext(false)};
    uint64_t r = rnd() % 100;
    uint8_t sign = rnd() % 2;

    if (r >= 80) {
        x = Decimal("-1111111111e20200", maxcontext);
    }
    else if (r >= 60) {
        x = Decimal("-1111111111222222222233333333334444444444555555555566666666667777777777"
                    "888888888899999999990000000000e-1201", maxcontext);
    }
    else if (r >= 40) {
        x = sign ? Decimal("-nan") : Decimal("nan");
    }
    else if (r >= 20) {
        x = sign ? Decimal("-snan") : Decimal("snan");
    }
    else {
        x = sign ? Decimal("-inf") : Decimal("inf");
    }
}

static bool
skip_test(const std::string& id)
{
    const auto& loc = std::find(std::begin(skipit), std::end(skipit), id);
    if (loc != std::end(skipit)) {
        return true;
    }

    return false;
}

static bool
startswith(const std::string& s, const char *prefix)
{
    return strncasecmp(s.c_str(), prefix, strlen(prefix)) == 0;
}

static bool
endswith(const std::string& s, const char *suffix)
{
    std::string rs(s);
    std::string prefix(suffix);
    std::reverse(rs.begin(), rs.end());
    std::reverse(prefix.begin(), prefix.end());
    return startswith(rs, prefix.c_str());
}

static bool
eqtoken(const std::string& tok, const char *s)
{
    return strcasecmp(tok.c_str(), s) == 0;
}

static bool
istokchar(unsigned char c)
{
    return std::isalnum(c) || (std::ispunct(c) && c != '"' && c != '\'');
}

static int
nexttoken(std::string::const_iterator& start,
          std::string::const_iterator& end,
          std::string::const_iterator& next_start,
          const std::string::const_iterator& nul)
{
    end = next_start;

    for (; end != nul; end++) {
        if (isspace(static_cast<unsigned char>(*end))) {
            /* empty */
        }
        else if (*end == '-' && (end+1) != nul && *(end+1) == '-') {
            start = end = next_start = nul;
            return 0;
        }
        else if (*end == '"') {
            start = ++end;
            for (; end != nul; end++) {
                if (*end == '"') {
                    if ((end+1) != nul && *(end+1) == '"') {
                        end++;  /* official test cases: "1""1" is parsed as a single string. */
                    }
                    else {
                        next_start = end+1;
                        return 0;
                    }
                }
            }
            return -1;
        }
        else if (*end == '\'') {
            start = ++end;
            for (; end != nul; end++) {
                if (*end == '\'') {
                    if ((end+1) != nul && *(end+1) == '\'') {
                        end++;  /* official test cases: '1''1' is parsed as a single string. */
                    }
                    else {
                        next_start = end+1;
                        return 0;
                    }
                }
            }
            return -1;
        }
        else {
            start = end;
            for (; end != nul; end++) {
                if (std::isspace(static_cast<unsigned char>(*end))) {
                    break;
                }
                if (!istokchar(static_cast<unsigned char>(*end))) {
                    return -1;
                }
            }
            next_start = end;
            return 0;
        }
    }

    start = next_start = end;
    return 0;
}

/* split a line into tokens */
static std::vector<std::string>
split(const std::string& line)
{
    std::string::const_iterator start = line.begin();
    std::string::const_iterator end = start;
    std::string::const_iterator next_start = start;
    const std::string::const_iterator nul = line.end();
    std::vector<std::string> token;

    while (true) {
        const int r = nexttoken(start, end, next_start, nul);
        if (r < 0) {
            std::cerr << "parse_error: " << line << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (end == start && end == next_start) {
            break;
        }
        std::string tok{start, end};
        token.push_back(tok);
    }

    return token;
}

/* returns all expected conditions in a status flag */
static uint32_t
scan_conditions(const std::vector<std::string>& token, const size_t n)
{
    uint32_t status = 0;

    for (size_t i = n; i < token.size(); i++) {
        const std::string condition = token[i];

        if (eqtoken(condition, "Clamped")) {
            status |= MPD_Clamped;
        }
        else if (eqtoken(condition, "Conversion_syntax")) {
            status |= MPD_Conversion_syntax;
        }
        else if (eqtoken(condition, "Division_by_zero")) {
            status |= MPD_Division_by_zero;
        }
        else if (eqtoken(condition, "Division_impossible")) {
            status |= MPD_Division_impossible;
        }
        else if (eqtoken(condition, "Division_undefined")) {
            status |= MPD_Division_undefined;
        }
        else if (eqtoken(condition, "Fpu_error")) {
            status |= MPD_Fpu_error;
        }
        else if (eqtoken(condition, "Inexact")) {
            status |= MPD_Inexact;
        }
        else if (eqtoken(condition, "Invalid_context")) {
            status |= MPD_Invalid_context;
        }
        else if (eqtoken(condition, "Invalid_operation")) {
            status |= MPD_Invalid_operation;
        }
        else if (eqtoken(condition, "Malloc_error")) {
            status |= MPD_Malloc_error;
        }
        else if (eqtoken(condition, "Not_implemented")) {
            status |= MPD_Not_implemented;
        }
        else if (eqtoken(condition, "Overflow")) {
            status |= MPD_Overflow;
        }
        else if (eqtoken(condition, "Rounded")) {
            status |= MPD_Rounded;
        }
        else if (eqtoken(condition, "Subnormal")) {
            status |= MPD_Subnormal;
        }
        else if (eqtoken(condition, "Underflow")) {
            status |= MPD_Underflow;
        }
        else {
            err_token(token, "scan_conditions: unknown status");
        }
    }

    return status;
}

static void
compare_expected(const std::vector<std::string>& token,
                 const std::string& calc,
                 const std::string& expected,
                 uint32_t expected_status,
                 const Context& ctx)
{
    const std::string id = token.at(0);

    /* known ULP diffs */
    if (ctx.allcr() == 0) {
        for (const auto& c : ulp_cases) {
            if (id == c.id && expected == c.expected && calc == c.calc) {
                return;
            }
        }
    }

    /* known status diffs */
    for (const auto& c : status_cases) {
        if (id == c.id && expected_status == c.expected && ctx.status() == c.calc) {
            return;
        }
    }

    if (calc != expected) {
        err_token(token, "calc: ", calc, " expected: ", expected);
    }

    if (ctx.status() != expected_status) {
        char ctxstatus[MPD_MAX_FLAG_STRING];
        char expstatus[MPD_MAX_FLAG_STRING];

        mpd_snprint_flags(ctxstatus, MPD_MAX_FLAG_STRING, ctx.status());
        mpd_snprint_flags(expstatus, MPD_MAX_FLAG_STRING, expected_status);

        err_token(token, "calc: [", ctxstatus, "] expected: [",  expstatus, "]");
    }
}

static bool
equalmem(const Decimal& x, const Decimal& y)
{
    const mpd_t *a = x.getconst();
    const mpd_t *b = y.getconst();

    if ((a->flags & ~MPD_DATAFLAGS) != (b->flags & ~MPD_DATAFLAGS) ||
        a->exp != b->exp ||
        a->len != b->len ||
        a->digits != b->digits) {
        return false;
    }

    for (mpd_ssize_t i = 0; i < a->len; i++) {
        if (a->data[i] != b->data[i]) {
            return false;
        }
    }

    return true;
}

static void
check_equalmem(const std::vector<std::string>& token, const Decimal& a, const Decimal& b)
{
    if (!equalmem(a, b)) {
        err_token(token, "const arg changed");
    }
}

static unsigned long
get_testno(const std::vector<std::string>& token)
{
    const char *number = strpbrk(token.at(0).c_str(), "0123456789");
    if (number == nullptr) {
        err_token(token, "invalid test id: ", token.at(0));
    }
    return strtoul(number, nullptr, 10);
}

/* scan a single operand and the expected result */
static size_t
scan_op_expected(Decimal& op,
                 std::string& expected,
                 const std::vector<std::string>& token,
                 Context& ctx)
{
    op = Decimal(token.at(2), ctx);
    if (token.at(3) != "->") {
        err_token(token, "expected '->' token");
    }
    expected = token.at(4);

    return 5;
}

/* scan decimal operand, string operand and the expected result */
static size_t
scan_op_string_expected(Decimal& op1,
                        std::string& op2,
                        std::string& result,
                        const std::vector<std::string>& token,
                        Context& ctx)
{
    op1 = Decimal(token.at(2), ctx);
    op2 = token.at(3);
    if (token.at(4) != "->") {
        err_token(token, "expected '->' token");
    }
    result = token.at(5);

    return 6;
}

/* scan two operands and the expected result */
static size_t
scan_op_op_expected(Decimal& op1,
                    Decimal& op2,
                    std::string& result,
                    const std::vector<std::string>& token,
                    Context& ctx)
{
    op1 = Decimal(token.at(2), ctx);
    op2 = Decimal(token.at(3), ctx);
    if (token.at(4) != "->") {
        err_token(token, "expected '->' token");
    }
    result = token.at(5);

    return 6;
}

/* scan one operands and two results */
static size_t
scan_op_expected_expected(Decimal& op1,
                          std::string& result1,
                          std::string& result2,
                          const std::vector<std::string>& token,
                          Context& ctx)
{
    op1 = Decimal(token.at(2), ctx);
    if (token.at(3) != "->") {
        err_token(token, "expected '->' token");
    }
    result1 = token.at(4);
    result2 = token.at(5);

    return 6;
}

/* scan two operands and two results */
static size_t
scan_op_op_expected_expected(Decimal& op1,
                             Decimal& op2,
                             std::string& result1,
                             std::string& result2,
                             const std::vector<std::string>& token,
                             Context& ctx)
{
    op1 = Decimal(token.at(2), ctx);
    op2 = Decimal(token.at(3), ctx);
    if (token.at(4) != "->") {
        err_token(token, "expected '->' token");
    }
    result1 = token.at(5);
    result2 = token.at(6);

    return 7;
}

/* scan three operands and the expected result */
static size_t
scan_op_op_op_expected(Decimal& op1,
                       Decimal& op2,
                       Decimal& op3,
                       std::string& result,
                       const std::vector<std::string>& token,
                       Context& ctx)
{
    op1 = Decimal(token.at(2), ctx);
    op2 = Decimal(token.at(3), ctx);
    op3 = Decimal(token.at(4), ctx);
    if (token.at(5) != "->") {
        err_token(token, "expected '->' token");
    }
    result = token.at(6);

    return 7;
}

/* Triple tests */
static void
Triple(const std::vector<std::string>& token, const Decimal &dec, Context &ctx)
{
#ifdef MPD_CONFIG_32
    /*
     * 32-bit: as_triple() expects well-formed decimals. Skip test cases
     * that use the extended exponent, which is safe in the tests but not
     * in production.
     */
    if (!dec.isspecial()) {
        if (dec.exponent() < MPD_MIN_ETINY || dec.exponent() > MPD_MAX_EMAX) {
            return;
        }
    }
#endif

    mpd_uint128_triple_t triple = dec.as_uint128_triple();
    switch (triple.tag) {
    case MPD_TRIPLE_QNAN: case MPD_TRIPLE_SNAN:
        DECIMAL_ASSERT(triple.exp == 0, token);
        break;
    case MPD_TRIPLE_INF:
        DECIMAL_ASSERT(triple.hi == 0 && triple.lo == 0 && triple.exp == 0,
                       token);
        break;
    case MPD_TRIPLE_NORMAL:
        break;
    case MPD_TRIPLE_ERROR:
        DECIMAL_ASSERT(triple.sign == 0 && triple.hi == 0 &&
                       triple.lo == 0 && triple.exp == 0,
                       token);
        return;
    }

    /* Allocation failures in Decimal(triple) */
    Decimal d = 10;
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {

        set_alloc_fail(ctx, n);
        try {
            d = Decimal(triple);
        }
        catch (MallocError&) {
            set_alloc(ctx);
            DECIMAL_ASSERT(d == 10, token);
            continue;
        }

        set_alloc(ctx);
        break;
    }

    check_equalmem(token, d, dec);
    DECIMAL_ASSERT(d.cmp_total(dec) == 0, token);
}

/*
 * This function is used for "toSci", "toEng" and "apply" and does not use
 * a maxcontext for the conversion of the operand.
 */
typedef std::string (Decimal::*String_DecimalContext)(bool) const;
static void
Str_DecCtx(String_DecimalContext func,
           const std::vector<std::string>& token,
           const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op;
    Decimal tmp;
    std::string expected;
    std::string expected_fail;
    std::string calc;

    Context& workctx = context;
    workctx.status(0);
    const size_t i = scan_op_expected(op, expected, token, workctx);
    const uint32_t expstatus = scan_conditions(token, i);
    if (expstatus != workctx.status()) {
        err_token(token, "op: ", op, " expstatus: ", expstatus, " got: ", workctx.status());
    }
    Triple(token, op, workctx);

    /* Allocation failures for Decimal() */
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp);
        const Decimal save_tmp = tmp;

        workctx.status(0);
        set_alloc_fail(workctx, n);
        try {
            (void)scan_op_expected(tmp, expected_fail, token, workctx);
        }
        catch (MallocError&) {
            set_alloc(workctx);
            check_equalmem(token, tmp, save_tmp);
            continue;
        }

        set_alloc(workctx);
        break;
    }
    /* internal sanity checks */
    DECIMAL_ASSERT(expected == expected_fail, token);
    DECIMAL_ASSERT(tmp.cmp_total(op) == 0, token);

    /* make a copy of the operand */
    mpd_init_rand(tmp);
    tmp = op;

    workctx.status(0);
    calc = (tmp.*func)(true);

    /* compare the calculated result with the expected result */
    compare_expected(token, calc, expected, 0, workctx);
    check_equalmem(token, tmp, op);

    /* Allocation failures */
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp);
        tmp = op;

        workctx.status(0);
        set_alloc_fail(workctx, n);
        try {
            calc = (tmp.*func)(true);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, tmp, op);
            continue;
        }

        set_alloc(workctx);
        break;
    }

    compare_expected(token, calc, expected, 0, workctx);
    check_equalmem(token, tmp, op);
}

#ifdef __INTEL_COMPILER
  #pragma warning(disable : 186)
#endif
/* Quick and dirty: parse hex escape sequences */
static std::string
parse_escapes_backslash(const char *s)
{
    char hex[5];
    char *result, *cp;
    unsigned int u;
    unsigned char b;
    int n;

    std::shared_ptr<char> ptr(new char[strlen(s)+1], std::default_delete<char[]>());
    cp = result = ptr.get();

    hex[0] = '0';
    hex[1] = '\0';
    while (*s) {
        if (*s == '\\' && *(s+1) == 'x') {
            for (n = 1; n < 4; n++) {
                if (!s[n]) {
                    err_raise("parse hex escapes: invalid escape sequence");
                }
                hex[n] = s[n];
            }
            hex[n] = '\0';
            sscanf(hex, "%x%n", &u, &n);
            b = safe_downcast<unsigned char, unsigned int>(u);
            *cp++ = static_cast<char>(b);
            s += n;
        }
        else {
            *cp++ = *s++;
        }
    }

    *cp = '\0';
    return std::string(result);
}

static std::string
parse_escapes_hexstring(const char *s)
{
    const std::string hex{s};
    const size_t len = hex.size();
    std::vector<char> bytes;

    if (len % 2 != 0) {
        err_raise("parse hex escapes: invalid escape sequence");
    }

    for (size_t i = 0; i < len; i += 2) {
        std::string twodigits = hex.substr(i, 2);
        const unsigned long ul = strtoul(twodigits.c_str(), nullptr, 16);
        const unsigned char b = safe_downcast<unsigned char, unsigned long>(ul);
        bytes.push_back(static_cast<char>(b));
    }

    return std::string(bytes.data(), bytes.size());
}

static std::string
parse_escapes(const char *s)
{
    if (startswith(s, "HEX")) {
        return parse_escapes_hexstring(s+3);
    }
    else {
        return parse_escapes_backslash(s);
    }
}

/* This function is used for Decimal::format. */
static void
Fmt(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op, tmp;
    std::string fmt, expected;
    std::string calc;

    const size_t i = scan_op_string_expected(op, fmt, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, i);
    Triple(token, op, maxcontext);

    fmt = parse_escapes(fmt.c_str());
    expected = parse_escapes(expected.c_str());

    mpd_init_rand(tmp);
    tmp = op;

    context.status(0);
    try {
        calc = tmp.format(fmt);
    }
    catch (ValueError&) {
        DECIMAL_ASSERT(expstatus == MPD_Invalid_operation, token);
        DECIMAL_ASSERT(context.status() == 0, token);
        check_equalmem(token, tmp, op);
    #ifdef __mips__
        return;
    #endif
    }

    DECIMAL_ASSERT(expstatus == 0 || expstatus == MPD_Invalid_operation, token);
    if (expstatus == 0) {
        compare_expected(token, calc, expected, expstatus, context);
        check_equalmem(token, tmp, op);
    }

    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp);
        tmp = op;

        context.status(0);
        set_alloc_fail(context, n);
        try {
            calc = tmp.format(fmt);
        }
        catch (MallocError&) {
            set_alloc(context);
            continue;
        }
    #ifndef __mips__ /* miscompilation */
        catch (ValueError&) {
            DECIMAL_ASSERT(expstatus == MPD_Invalid_operation, token);
            DECIMAL_ASSERT(context.status() == 0, token);
        }
    #endif

        set_alloc(context);
        break;
    }

    DECIMAL_ASSERT(expstatus == 0 || expstatus == MPD_Invalid_operation, token);
    if (expstatus == 0) {
        compare_expected(token, calc, expected, expstatus, context);
        check_equalmem(token, tmp, op);
    }
}

/* test number class */
static void
Class(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op, tmp;
    std::string expected;

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    mpd_init_rand(tmp);
    tmp = op;

    context.status(0);
    std::string calc = tmp.number_class(context);
    compare_expected(token, calc, expected, expstatus, context);
    check_equalmem(token, tmp, op);
}

/* test a unary function */
typedef Decimal (Decimal::*Decimal_Decimal)() const;

static void
Dec_Dec_RunSingle(Decimal& result, Decimal& tmp,
                  const std::vector<std::string>& token,
                  const Decimal_Decimal func,
                  const Decimal& op,
                  const std::string& expected,
                  const uint32_t expstatus)
{
    uint64_t incr = 1;
    for (uint64_t n = 1; n < UINT64_MAX-100; n += incr) {
        mpd_init_rand(result);
        mpd_init_rand(tmp);
        tmp = op;

        const Decimal save_result = result;
        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp.*func)();
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result, save_result);
            check_equalmem(token, tmp, op);
            if (n > 50) {
                incr = rnd() % 100 + 1;
            }
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
    if (&tmp != &result) {
        check_equalmem(token, tmp, op);
    }
}

static void
Dec_Dec(Decimal_Decimal func,
        const std::vector<std::string>& token,
        const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op, result, tmp;
    std::string expected;

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    Dec_Dec_RunSingle(result, tmp, token, func, op, expected, expstatus);
    Dec_Dec_RunSingle(tmp, tmp, token, func, op, expected, expstatus);
}

/* test a unary function with an optional context argument */
typedef Decimal (Decimal::*Decimal_DecimalContext)(Context&) const;

static void
Dec_DecCtx_RunSingle(Decimal& result, Decimal& tmp,
                     const std::vector<std::string>& token,
                     const Decimal_DecimalContext func,
                     const Decimal& op,
                     const std::string& expected,
                     const uint32_t expstatus)
{
    uint64_t incr = 1;
    for (uint64_t n = 1; n < UINT64_MAX-100; n += incr) {
        mpd_init_rand(result);
        mpd_init_rand(tmp);
        tmp = op;

        const Decimal save_result = result;
        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp.*func)(context);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result, save_result);
            check_equalmem(token, tmp, op);
            if (n > 50) {
                incr = rnd() % 100 + 1;
            }
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
    if (&tmp != &result) {
        check_equalmem(token, tmp, op);
    }
}

static void
Dec_DecCtx(Decimal_DecimalContext func,
           const std::vector<std::string>& token,
           const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op, result, tmp;
    std::string expected;

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    Dec_DecCtx_RunSingle(result, tmp, token, func, op, expected, expstatus);
    Dec_DecCtx_RunSingle(tmp, tmp, token, func, op, expected, expstatus);
}

/* Same as Dec_DecCtx, but quantize the operand before applying the actual function */
static void
Dec_DecCtxWithQuantize(Decimal_DecimalContext func,
                       const std::vector<std::string>& token,
                       const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op, scale, result, tmp;
    std::string expected;

    const size_t n = scan_op_op_expected(op, scale, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);
    Triple(token, scale, maxcontext);

    op = op.quantize(scale, maxcontext);

    Dec_DecCtx_RunSingle(result, tmp, token, func, op, expected, expstatus);
    Dec_DecCtx_RunSingle(tmp, tmp, token, func, op, expected, expstatus);
}

/* Test a binary function */
typedef Decimal (Decimal::*Decimal_DecimalDecimalContext)(const Decimal&, Context&) const;

static void
resolve_status_hack(uint32_t& expstatus, const uint32_t status)
{
    /* hack #1 to resolve disagreement with results generated by decimal.py */
    if ((expstatus & MPD_Invalid_operation) &&
        (status & MPD_Division_impossible)) {
        expstatus = MPD_Division_impossible;
    }

    /* hack #2 to resolve disagreement with results generated by decimal.py */
    if ((expstatus & MPD_Invalid_operation) &&
        (status & MPD_Division_undefined)) {
        expstatus = MPD_Division_undefined;
    }
}

static void
Dec_DecDecCtx_RunSingle(Decimal& result, Decimal& tmp1, Decimal& tmp2,
                        const std::vector<std::string>& token,
                        const Decimal_DecimalDecimalContext func,
                        const Decimal& op1, const Decimal &op2,
                        const std::string& expected,
                        const uint32_t expstatus)
{
    uint64_t incr = 1;
    for (uint64_t n = 1; n < UINT64_MAX-100; n += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        tmp1 = op1;
        tmp2 = op2;

        const Decimal save_result = result;
        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp1.*func)(tmp2, context);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result, save_result);
            check_equalmem(token, tmp1, op1);
            check_equalmem(token, tmp2, op2);
            if (n > 50) {
               incr = rnd() % 100 + 1;
            }
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
    if (&tmp1 != &result) {
        check_equalmem(token, tmp1, op1);
    }
    if (&tmp2 != &result) {
        check_equalmem(token, tmp2, op2);
    }
}

static void
Dec_DecDecCtx(const Decimal_DecimalDecimalContext func,
              const std::vector<std::string>& token,
              const bool scan_equal,
              const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal result, tmp1, tmp2;
    Decimal op1, op2;
    std::string expected;
    uint32_t expstatus;
    size_t n;

    if (scan_equal) {
        n = scan_op_expected(op1, expected, token, maxcontext);
        op2 = op1;
    }
    else {
        n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
    }
    expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);

    context.status(0);
    result = (op1.*func)(op2, context);

    Dec_DecDecCtx_RunSingle(result, tmp1, tmp2, token, func, op1, op2, expected, expstatus);
    Dec_DecDecCtx_RunSingle(tmp1, tmp1, tmp2, token, func, op1, op2, expected, expstatus);
    Dec_DecDecCtx_RunSingle(tmp2, tmp1, tmp2, token, func, op1, op2, expected, expstatus);

    if (equalmem(op1, op2)) {
        Dec_DecDecCtx_RunSingle(result, tmp1, tmp1, token, func, op1, op2, expected, expstatus);
        Dec_DecDecCtx_RunSingle(tmp1, tmp1, tmp1, token, func, op1, op2, expected, expstatus);
    }
}

/* Test a binary function with a binary result */
typedef std::pair<Decimal, Decimal> (Decimal::*DecimalPair_DecimalDecimalContext)(const Decimal&, Context&) const;

static void
DecPair_DecDecCtx_RunSingle(std::pair<Decimal, Decimal>& result, Decimal& tmp1, Decimal& tmp2,
                            const std::vector<std::string>& token,
                            const DecimalPair_DecimalDecimalContext func,
                            const Decimal& op1, const Decimal &op2,
                            const std::string& expected1, const std::string& expected2,
                            const uint32_t expstatus)
{
    uint64_t incr = 1;
    for (uint64_t n = 1; n < UINT64_MAX-100; n += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        tmp1 = op1;
        tmp2 = op2;
        const Decimal first = result.first;
        const Decimal second = result.second;

        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp1.*func)(tmp2, context);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result.first, first);
            check_equalmem(token, result.second, second);
            check_equalmem(token, tmp1, op1);
            check_equalmem(token, tmp2, op2);
            if (n > 50) {
                incr = rnd() % 100 + 1;
            }
            continue;
        }

        set_alloc(context);
        break;
    }

    std::string calc = result.first.to_sci();
    compare_expected(token, calc, expected1, expstatus, context);

    calc = result.second.to_sci();
    compare_expected(token, calc, expected2, expstatus, context);

    if (&tmp1 != &result.first && &tmp1 != &result.second) {
        check_equalmem(token, tmp1, op1);
    }
    if (&tmp2 != &result.first && &tmp2 != &result.second) {
        check_equalmem(token, tmp2, op2);
    }
}

static void
DecPair_DecDecCtx(const DecimalPair_DecimalDecimalContext func,
                  const std::vector<std::string>& token,
                  const bool scan_equal,
                  const bool extended)
{
    Context maxcontext{readcontext(extended)};
    std::pair<Decimal, Decimal> result;
    Decimal tmp1, tmp2;
    Decimal op1, op2;
    std::string expected1, expected2;
    uint32_t expstatus;
    size_t n;

    if (scan_equal) {
        n = scan_op_expected_expected(op1, expected1, expected2,
                                      token, maxcontext);
        op2 = op1;
    }
    else {
        n = scan_op_op_expected_expected(op1, op2, expected1, expected2,
                                         token, maxcontext);
    }
    expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);

    context.status(0);
    result = (op1.*func)(op2, context);
    resolve_status_hack(expstatus, context.status());

    DecPair_DecDecCtx_RunSingle(result, tmp1, tmp2, token, func, op1, op2, expected1, expected2, expstatus);
    DecPair_DecDecCtx_RunSingle(result, result.first, tmp2, token, func, op1, op2, expected1, expected2, expstatus);
    DecPair_DecDecCtx_RunSingle(result, tmp1, result.first, token, func, op1, op2, expected1, expected2, expstatus);
    DecPair_DecDecCtx_RunSingle(result, result.second, tmp2, token, func, op1, op2, expected1, expected2, expstatus);
    DecPair_DecDecCtx_RunSingle(result, tmp1, result.second, token, func, op1, op2, expected1, expected2, expstatus);

    if (equalmem(op1, op2)) {
        DecPair_DecDecCtx_RunSingle(result, tmp1, tmp1, token, func, op1, op2, expected1, expected2, expstatus);
        DecPair_DecDecCtx_RunSingle(result, result.first, result.first, token, func, op1, op2, expected1, expected2, expstatus);
        DecPair_DecDecCtx_RunSingle(result, result.second, result.second, token, func, op1, op2, expected1, expected2, expstatus);
    }
}

/* Test a ternary function */
typedef Decimal (Decimal::*Decimal_DecimalDecimalDecimalContext)(const Decimal&, const Decimal&, Context&) const;

static void
Dec_DecDecDecCtx_RunSingle(Decimal& result, Decimal& tmp1, Decimal& tmp2, Decimal& tmp3,
                           const std::vector<std::string>& token,
                           const Decimal_DecimalDecimalDecimalContext func,
                           const Decimal& op1, const Decimal &op2, const Decimal &op3,
                           const std::string& expected,
                           const uint32_t expstatus)
{
    uint64_t incr = 1;
    for (uint64_t n = 1; n < UINT64_MAX-100; n += incr) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        mpd_init_rand(tmp3);
        tmp1 = op1;
        tmp2 = op2;
        tmp3 = op3;

        const Decimal save_result = result;
        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp1.*func)(tmp2, tmp3, context);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result, save_result);
            check_equalmem(token, tmp1, op1);
            check_equalmem(token, tmp2, op2);
            check_equalmem(token, tmp3, op3);
            if (n > 100) {
                incr = rnd() % 100 + 1;
            }
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
    if (&tmp1 != &result) {
        check_equalmem(token, tmp1, op1);
    }
    if (&tmp2 != &result) {
        check_equalmem(token, tmp2, op2);
    }
    if (&tmp3 != &result) {
        check_equalmem(token, tmp3, op3);
    }
}

enum ternary_equal { OpOpOp, EqEqOp, EqOpEq, OpEqEq, EqEqEq };
static void
Dec_DecDecDecCtx(const Decimal_DecimalDecimalDecimalContext func,
                 enum ternary_equal scan_equal,
                 const std::vector<std::string>& token,
                 const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal result, tmp1, tmp2, tmp3;
    Decimal op1, op2, op3;
    std::string expected;
    uint32_t expstatus;
    size_t n;

    switch (scan_equal) {
    case OpOpOp:
        n = scan_op_op_op_expected(op1, op2, op3, expected, token, maxcontext);
        break;
    case EqEqOp:
        n = scan_op_op_expected(op1, op3, expected, token, maxcontext);
        op2 = op1;
        break;
    case EqOpEq:
        n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
        op3 = op1;
        break;
    case OpEqEq:
        n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
        op3 = op2;
        break;
    case EqEqEq:
        n = scan_op_expected(op1, expected, token, maxcontext);
        op3 = op2 = op1;
        break;
    default:
        err_raise("internal error: unexpected tag");
        break;
    }
    expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);
    Triple(token, op3, maxcontext);

    Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp2, tmp3, token, func, op1, op2, op3, expected, expstatus);
    Dec_DecDecDecCtx_RunSingle(result, result, tmp2, tmp3, token, func, op1, op2, op3, expected, expstatus);
    Dec_DecDecDecCtx_RunSingle(result, tmp1, result, tmp3, token, func, op1, op2, op3, expected, expstatus);
    Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp2, result, token, func, op1, op2, op3, expected, expstatus);

    if (equalmem(op1, op2)) {
        Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp1, tmp3, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, result, result, tmp3, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp1, result, token, func, op1, op2, op3, expected, expstatus);
    }

    if (equalmem(op1, op3)) {
        Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp2, tmp1, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, result, tmp2, result, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, tmp1, result, tmp1, token, func, op1, op2, op3, expected, expstatus);
    }

    if (equalmem(op2, op3)) {
        Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp2, tmp2, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, result, tmp2, tmp2, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, tmp1, result, result, token, func, op1, op2, op3, expected, expstatus);
    }

    if (equalmem(op1, op2) && equalmem(op1, op3)) {
        Dec_DecDecDecCtx_RunSingle(result, tmp1, tmp1, tmp1, token, func, op1, op2, op3, expected, expstatus);
        Dec_DecDecDecCtx_RunSingle(result, result, result, result, token, func, op1, op2, op3, expected, expstatus);
    }
}

/* Test a binary function with no context argument */
typedef Decimal (Decimal::*Decimal_DecimalDecimal)(const Decimal&) const;

static void
Dec_DecDec_RunSingle(Decimal& result, Decimal& tmp1, Decimal& tmp2,
                     const std::vector<std::string>& token,
                     const Decimal_DecimalDecimal func,
                     const Decimal& op1, const Decimal &op2,
                     const std::string& expected,
                     const uint32_t expstatus)
{
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        tmp1 = op1;
        tmp2 = op2;

        const Decimal save_result = result;
        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp1.*func)(tmp2);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result, save_result);
            check_equalmem(token, tmp1, op1);
            check_equalmem(token, tmp2, op2);
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
    if (&tmp1 != &result) {
        check_equalmem(token, tmp1, op1);
    }
    if (&tmp2 != &result) {
        check_equalmem(token, tmp2, op2);
    }
}

static void
Dec_DecDec(const Decimal_DecimalDecimal func,
           const std::vector<std::string>& token,
           const bool scan_equal,
           const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal result, tmp1, tmp2;
    Decimal op1, op2;
    std::string expected;
    uint32_t expstatus;
    size_t n;

    if (scan_equal) {
        n = scan_op_expected(op1, expected, token, maxcontext);
        op2 = op1;
    }
    else {
        n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
    }
    expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);

    Dec_DecDec_RunSingle(result, tmp1, tmp2, token, func, op1, op2, expected, expstatus);
    Dec_DecDec_RunSingle(tmp1, tmp1, tmp2, token, func, op1, op2, expected, expstatus);
    Dec_DecDec_RunSingle(tmp2, tmp1, tmp2, token, func, op1, op2, expected, expstatus);

    if (equalmem(op1, op2)) {
        Dec_DecDec_RunSingle(result, tmp1, tmp1, token, func, op1, op2, expected, expstatus);
        Dec_DecDec_RunSingle(tmp1, tmp1, tmp1, token, func, op1, op2, expected, expstatus);
    }
}

/* Test a binary function that returns an integer result */
typedef int (Decimal::*Int_DecimalDecimal)(const Decimal&) const;

static void
Int_DecDec_RunSingle(Decimal& tmp1, Decimal& tmp2,
                     const enum skip_cmp skip,
                     const std::vector<std::string>& token,
                     const Int_DecimalDecimal func,
                     const Decimal& op1, const Decimal &op2,
                     const std::string& expected,
                     const uint32_t expstatus)
{
    int int_result = -101;

    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        tmp1 = op1;
        tmp2 = op2;

        context.status(0);
        set_alloc_fail(context, n);
        try {
            int_result = (tmp1.*func)(tmp2);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, tmp1, op1);
            check_equalmem(token, tmp2, op2);
            continue;
        }

        set_alloc(context);
        break;
    }

    char buf[11];
    snprintf(buf, sizeof buf, "%d", int_result);
    if (skip == SKIP_NONE || int_result != INT_MAX) {
        compare_expected(token, buf, expected, expstatus, context);
    }
    check_equalmem(token, tmp1, op1);
    check_equalmem(token, tmp2, op2);
}

static void
Int_DecDec(const Int_DecimalDecimal func,
           const std::vector<std::string>& token,
           const enum skip_cmp skip,
           const bool scan_equal,
           const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal tmp1, tmp2;
    Decimal op1, op2;
    std::string expected;
    uint32_t expstatus;
    size_t n;

    if (scan_equal) {
        n = scan_op_expected(op1, expected, token, maxcontext);
        op2 = op1;
    }
    else {
        n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
    }
    expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);

    Int_DecDec_RunSingle(tmp1, tmp2, skip, token, func, op1, op2, expected, expstatus);
    if (equalmem(op1, op2)) {
        Int_DecDec_RunSingle(tmp1, tmp1, skip, token, func, op1, op2, expected, expstatus);
    }
}

/* Test a binary function that returns a bool result */
typedef bool (Decimal::*Bool_DecimalDecimal)(const Decimal&) const;

static void
Bool_DecDec_RunSingle(Decimal& tmp1, Decimal& tmp2,
                      const enum skip_cmp skip,
                      const std::vector<std::string>& token,
                      const Bool_DecimalDecimal func,
                      const Decimal& op1, const Decimal &op2,
                      const std::string& expected,
                      const uint32_t expstatus)
{
    int int_result = -101;

    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp1);
        mpd_init_rand(tmp2);
        tmp1 = op1;
        tmp2 = op2;

        context.status(0);
        set_alloc_fail(context, n);
        try {
            int_result = (tmp1.*func)(tmp2);
        }
        catch (MallocError&) {
            set_alloc(context);
            DECIMAL_ASSERT(int_result== INT_MAX, token);
            check_equalmem(token, tmp1, op1);
            check_equalmem(token, tmp2, op2);
            continue;
        }

        set_alloc(context);
        break;
    }

    char buf[11];
    snprintf(buf, 11, "%d", int_result);
    if (skip == SKIP_NONE || int_result != INT_MAX) {
        compare_expected(token, buf, expected, expstatus, context);
    }
    check_equalmem(token, tmp1, op1);
    check_equalmem(token, tmp2, op2);
}

static void
Bool_DecDec(const Bool_DecimalDecimal func,
            const std::vector<std::string>& token,
            const enum skip_cmp skip,
            const bool scan_equal,
            const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal tmp1, tmp2;
    Decimal op1, op2;
    std::string expected;
    uint32_t expstatus;
    size_t n;

    if (scan_equal) {
        n = scan_op_expected(op1, expected, token, maxcontext);
        op2 = op1;
    }
    else {
        n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
    }
    expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);

    Bool_DecDec_RunSingle(tmp1, tmp2, skip, token, func, op1, op2, expected, expstatus);
    if (equalmem(op1, op2)) {
        Bool_DecDec_RunSingle(tmp1, tmp1, skip, token, func, op1, op2, expected, expstatus);
    }
}

static mpd_ssize_t
scan_ssize(const std::string& tok)
{
    errno = 0;
    mpd_ssize_t x = strtossize(tok.c_str(), nullptr, 10);
    if (errno != 0) {
        err_raise("invalid conversion to ssize_t");
    }
    return x;
}

/* Test a function with a Decimal and an int64_t operand */
typedef Decimal (Decimal::*Decimal_DecimalInt64Context)(int64_t, Context&) const;

static void
Dec_DecInt64_RunSingle(Decimal& result, Decimal& tmp,
                       const std::vector<std::string>& token,
                       const Decimal_DecimalInt64Context func,
                       const Decimal& op,
                       const int64_t i64,
                       const std::string& expected,
                       const uint32_t expstatus)
{
    /* Allocation failures */
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {
        mpd_init_rand(tmp);
        tmp = op;

        context.status(0);
        set_alloc_fail(context, n);
        try {
            result = (tmp.*func)(i64, context);
        }
        catch (MallocError&) {
            check_equalmem(token, tmp, op);
            set_alloc(context);
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
    if (&tmp != &result) {
        check_equalmem(token, tmp, op);
    }
}

static void
Dec_DecInt64Ctx(const Decimal_DecimalInt64Context func,
                const std::vector<std::string>& token,
                const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal result, tmp;
    Decimal op1, op2;
    std::string expected;

    const size_t n = scan_op_op_expected(op1, op2, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op1, maxcontext);
    Triple(token, op2, maxcontext);

    if (op2.isspecial() || op2.exponent() != 0) {
        return;
    }

    const int64_t i64 = mpd_get_ssize(op2.getconst(), maxcontext.get());
    if (maxcontext.status() & MPD_Invalid_operation) {
        return;
    }

    Dec_DecInt64_RunSingle(result, tmp, token, func, op1, i64, expected, expstatus);
    Dec_DecInt64_RunSingle(tmp, tmp, token, func, op1, i64, expected, expstatus);
}

/* Test decimal::ln10 */
static void
ln10(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal result;
    Decimal op;
    std::string expected;

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    if (op.isspecial() || op.exponent() != 0) {
        return;
    }

    const int64_t i64 = mpd_get_ssize(op.getconst(), maxcontext.get());
    if (maxcontext.status() & MPD_Invalid_operation) {
        return;
    }

    for (uint64_t i = 1; i < UINT64_MAX-1; i++) {
        const Decimal save_result = result;

        context.status(0);
        set_alloc_fail(context, i);
        try {
            result = Decimal::ln10(i64, context);
        }
        catch (MallocError&) {
            set_alloc(context);
            check_equalmem(token, result, save_result);
            continue;
        }

        set_alloc(context);
        break;
    }

    const std::string calc = result.to_sci();
    compare_expected(token, calc, expected, expstatus, context);
}

/* Test u64() */
static void
u64_DecCtx(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op;
    uint64_t u64;
    char calc[23];
    std::string expected;

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    context.status(0);
    try {
        u64 = op.u64();
    }
    catch (ValueError&) {
        DECIMAL_ASSERT(expstatus == MPD_Invalid_operation, token);
        return;
    }

    snprintf(calc, 23, "%" PRIu64, u64);
    compare_expected(token, calc, expected, expstatus, context);
}

/* Test u32() */
static void
u32_DecCtx(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op;
    std::string expected;
    uint32_t u32;
    char calc[23];

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    context.status(0);
    try {
        u32 = op.u32();
    }
    catch (ValueError&) {
        DECIMAL_ASSERT(expstatus == MPD_Invalid_operation, token);
        return;
    }

    snprintf(calc, sizeof calc, "%" PRIu32, u32);
    compare_expected(token, calc, expected, 0, context);
}

/* Test a function returning an int64_t */
static void
i64_DecCtx(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op;
    std::string expected;
    int64_t i64;
    char calc[23];

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    context.status(0);
    try {
        i64 = op.i64();
    }
    catch (ValueError&) {
        DECIMAL_ASSERT(expstatus == MPD_Invalid_operation, token);
        return;
    }

    snprintf(calc, sizeof calc, "%" PRIi64, i64);
    compare_expected(token, calc, expected, 0, context);
}

/* Test a function returning an int64_t */
static void
i32_DecCtx(const std::vector<std::string>& token, const bool extended)
{
    Context maxcontext{readcontext(extended)};
    Decimal op;
    std::string expected;
    int32_t i32;
    char calc[23];

    const size_t n = scan_op_expected(op, expected, token, maxcontext);
    const uint32_t expstatus = scan_conditions(token, n);
    Triple(token, op, maxcontext);

    context.status(0);
    try {
        i32 = op.i32();
    }
    catch (ValueError&) {
        DECIMAL_ASSERT(expstatus == MPD_Invalid_operation, token);
        return;
    }

    snprintf(calc, sizeof calc, "%" PRIi32, i32);
    compare_expected(token, calc, expected, 0, context);
}

static void
test_copy_constructor(void)
{
    const std::vector<std::string> token{"copy_constr"};
    Decimal a = Decimal(1).shiftl((decimal::MINALLOC*MPD_RDIGITS));
    Decimal b = Decimal(1).shiftl((2*decimal::MINALLOC*MPD_RDIGITS));
    Decimal c = 2025;
    Context ctx;

    /* static ==> dynamic */
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {

        set_alloc_fail(ctx, n);
        try {
            c = a;
        }
        catch (MallocError&) {
            set_alloc(ctx);
            DECIMAL_ASSERT(c == 2025, token);
            continue;
        }

        set_alloc(ctx);
        break;
    }

    DECIMAL_ASSERT(c == a, token);

    /* static ==> larger dynamic */
    for (uint64_t n = 1; n < UINT64_MAX-1; n++) {

        set_alloc_fail(ctx, n);
        try {
            c = b;
        }
        catch (MallocError&) {
            set_alloc(ctx);
            DECIMAL_ASSERT(c == a, token);
            continue;
        }

        set_alloc(ctx);
        break;
    }

    DECIMAL_ASSERT(c == b, token);
}

/* process an input stream of test cases */
static bool skip_bignum = false;
static std::atomic<uint32_t> bignum_counter{0};

static void
do_stream(std::istream& in, bool extended=true)
{
    std::string line;

    context = Context(testcontext(extended));

    while (std::getline(in, line)) {
        std::vector<std::string> token = split(line);
        if (token.size() == 0) {
            continue;
        }

        if (skip_bignum) { /* small thread stack */
            bool cont = false;
            for (const std::string &s : token) {
                /* This is a simple heuristic, which works for the test cases
                   in additional.topTest. */
                if (s.size() > 4096) {
                    cont = true;
                    bignum_counter++;
                    break;
                }
            }
            if (cont) {
                continue;
            }
        }

        if (startswith(token.at(0), "ExtendedRange")) {
            if (token.at(1) == "1") {
                extended = true;
            }
            else if (token.at(1) == "0") {
                extended = false;
            }
            else {
                err_token(token, "value must be 1 or 0");
            }
            continue;
        }

        if (startswith(token.at(0), "Precision")) {
            if (token.at(1) == "MAX_PREC") {
                context.prec(MPD_MAX_PREC);
            }
            else {
                mpd_context_t ctx = *context.getconst();
                const mpd_ssize_t l = scan_ssize(token.at(1));
                ctx.prec = l;
                context = Context(ctx);
            }
            continue;
        }

        if (startswith(token.at(0), "MinExponent")) {
            if (token.at(1) == "MIN_EMIN") {
                context.emin(MPD_MIN_EMIN);
            }
            else {
                mpd_context_t ctx = *context.getconst();
                const mpd_ssize_t l = scan_ssize(token.at(1));
                ctx.emin = l;
                context = Context(ctx);
            }
            continue;
        }

        if (startswith(token.at(0), "MaxExponent")) {
            if (token.at(1) == "MAX_EMAX") {
                context.emax(MPD_MAX_EMAX);
            }
            else {
                mpd_context_t ctx = *context.getconst();
                const mpd_ssize_t l = scan_ssize(token.at(1));
                ctx.emax = l;
                context = Context(ctx);
            }
            continue;
        }

        if (startswith(token.at(0), "Rounding")) {
            if (eqtoken(token.at(1), "Up")) {
                context.round(MPD_ROUND_UP);
            }
            else if (eqtoken(token.at(1), "Down")) {
                context.round(MPD_ROUND_DOWN);
            }
            else if (eqtoken(token.at(1), "Ceiling")) {
                context.round(MPD_ROUND_CEILING);
            }
            else if (eqtoken(token.at(1), "Floor")) {
                context.round(MPD_ROUND_FLOOR);
            }
            else if (eqtoken(token.at(1), "Half_up")) {
                context.round(MPD_ROUND_HALF_UP);
            }
            else if (eqtoken(token.at(1), "Half_down")) {
                context.round(MPD_ROUND_HALF_DOWN);
            }
            else if (eqtoken(token.at(1), "Half_even")) {
                context.round(MPD_ROUND_HALF_EVEN);
            }
            else if (eqtoken(token.at(1), "05up")) {
                context.round(MPD_ROUND_05UP);
            }
            else {
                err_token(token, "invalid rounding mode");
            }

            continue;
        }

        if (startswith(token.at(0), "Clamp")) {
            const int l = static_cast<int>(scan_ssize(token.at(1)));
            context.clamp(l);
            continue;
        }

        if (startswith(token.at(0), "Locale")) {
            if (setlocale(LC_NUMERIC, token.at(1).c_str()) == nullptr) {
                err_token(token, "invalid or missing locale");
            }
            continue;
        }

        if (startswith(token.at(0), "Version")) {
            continue;  /* optional directive */
        }

        if (startswith(token.at(0), "Extended")) {
            continue;  /* optional directive */
        }

        mpd_assert_context_ok(context, token);

        /*
         * Actual tests start here:
         *   - token.at(0) is the id
         *   - token.at(1) is the operation type
         *   - testno can be used for setting a watchpoint in the debugger
         */
        const unsigned long testno = get_testno(token);
        (void)testno;

        if (skip_test(token.at(0))) {
            continue;  /* id is in the skip list */
        }

#ifdef MPD_CONFIG_64
        if (startswith(token.at(0), "cov32")) {
            continue;  /* skip 32-bit specific coverage tests */
        }
#else
        if (startswith(token.at(0), "cov64")) {
            continue;  /* skip 64-bit specific coverage tests */
        }
#endif

        if (startswith(token.at(0), "pwmx")) {
            token.at(1) = std::string("powmod");
        }

        /* Unary functions with std::string result */
        if (eqtoken(token.at(1), "tosci") || eqtoken(token.at(1), "apply")) {
            Str_DecCtx(&Decimal::to_sci, token, extended);
        }
        else if (eqtoken(token.at(1), "toeng")) {
            Str_DecCtx(&Decimal::to_eng, token, extended);
        }
        else if (eqtoken(token.at(1), "format")) {
            Fmt(token, extended);
        }

        /* Unary function with const char * result */
        else if (eqtoken(token.at(1), "class")) {
            Class(token, extended);
        }

        /* Unary functions with Decimal result */
        else if (eqtoken(token.at(1), "abs")) {
            Dec_DecCtx(&Decimal::abs, token, extended);
        }
        else if (eqtoken(token.at(1), "copy")) {
            Dec_Dec(&Decimal::copy, token, extended);
        }
        else if (eqtoken(token.at(1), "copyabs")) {
            Dec_Dec(&Decimal::copy_abs, token, extended);
        }
        else if (eqtoken(token.at(1), "copynegate")) {
            Dec_Dec(&Decimal::copy_negate, token, extended);
        }
        else if (eqtoken(token.at(1), "exp")) {
            if (extended) {
                if (testno != 126) {
                    /* Almost all test cases in the official tests are
                       correctly rounded even when context.allcr is not
                       set. */
                    context.allcr(0);
                    Dec_DecCtx(&Decimal::exp, token, extended);
                    context.allcr(1);
                }
            }
            Dec_DecCtx(&Decimal::exp, token, extended);
        }
        else if (eqtoken(token.at(1), "invert")) {
            Dec_DecCtx(&Decimal::logical_invert, token, extended);
        }
        else if (eqtoken(token.at(1), "invroot")) {
            Dec_DecCtx(&Decimal::invroot, token, extended);
        }
        else if (eqtoken(token.at(1), "ln")) {
            if (extended) {
                /* All test cases in the official tests are correctly rounded
                   even when context.allcr is not set. */
                context.allcr(0);
                Dec_DecCtx(&Decimal::ln, token, extended);
                context.allcr(1);
            }
            Dec_DecCtx(&Decimal::ln, token, extended);
        }
        else if (eqtoken(token.at(1), "log10")) {
            if (extended) {
                /* All test cases in the official tests are correctly rounded
                   even when context.allcr is not set. */
                context.allcr(0);
                Dec_DecCtx(&Decimal::log10, token, extended);
                context.allcr(1);
            }
            Dec_DecCtx(&Decimal::log10, token, extended);
        }
        else if (eqtoken(token.at(1), "logb")) {
            Dec_DecCtx(&Decimal::logb, token, extended);
        }
        else if (eqtoken(token.at(1), "minus")) {
            Dec_DecCtx(&Decimal::minus, token, extended);
        }
        else if (eqtoken(token.at(1), "nextminus")) {
            Dec_DecCtx(&Decimal::next_minus, token, extended);
        }
        else if (eqtoken(token.at(1), "nextplus")) {
            Dec_DecCtx(&Decimal::next_plus, token, extended);
        }
        else if (eqtoken(token.at(1), "plus")) {
            Dec_DecCtx(&Decimal::plus, token, extended);
        }
        else if (eqtoken(token.at(1), "reduce")) {
            Dec_DecCtx(&Decimal::reduce, token, extended);
        }
        else if (eqtoken(token.at(1), "squareroot")) {
            #ifdef MPD_CONFIG_32
                if (context.prec() == MPD_MAX_PREC) set_alloc_limit(16000000);
            #endif
            Dec_DecCtx(&Decimal::sqrt, token, extended);
            #ifdef MPD_CONFIG_32
                if (context.prec() == MPD_MAX_PREC) set_alloc_limit(SIZE_MAX);
            #endif
        }
        else if (eqtoken(token.at(1), "quantize_squareroot")) {
            #ifdef MPD_CONFIG_32
                if (context.prec() == MPD_MAX_PREC) set_alloc_limit(16000000);
            #endif
            Dec_DecCtxWithQuantize(&Decimal::sqrt, token, extended);
            #ifdef MPD_CONFIG_32
                if (context.prec() == MPD_MAX_PREC) set_alloc_limit(SIZE_MAX);
            #endif
        }
        else if (eqtoken(token.at(1), "tointegral")) {
            Dec_DecCtx(&Decimal::to_integral, token, extended);
        }
        else if (eqtoken(token.at(1), "tointegralx")) {
            Dec_DecCtx(&Decimal::to_integral_exact, token, extended);
        }
        else if (eqtoken(token.at(1), "floor")) {
            Dec_DecCtx(&Decimal::floor, token, extended);
        }
        else if (eqtoken(token.at(1), "ceil")) {
            Dec_DecCtx(&Decimal::ceil, token, extended);
        }
        else if (eqtoken(token.at(1), "trunc")) {
            Dec_DecCtx(&Decimal::trunc, token, extended);
        }

        /* Binary function returning an int */
        else if (eqtoken(token.at(1), "samequantum")) {
            Bool_DecDec(&Decimal::same_quantum, token, SKIP_NONE, false, extended);
        }

        /* Binary function returning an int, equal operands */
        else if (eqtoken(token.at(1), "samequantum_eq")) {
            Bool_DecDec(&Decimal::same_quantum, token, SKIP_NONE, true, extended);
        }

        /* Binary functions with Decimal result */
        else if (eqtoken(token.at(1), "add")) {
            Dec_DecDecCtx(&Decimal::add, token, false, extended);
            Dec_DecDec(&Decimal::operator+, token, false, extended);
        }
        else if (eqtoken(token.at(1), "and")) {
            Dec_DecDecCtx(&Decimal::logical_and, token, false, extended);
        }
        else if (eqtoken(token.at(1), "copysign")) {
            Dec_DecDec(&Decimal::copy_sign, token, false, extended);
        }
        else if (eqtoken(token.at(1), "divide")) {
            #ifdef MPD_CONFIG_32
                if (context.prec() == MPD_MAX_PREC) set_alloc_limit(16000000);
            #endif
            Dec_DecDecCtx(&Decimal::div, token, false, extended);
            Dec_DecDec(&Decimal::operator/, token, false, extended);
            #ifdef MPD_CONFIG_32
                if (context.prec() == MPD_MAX_PREC) set_alloc_limit(SIZE_MAX);
            #endif
        }
        else if (eqtoken(token.at(1), "divideint")) {
            Dec_DecDecCtx(&Decimal::divint, token, false, extended);
        }
        else if (eqtoken(token.at(1), "max")) {
            Dec_DecDecCtx(&Decimal::max, token, false, extended);
        }
        else if (eqtoken(token.at(1), "maxmag") || eqtoken(token.at(1), "max_mag")) {
            Dec_DecDecCtx(&Decimal::max_mag, token, false, extended);
        }
        else if (eqtoken(token.at(1), "min")) {
            Dec_DecDecCtx(&Decimal::min, token, false, extended);
        }
        else if (eqtoken(token.at(1), "minmag") || eqtoken(token.at(1), "min_mag")) {
            Dec_DecDecCtx(&Decimal::min_mag, token, false, extended);
        }
        else if (eqtoken(token.at(1), "multiply")) {
            Dec_DecDecCtx(&Decimal::mul, token, false, extended);
            Dec_DecDec(&Decimal::operator*, token, false, extended);
        }
        else if (eqtoken(token.at(1), "nexttoward")) {
            Dec_DecDecCtx(&Decimal::next_toward, token, false, extended);
        }
        else if (eqtoken(token.at(1), "or")) {
            Dec_DecDecCtx(&Decimal::logical_or, token, false, extended);
        }
        else if (eqtoken(token.at(1), "power")) {
            if (extended) {
                /* All test cases in the official tests are correctly rounded
                   even when context.allcr is not set. */
                context.allcr(0);
                Dec_DecDecCtx(&Decimal::pow, token, false, extended);
                context.allcr(1);
            }
            Dec_DecDecCtx(&Decimal::pow, token, false, extended);
        }
        else if (eqtoken(token.at(1), "quantize")) {
            Dec_DecDecCtx(&Decimal::quantize, token, false, extended);
        }
        else if (eqtoken(token.at(1), "resc")) {
            Dec_DecInt64Ctx(&Decimal::rescale, token, extended);
        }
        else if (eqtoken(token.at(1), "remainder")) {
            Dec_DecDecCtx(&Decimal::rem, token, false, extended);
            Dec_DecDec(&Decimal::operator%, token, false, extended);
        }
        else if (eqtoken(token.at(1), "remaindernear")) {
            Dec_DecDecCtx(&Decimal::rem_near, token, false, extended);
        }
        else if (eqtoken(token.at(1), "rotate")) {
            Dec_DecDecCtx(&Decimal::rotate, token, false, extended);
        }
        else if (eqtoken(token.at(1), "scaleb")) {
            Dec_DecDecCtx(&Decimal::scaleb, token, false, extended);
        }
        else if (eqtoken(token.at(1), "shift")) {
            Dec_DecDecCtx(&Decimal::shift, token, false, extended);
            if (extended) {
                Dec_DecInt64Ctx(&Decimal::shiftn, token, extended);
            }
        }
        else if (eqtoken(token.at(1), "subtract")) {
            Dec_DecDecCtx(&Decimal::sub, token, false, extended);
            Dec_DecDec(&Decimal::operator-, token, false, extended);
        }
        else if (eqtoken(token.at(1), "xor")) {
            Dec_DecDecCtx(&Decimal::logical_xor, token, false, extended);
        }

        /* Binary functions with Decimal result, equal operands */
        else if (eqtoken(token.at(1), "add_eq")) {
            Dec_DecDecCtx(&Decimal::add, token, true, extended);
            Dec_DecDec(&Decimal::operator+, token, true, extended);
        }
        else if (eqtoken(token.at(1), "and_eq")) {
            Dec_DecDecCtx(&Decimal::logical_and, token, true, extended);
        }
        else if (eqtoken(token.at(1), "copysign_eq")) {
            Dec_DecDec(&Decimal::copy_sign, token, true, extended);
        }
        else if (eqtoken(token.at(1), "divide_eq")) {
            Dec_DecDecCtx(&Decimal::div, token, true, extended);
            Dec_DecDec(&Decimal::operator/, token, true, extended);
        }
        else if (eqtoken(token.at(1), "divideint_eq")) {
            Dec_DecDecCtx(&Decimal::divint, token, true, extended);
        }
        else if (eqtoken(token.at(1), "max_eq")) {
            Dec_DecDecCtx(&Decimal::max, token, true, extended);
        }
        else if (eqtoken(token.at(1), "maxmag_eq")) {
            Dec_DecDecCtx(&Decimal::max_mag, token, true, extended);
        }
        else if (eqtoken(token.at(1), "min_eq")) {
            Dec_DecDecCtx(&Decimal::min, token, true, extended);
        }
        else if (eqtoken(token.at(1), "minmag_eq")) {
            Dec_DecDecCtx(&Decimal::min_mag, token, true, extended);
        }
        else if (eqtoken(token.at(1), "multiply_eq")) {
            Dec_DecDecCtx(&Decimal::mul, token, true, extended);
            Dec_DecDec(&Decimal::operator*, token, true, extended);
        }
        else if (eqtoken(token.at(1), "nexttoward_eq")) {
            Dec_DecDecCtx(&Decimal::next_toward, token, true, extended);
        }
        else if (eqtoken(token.at(1), "or_eq")) {
            Dec_DecDecCtx(&Decimal::logical_or, token, true, extended);
        }
        else if (eqtoken(token.at(1), "power_eq")) {
            if (extended) {
                /* see power */
                context.allcr(0);
                Dec_DecDecCtx(&Decimal::pow, token, true, extended);
                context.allcr(1);
            }
            Dec_DecDecCtx(&Decimal::pow, token, true, extended);
        }
        else if (eqtoken(token.at(1), "quantize_eq")) {
            Dec_DecDecCtx(&Decimal::quantize, token, true, extended);
        }
        else if (eqtoken(token.at(1), "remainder_eq")) {
            Dec_DecDecCtx(&Decimal::rem, token, true, extended);
            Dec_DecDec(&Decimal::operator%, token, true, extended);
        }
        else if (eqtoken(token.at(1), "remaindernear_eq")) {
            Dec_DecDecCtx(&Decimal::rem_near, token, true, extended);
        }
        else if (eqtoken(token.at(1), "rotate_eq")) {
            Dec_DecDecCtx(&Decimal::rotate, token, true, extended);
        }
        else if (eqtoken(token.at(1), "scaleb_eq")) {
            Dec_DecDecCtx(&Decimal::scaleb, token, true, extended);
        }
        else if (eqtoken(token.at(1), "shift_eq")) {
            Dec_DecDecCtx(&Decimal::shift, token, true, extended);
        }
        else if (eqtoken(token.at(1), "subtract_eq")) {
            Dec_DecDecCtx(&Decimal::sub, token, true, extended);
            Dec_DecDec(&Decimal::operator-, token, true, extended);
        }
        else if (eqtoken(token.at(1), "xor_eq")) {
            Dec_DecDecCtx(&Decimal::logical_xor, token, true, extended);
        }

        /* Binary function with Decimal pair result */
        else if (eqtoken(token.at(1), "divmod")) {
            DecPair_DecDecCtx(&Decimal::divmod, token, false, extended);
        }
        /* Binary function with Decimal pair result, equal operands */
        else if (eqtoken(token.at(1), "divmod_eq")) {
            DecPair_DecDecCtx(&Decimal::divmod, token, true, extended);
        }

        /* Ternary functions with Decimal result */
        else if (eqtoken(token.at(1), "fma")) {
            Dec_DecDecDecCtx(&Decimal::fma, OpOpOp, token, extended);
        }
        else if (eqtoken(token.at(1), "powmod")) {
            Dec_DecDecDecCtx(&Decimal::powmod, OpOpOp, token, extended);
        }

        /* Ternary functions with Decimal result, eq_eq_op */
        else if (eqtoken(token.at(1), "fma_eq_eq_op")) {
            Dec_DecDecDecCtx(&Decimal::fma, EqEqOp, token, extended);
        }
        else if (eqtoken(token.at(1), "powmod_eq_eq_op")) {
            Dec_DecDecDecCtx(&Decimal::powmod, EqEqOp, token, extended);
        }

        /* Ternary functions with Decimal result, eq_op_eq */
        else if (eqtoken(token.at(1), "fma_eq_op_eq")) {
            Dec_DecDecDecCtx(&Decimal::fma, EqOpEq, token, extended);
        }
        else if (eqtoken(token.at(1), "powmod_eq_op_eq")) {
            Dec_DecDecDecCtx(&Decimal::powmod, EqOpEq, token, extended);
        }

        /* Ternary functions with Decimal result, op_eq_eq */
        else if (eqtoken(token.at(1), "fma_op_eq_eq")) {
            Dec_DecDecDecCtx(&Decimal::fma, OpEqEq, token, extended);
        }
        else if (eqtoken(token.at(1), "powmod_op_eq_eq")) {
            Dec_DecDecDecCtx(&Decimal::powmod, OpEqEq, token, extended);
        }

        /* Ternary functions with Decimal result, eq_eq_eq */
        else if (eqtoken(token.at(1), "fma_eq_eq_eq")) {
            Dec_DecDecDecCtx(&Decimal::fma, EqEqEq, token, extended);
        }
        else if (eqtoken(token.at(1), "powmod_eq_eq_eq")) {
            Dec_DecDecDecCtx(&Decimal::powmod, EqEqEq, token, extended);
        }

        /* Special cases for the comparison functions */
        else if (eqtoken(token.at(1), "compare")) {
            Dec_DecDecCtx(&Decimal::compare, token, false, extended);
            Int_DecDec(&Decimal::cmp, token, SKIP_NAN, false, extended);
        }
        else if (eqtoken(token.at(1), "comparesig")) {
            Dec_DecDecCtx(&Decimal::compare_signal, token, false, extended);
        }

        else if (eqtoken(token.at(1), "comparetotal")) {
            Dec_DecDec(&Decimal::compare_total, token, false, extended);
            Int_DecDec(&Decimal::cmp_total, token, SKIP_NONE, false, extended);
        }
        else if (eqtoken(token.at(1), "comparetotmag")) {
            Dec_DecDec(&Decimal::compare_total_mag, token, false, extended);
            Int_DecDec(&Decimal::cmp_total_mag, token, SKIP_NONE, false, extended);
        }

        /* Special cases for the comparison functions, equal operands */
        else if (eqtoken(token.at(1), "compare_eq")) {
            Dec_DecDecCtx(&Decimal::compare, token, true, extended);
            Int_DecDec(&Decimal::cmp, token, SKIP_NAN, true, extended);
        }
        else if (eqtoken(token.at(1), "comparesig_eq")) {
            Dec_DecDecCtx(&Decimal::compare_signal, token, true, extended);
        }

        else if (eqtoken(token.at(1), "comparetotal_eq")) {
            Dec_DecDec(&Decimal::compare_total, token, true, extended);
            Int_DecDec(&Decimal::cmp_total, token, SKIP_NAN, true, extended);
        }
        else if (eqtoken(token.at(1), "comparetotmag_eq")) {
            Dec_DecDec(&Decimal::compare_total_mag, token, true, extended);
            Int_DecDec(&Decimal::cmp_total_mag, token, SKIP_NAN, true, extended);
        }

        /* Special cases for the shift functions */
        else if (eqtoken(token.at(1), "shiftleft")) {
            Dec_DecInt64Ctx(&Decimal::shiftl, token, extended);
        }
        else if (eqtoken(token.at(1), "shiftright")) {
            Dec_DecInt64Ctx(&Decimal::shiftr, token, extended);
        }

        /* Special case for Decimal::ln10() */
        else if (eqtoken(token.at(1), "ln10")) {
            ln10(token, extended);
        }

        /* Special cases for the get_int functions */
        else if (eqtoken(token.at(1), "get_u64") || eqtoken(token.at(1), "get_uint64")) {
            u64_DecCtx(token, extended);
        }
        else if (eqtoken(token.at(1), "get_u32") || eqtoken(token.at(1), "get_uint32")) {
            u32_DecCtx(token, extended);
        }
        else if (eqtoken(token.at(1), "get_i64") || eqtoken(token.at(1), "get_int64")) {
            i64_DecCtx(token, extended);
        }
        else if (eqtoken(token.at(1), "get_i32") || eqtoken(token.at(1), "get_int32")) {
            i32_DecCtx(token, extended);
        }

        else if (startswith(token.at(0), "bool")) {
            /* skip: not implemented: bool tests in extra.decTest */
            continue;
        }

        else if (eqtoken(token.at(1), "get_uint64_abs") ||
                 eqtoken(token.at(1), "get_ssize64") ||
                 eqtoken(token.at(1), "get_uint32_abs") ||
                 eqtoken(token.at(1), "get_ssize32")) {
            /* skip: not implemented */
        }

        else if (eqtoken(token.at(1), "rescale")) {
           /*
            * skip: 'rescale' is obsolete in the standard and Decimal::rescale()
            * is not equivalent to the obsolete version.
            */
        }
        else if (eqtoken(token.at(1), "baseconv")) {
            /* skip: not implemented */
        }
        else {
            err_token(token, "unknown operation");
        }
    }
}

static int
exit_status(const std::vector<std::string>& status)
{
    for (auto p : status) {
        if (p != "PASS") {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

static void
do_file(const std::string& filename, std::vector<std::string>& status, size_t i, bool threaded)
{
    try {
        if (threaded) {
            /* Thread local context is initialized on first access. */
            if (context.prec() != 1) {
                err_raise("automatic context initialization from template failed");
            }
        }

        std::ifstream in{filename};
        if (!in.is_open()) {
            err_raise("could not open ", filename);
        }

        do_stream(in);

        if (in.bad()) {
            err_raise("iterating over lines failed in ", filename);
        }
    } catch (test::Failure& e) {
        status[i] = e.what();
    }
}

/* process a file list */
static int
do_files(const std::vector<std::string>& files)
{
    const size_t n = files.size();
    std::vector<std::string> status(n, "PASS");

    for (size_t i = 0; i < n; i++) {
        std::cout << files[i] << " ... " << std::flush;
        do_file(files[i], status, i, false);
        std::cout << status[i] << "\n" << std::flush;
    }

    std::cout << "\n" << std::flush;

    return exit_status(status);
}

/* process a file list, using std::thread */
static int
do_files_thread(const std::vector<std::string>& files)
{
    const size_t n = files.size();
    std::vector<std::string> status(n, "PASS");
    std::vector<std::thread> t(n);

    for (size_t i = 0; i < n; i++) {
        t[i] = std::thread(do_file, files[i], std::ref(status), i, true);
    }

    for (size_t i = 0; i < n; i++) {
        t[i].join();
    }

    for (size_t i = 0; i < n; i++) {
        std::cout << files[i] << " ... " << status[i] << "\n" << std::flush;
    }

    std::cout << "\n" << std::flush;

    if (skip_bignum) {
        std::cout << "NOTE: std::thread stack size < 512K: skipped "
                  <<  bignum_counter << " bignum test case"
                  << (bignum_counter == 1 ? "\n\n" : "s\n\n")
                  << std::flush;
    }

    return exit_status(status);
}

#ifdef HAVE_PTHREAD_H
/*
 * The pthread section is for systems like AIX, which have a std::thread stack
 * size that is too small for the bignum tests. std::thread does not allow to
 * set the stack size.
 */
#define THREAD_STACK_SIZE 1048576

struct thread_info {
    size_t index;
    pthread_t tid;
    const std::string *filename;
    std::vector<std::string> *status;
};

static bool
thread_stack_too_small_for_bignum()
{
    pthread_attr_t tattr;
    size_t size;
    int ret;

    ret = pthread_attr_init(&tattr);
    if (ret != 0) {
        err_raise("thread attribute initialization failed");
    }

    ret = pthread_attr_getstacksize(&tattr, &size);
    pthread_attr_destroy(&tattr);

    if (ret != 0) {
        err_raise("getting thread stack size failed");
    }

    return size < 524288;
}

static void *
do_file_pthread(void *arg)
{
    struct thread_info *tinfo = static_cast<struct thread_info *>(arg);

    try {
        if (context.prec() != 1) {
            err_raise("automatic context initialization from template failed");
        }

        std::ifstream in{*tinfo->filename};
        if (!in.is_open()) {
            err_raise("could not open ", *tinfo->filename);
        }

        do_stream(in);

        if (in.bad()) {
            err_raise("iterating over lines failed in ", *tinfo->filename);
        }
    } catch (test::Failure& e) {
        (*tinfo->status)[tinfo->index] = e.what();
    }

    return nullptr;
}

/* process a file list, using pthread */
static int
do_files_pthread(const std::vector<std::string>& files)
{
    const size_t n = files.size();
    std::vector<std::string> status(n, "PASS");
    std::vector<struct thread_info> tinfo(n);
    pthread_attr_t tattr;
    int ret;

    ret = pthread_attr_init(&tattr);
    if (ret != 0) {
        err_raise("thread attribute initialization failed");
    }

    ret = pthread_attr_setstacksize(&tattr, THREAD_STACK_SIZE);
    if (ret != 0) {
        pthread_attr_destroy(&tattr);
        err_raise("setting thread stack size failed");
    }

    for (size_t i = 0; i < n; i++) {
        tinfo[i].index = i;
        tinfo[i].filename = &files[i];
        tinfo[i].status = &status;

        ret = pthread_create(&tinfo[i].tid, &tattr, &do_file_pthread, &tinfo[i]);
        if (ret != 0) {
            pthread_attr_destroy(&tattr);
            err_raise("could not create thread");
        }
    }

    for (size_t i = 0; i < n; i++) {
        ret = pthread_join(tinfo[i].tid, nullptr);
        if (ret != 0) {
            pthread_attr_destroy(&tattr);
            err_raise("error in thread execution");
        }
    }

    for (size_t i = 0; i < n; i++) {
        std::cout << files[i] << " ... " << status[i] << "\n" << std::flush;
    }

    std::cout << "\n" << std::flush;

    pthread_attr_destroy(&tattr);

    return exit_status(status);
}
#endif  /* HAVE_PTHREAD_H */


static const int32_t int32_cases[] = {
  INT32_MIN, INT32_MIN+1, INT32_MIN+2,
  INT32_MAX-2, INT32_MAX-1, INT32_MAX,
  -10, -5, -1, 0, 5, 10,
  -999999999, -99999999, -9999999, -999999, -99999, -9999, -999, -99, -9,
  -1000500001, -100050001, -10050001, -1005001, -105001, -10501, -1501, -151,
  -1000000001, -100000001, -10000001, -1000001, -100001, -10001, -1001, -101,
  -1000000000, -100000000, -10000000, -1000000, -100000, -10000, -1000, -100,
  999999999, 99999999, 9999999, 999999, 99999, 9999, 999, 99, 9,
  1000500001, 100050001, 10050001, 1005001, 105001, 10501, 1501, 151,
  1000000001, 100000001, 10000001, 1000001, 100001, 10001, 1001, 101,
  1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100,
  -(1<<30),
  -(1<<29), -(1<<28), -(1<<27), -(1<<26), -(1<<25), -(1<<24), -(1<<23), -(1<<22), -(1<<21), -(1<<20),
  -(1<<19), -(1<<18), -(1<<17), -(1<<16), -(1<<15), -(1<<14), -(1<<13), -(1<<12), -(1<<11), -(1<<10),
  -(1<<9),  -(1<<8),  -(1<<7),  -(1<<6),  -(1<<5),  -(1<<4),  -(1<<3),  -(1<<2),  -(1<<1),  -(1<<0),
   (1<<30),
   (1<<29), (1<<28), (1<<27), (1<<26), (1<<25), (1<<24), (1<<23), (1<<22), (1<<21), (1<<20),
   (1<<19), (1<<18), (1<<17), (1<<16), (1<<15), (1<<14), (1<<13), (1<<12), (1<<11), (1<<10),
   (1<<9),  (1<<8),  (1<<7),  (1<<6),  (1<<5),  (1<<4),  (1<<3),  (1<<2),  (1<<1),  (1<<0)
};

static const int64_t int64_cases[] = {
  INT64_MIN, INT64_MIN+1, INT64_MIN+2, -10, -5, -1, 0, 5, 10, INT64_MAX-2, INT64_MAX-1, INT64_MAX,
  -999999999999999999LL, -99999999999999999LL, -9999999999999999LL, -999999999999999LL, -99999999999999LL, -9999999999999LL,
  -999999999999LL, -99999999999LL, -9999999999LL, -999999999LL, -99999999LL, -9999999LL, -999999LL, -99999LL, -9999LL, -999LL, -99LL, -9LL,
  -1000000000000000000LL, -100000000000000000LL, -10000000000000000LL, -1000000000000000LL, -100000000000000LL, -10000000000000LL,
  -1000000000000LL, -100000000000LL, -10000000000LL, -1000000000LL, -100000000LL, -10000000LL, -1000000LL, -100000LL, -10000LL, -1000LL, -100LL, -10LL,
  -1000000005000000000LL, -100000005000000000LL, -10000005000000000LL, -1000005000000000LL, -100000005000000LL, -10000005000000LL,
  -1000005000000LL, -100005000000LL, -10000005000LL, -1000005000LL, -100005000LL, -10005000LL, -1005000LL, -100050LL, -10050LL, -1050LL, -150LL, -15LL,
  -1000000005000000001LL, -100000005000000001LL, -10000005000000001LL, -1000005000000001LL, -100000005000001LL, -10000005000001LL,
  -1000005000001LL, -100005000001LL, -10000005001LL, -1000005001LL, -100005001LL, -10005001LL, -1005001LL, -100051LL, -10051LL, -1051LL, -151LL, -15LL,
  999999999999999999LL, 99999999999999999LL, 9999999999999999LL, 999999999999999LL, 99999999999999LL, 9999999999999LL,
  999999999999LL, 99999999999LL, 9999999999LL, 999999999LL, 99999999LL, 9999999LL, 999999LL, 99999LL, 9999LL, 999LL, 99LL, 9LL,
  1000000000000000000LL, 100000000000000000LL, 10000000000000000LL, 1000000000000000LL, 100000000000000LL, 10000000000000LL,
  1000000000000LL, 100000000000LL, 10000000000LL, 1000000000LL, 100000000LL, 10000000LL, 1000000LL, 100000LL, 10000LL, 1000LL, 100LL, 10LL,
  1000000005000000000LL, 100000005000000000LL, 10000005000000000LL, 1000005000000000LL, 100000005000000LL, 10000005000000LL,
  1000005000000LL, 100005000000LL, 10000005000LL, 1000005000LL, 100005000LL, 10005000LL, 1005000LL, 100050LL, 10050LL, 1050LL, 150LL, 15LL,
  1000000005000000001LL, 100000005000000001LL, 10000005000000001LL, 1000005000000001LL, 100000005000001LL, 10000005000001LL,
  1000005000001LL, 100005000001LL, 10000005001LL, 1000005001LL, 100005001LL, 10005001LL, 1005001LL, 100051LL, 10051LL, 1051LL, 151LL, 15LL,
  -(1LL<<62), -(1LL<<61), -(1LL<<60),
  -(1LL<<59), -(1LL<<58), -(1LL<<57), -(1LL<<56), -(1LL<<55), -(1LL<<54), -(1LL<<53), -(1LL<<52), -(1LL<<51), -(1LL<<50),
  -(1LL<<39), -(1LL<<38), -(1LL<<37), -(1LL<<36), -(1LL<<35), -(1LL<<34), -(1LL<<33), -(1LL<<32), -(1LL<<31), -(1LL<<30),
  -(1LL<<29), -(1LL<<28), -(1LL<<27), -(1LL<<26), -(1LL<<25), -(1LL<<24), -(1LL<<23), -(1LL<<22), -(1LL<<21), -(1LL<<20),
  -(1LL<<19), -(1LL<<18), -(1LL<<17), -(1LL<<16), -(1LL<<15), -(1LL<<14), -(1LL<<13), -(1LL<<12), -(1LL<<11), -(1LL<<10),
  -(1LL<<9),  -(1LL<<8),  -(1LL<<7),  -(1LL<<6),  -(1LL<<5),  -(1LL<<4),  -(1LL<<3),  -(1LL<<2),  -(1LL<<1),  -(1LL<<0),
  -(1LL<<62), -(1LL<<61), -(1LL<<60),
  (1LL<<59), (1LL<<58), (1LL<<57), (1LL<<56), (1LL<<55), (1LL<<54), (1LL<<53), (1LL<<52), (1LL<<51), (1LL<<50),
  (1LL<<39), (1LL<<38), (1LL<<37), (1LL<<36), (1LL<<35), (1LL<<34), (1LL<<33), (1LL<<32), (1LL<<31), (1LL<<30),
  (1LL<<29), (1LL<<28), (1LL<<27), (1LL<<26), (1LL<<25), (1LL<<24), (1LL<<23), (1LL<<22), (1LL<<21), (1LL<<20),
  (1LL<<19), (1LL<<18), (1LL<<17), (1LL<<16), (1LL<<15), (1LL<<14), (1LL<<13), (1LL<<12), (1LL<<11), (1LL<<10),
  (1LL<<9),  (1LL<<8),  (1LL<<7),  (1LL<<6),  (1LL<<5),  (1LL<<4),  (1LL<<3),  (1LL<<2),  (1LL<<1),  (1LL<<0),
};

static const char *init_cases[] = {
  "sNaN", "sNaN19",
  "sNaN1982612612300000002000000000050000000000000000101111111111111112111111111111111111111111111111111111111111111111"
  "111111111111111111111111111111111111111111111111111111111111111",
  "-sNaN", "-sNaN19",
  "-sNaN198261261230000000200000000005000000000000000010111111111111111211111111111111111111111111111111111111111111111"
  "1111111111111111111111111111111111111111111111111111111111111111",
  "NaN", "NaN19",
  "NaN19826126123000000020000000000500000000000000001011111111111111121111111111111111111111111111111111111111111111111"
  "11111111111111111111111111111111111111111111111111111111111111",
  "-NaN", "-NaN19",
  "-NaN1982612612300000002000000000050000000000000000101111111111111112111111111111111111111111111111111111111111111111"
  "111111111111111111111111111111111111111111111111111111111111111",
  "inf", "-inf",
  "-1", "-0", "0", "1",
  "1e10", "-1e10",
  "1.21019218731291112376416152e10",
  "-1.21019218731291112376416152e10",
  "0.0000000000000000000000000000000000000000000000000001e-999999",
  "-0.0000000000000000000000000000000000000000000000000001e-999999"
};

static void
test_set_i32(void)
{
    const Context savecontext = context;
    context.status(0);
    for (const char *s : init_cases) {
        for (const int32_t& x : int32_cases) {
            Decimal v{s};

            v = x;
            assertEqual(context.status(), 0U);
            assertEqualStr(v, std::to_string(x));
        }
    }
    context = savecontext;
}

static void
test_set_i64(void)
{
    const Context savecontext = context;
    context.status(0);
    for (const char *s : init_cases) {
        for (const int64_t& x : int64_cases) {
            Decimal v{s};

            v = x;
            assertEqual(context.status(), 0U);
            assertEqualStr(v, std::to_string(x));
        }
    }
    context = savecontext;
}


/* process a single test file */
static void
usage(void)
{
    std::cerr << "runtest: usage: runtest testfile [--custom] [--alloc] [--thread|--pthread]" << std::endl;
    exit(EXIT_FAILURE);
}

static std::vector<std::string>
collect_files(const std::string& topfile)
{
    std::vector<std::string> files;
    std::string line;

    std::ifstream in{topfile};
    if (!in.is_open()) {
        err_exit("could not open file");
    }

    while (std::getline(in, line)) {
        std::vector<std::string> token = split(line);
        if (token.size() == 0) {
            continue;
        }

        if (startswith(token.at(0), "Dectest")) {
            files.push_back(token.at(1));
            continue;
        }
        else {
            err_exit("parse error");
        }
    }

    if (in.bad()) {
        err_exit("iterating over lines failed");
    }

    return files;
}


int
main(int argc, char *argv[])
{
    std::vector<std::string> args(argv + (argc!=0), argv + argc);
    std::string filename = "";
    bool custom_alloc = false;
    bool check_alloc = false;
    bool thread = false;
    bool pthread = false;

    for (auto arg : args) {
        if (filename == "" && (arg == "-" || !startswith(arg, "--"))) {
            filename = arg;
        }
        else if (!custom_alloc && arg == "--custom") {
            custom_alloc = true;
        }
        else if (!check_alloc && arg == "--alloc") {
            check_alloc = true;
        }
        else if (!thread && arg == "--thread") {
            thread = true;
        }
        else if (!pthread && arg == "--pthread") {
            pthread = true;
        }
        else {
            usage();
        }
    }
    if (filename == "") {
        usage();
    }

    /* std::thread needs 300K stack size for the bignum tests. */
    #ifdef HAVE_PTHREAD_H
    if (thread && thread_stack_too_small_for_bignum()) {
        skip_bignum = true;
    }
    #endif

    /* Initialize custom allocation functions */
    test::init_alloc(custom_alloc, check_alloc);

    /* Initialize the context template */
    context_template = Context(1, 1, -1);

    /* Initialize main thread context */
    context = context_template;

    /* Initial tests */
    test_set_i32();
    test_set_i64();
    test_copy_constructor();


    /* Read test cases from stdin */
    if (filename == "-") {
        try {
            do_stream(std::cin, /*extended=*/false);
        }
        catch (test::Failure& e) {
            std::cerr << "<stdin> ... " << e.what() << "\n" << std::flush;
            return EXIT_FAILURE;
        }
        std::cout << "<stdin> ... PASS\n\n" << std::flush;
        return EXIT_SUCCESS;
    }

    /* Collect test files */
    std::vector<std::string> files;
    if (endswith(filename, ".decTest")) {
        files.push_back(filename);
    }
    else if (endswith(filename, ".topTest")) {
        std::ifstream in{filename};
        if (!in.is_open()) {
            err_exit("could not open file");
        }

        files = collect_files(filename);

        if (in.bad()) {
            err_exit("iterating over lines failed");
        }
    }
    else {
        err_exit("unrecognized file extension: expect .decTest or .topTest");
    }

    /* Run all tests */
    if (thread) {
        return do_files_thread(files);
    }
    else if (pthread) {
    #ifdef HAVE_PTHREAD_H
        return do_files_pthread(files);
    #else
        err_exit("pthread not found on this system: use --thread");
    #endif
    }
    else {
        return do_files(files);
    }
}
