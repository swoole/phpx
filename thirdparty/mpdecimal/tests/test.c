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


#include <stdbool.h>
#include <stdlib.h>

#include "mpdecimal.h"
#include "test.h"


/******************************************************************************/
/*               Primary allocation functions (normal or offset)              */
/******************************************************************************/

static const size_t OFFSET = 16;

#ifdef MPD_CONFIG_64
static const size_t alloc_limit = 0x4000000000000ULL;
#else
static size_t alloc_limit = SIZE_MAX;
#endif

/* malloc with upper limits */
static void *
malloc_ceil(size_t size)
{
    if (size > alloc_limit) {
        return NULL;
    }

    return malloc(size);
}

static void *
calloc_ceil(size_t nmemb, size_t size)
{
    if (nmemb > alloc_limit / size) {
        return NULL;
    }

    return calloc(nmemb, size);
}

static void *
realloc_ceil(void *ptr, size_t size)
{
    if (size > alloc_limit) {
        return NULL;
    }

    return realloc(ptr, size);
}

static void
free_ceil(void *ptr)
{
    free(ptr);
}

/* custom malloc with an offset and upper limits */
static void *
malloc_offset(size_t size)
{
    if (size == 0 || size > SIZE_MAX - OFFSET) {
        return NULL;
    }

    char *ptr = malloc_ceil(OFFSET + size);

    return ptr ? ptr + OFFSET : NULL;
}

static void *
calloc_offset(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0 || size > SIZE_MAX - OFFSET) {
        return NULL;
    }

    char *ptr = calloc_ceil(nmemb, OFFSET + size);

    return ptr ? ptr + OFFSET : NULL;
}

static void *
realloc_offset(void *ptr, size_t size)
{
    if (size == 0 || size > SIZE_MAX - OFFSET) {
        return NULL;
    }

    char *c = (char *)ptr - OFFSET;
    char *p = realloc_ceil(c, OFFSET + size);

    return p ? p + OFFSET : NULL;
}

static void
free_offset(void *ptr)
{
    free((char *)ptr - OFFSET);
}

/* active set of primary allocation functions */
static void *(* test_mallocfunc)(size_t size) = malloc_ceil;
static void *(* test_callocfunc)(size_t nmemb, size_t size) = calloc_ceil;
static void *(* test_reallocfunc)(void *ptr, size_t size) = realloc_ceil;
static void (* test_freefunc)(void *ptr) = free_ceil;


/******************************************************************************/
/*            Secondary allocation functions (count or failure mode)          */
/******************************************************************************/

static bool enable_check_alloc = false;
int alloc_count;
int alloc_fail;
int alloc_idx;

static void *
malloc_count(size_t size)
{
    ++alloc_count;
    return test_mallocfunc(size);
}

static void *
calloc_count(size_t nmemb, size_t size)
{
    ++alloc_count;
    return test_callocfunc(nmemb, size);
}

static void *
realloc_count(void *ptr, size_t size)
{
    ++alloc_count;
    return test_reallocfunc(ptr, size);
}

static void *
malloc_fail(size_t size)
{
    if (++alloc_idx >= alloc_fail) {
        return NULL;
    }

    return test_mallocfunc(size);
}

static void *
calloc_fail(size_t nmemb, size_t size)
{
    if (++alloc_idx >= alloc_fail) {
        return NULL;
    }

    return test_callocfunc(nmemb, size);
}

static void *
realloc_fail(void *ptr, size_t size)
{
    if (++alloc_idx >= alloc_fail) {
        return NULL;
    }

    return test_reallocfunc(ptr, size);
}


/******************************************************************************/
/*                                 Public API                                 */
/******************************************************************************/

/* choose primary allocation functions at program start */
void
mpd_init_alloc(bool custom_alloc, bool check_alloc)
{
    static bool initialized = false;

    if (initialized) {
        fputs("mpd_init_alloc: error: cannot initialize twice\n", stderr);
        exit(EXIT_FAILURE);
    }
    initialized = true;

    enable_check_alloc = check_alloc;

    if (custom_alloc) {
        test_mallocfunc = malloc_offset;
        test_callocfunc = calloc_offset;
        test_reallocfunc = realloc_offset;
        test_freefunc = free_offset;
    }

    mpd_mallocfunc = test_mallocfunc;
    mpd_callocfunc = test_callocfunc;
    mpd_reallocfunc = test_reallocfunc;
    mpd_free = test_freefunc;
}

#ifdef MPD_CONFIG_32
void
mpd_set_alloc_limit(size_t size)
{
    alloc_limit = size;
}
#endif

void
mpd_set_alloc(mpd_context_t *ctx)
{
    mpd_mallocfunc = test_mallocfunc;
    mpd_callocfunc = test_callocfunc;
    mpd_reallocfunc = test_reallocfunc;
    mpd_free = test_freefunc;

    ctx->traps = MPD_Malloc_error;
}

void
mpd_set_alloc_count(mpd_context_t *ctx)
{
    mpd_mallocfunc = malloc_count;
    mpd_callocfunc = calloc_count;
    mpd_reallocfunc = realloc_count;
    mpd_free = test_freefunc;

    ctx->traps = MPD_Malloc_error;
    alloc_count = 0;
}

void
mpd_set_alloc_fail(mpd_context_t *ctx)
{
    if (enable_check_alloc) {
        mpd_mallocfunc = malloc_fail;
        mpd_callocfunc = calloc_fail;
        mpd_reallocfunc = realloc_fail;
        mpd_free = test_freefunc;

        ctx->traps = 0;
        alloc_idx = 0;
    }
}
