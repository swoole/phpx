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


#include <cstdlib>
#include <cstdint>
#include <cinttypes>

#include "mpdecimal.h"

#include "decimal.hh"
#include "test.hh"


/******************************************************************************/
/*                                Exceptions                                  */
/******************************************************************************/

namespace test {
const char *Failure::what() const noexcept { return m.what(); }
}  // namespace test


/******************************************************************************/
/*                                Functions                                   */
/******************************************************************************/

namespace test {
void
assert_true(const char *file, const int64_t line, const bool p)
{
    if (!(p)) {
        raise(file, line, "assertion failed (expected true, got false)");
    }
}

void
assert_false(const char *file, const int64_t line, const bool p)
{
    if (p) {
        raise(file, line, "assertion failed (expected false, got true)");
    }
}
}  // namespace test


/******************************************************************************/
/*               Primary allocation functions (normal or offset)              */
/******************************************************************************/

static const size_t OFFSET = 16;

#ifdef MPD_CONFIG_64
static const size_t alloc_limit = 0x4000000000000ULL;
#else
static thread_local size_t alloc_limit = SIZE_MAX;
#endif

/* malloc with upper limits */
static void *
malloc_ceil(size_t size)
{
    if (size > alloc_limit) {
        return nullptr;
    }

    return malloc(size);
}

static void *
calloc_ceil(size_t nmemb, size_t size)
{
    if (nmemb > alloc_limit / size) {
        return nullptr;
    }

    return calloc(nmemb, size);
}

static void *
realloc_ceil(void *ptr, size_t size)
{
    if (size > alloc_limit) {
        return nullptr;
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
        return nullptr;
    }

    char *ptr = (char *)malloc_ceil(OFFSET + size);

    return ptr ? ptr + OFFSET : nullptr;
}

static void *
calloc_offset(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0 || size > SIZE_MAX - OFFSET) {
        return nullptr;
    }

    char *ptr = (char *)calloc_ceil(nmemb, OFFSET + size);

    return ptr ? ptr + OFFSET : nullptr;
}

static void *
realloc_offset(void *ptr, size_t size)
{
    if (size == 0 || size > SIZE_MAX - OFFSET) {
        return nullptr;
    }

    char *c = (char *)ptr - OFFSET;
    char *p = (char *)realloc_ceil(c, OFFSET + size);

    return p ? p + OFFSET : nullptr;
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
static thread_local uint64_t alloc_fail = UINT64_MAX;
static thread_local uint64_t alloc_idx = 0;

static void *
malloc_fail(size_t size)
{
    if (++alloc_idx >= alloc_fail) {
        return nullptr;
    }

    return test_mallocfunc(size);
}

static void *
calloc_fail(size_t nmemb, size_t size)
{
    if (++alloc_idx >= alloc_fail) {
        return nullptr;
    }

    return test_callocfunc(nmemb, size);
}

static void *
realloc_fail(void *ptr, size_t size)
{
    if (++alloc_idx >= alloc_fail) {
        return nullptr;
    }

    return test_reallocfunc(ptr, size);
}

namespace test {

void
init_alloc(bool custom_alloc, bool check_alloc)
{
    static bool initialized = false;

    if (initialized) {
        fputs("mpd_init_alloc: error: cannot initialize twice\n", stderr);
        exit(EXIT_FAILURE);
    }
    initialized = true;

    /* initialization for the main thread */
#ifdef MPD_CONFIG_32
    alloc_limit = SIZE_MAX;
#endif
    alloc_fail = UINT64_MAX;
    alloc_idx = 0;

    enable_check_alloc = check_alloc;

    if (custom_alloc) {
        test_mallocfunc = malloc_offset;
        test_callocfunc = calloc_offset;
        test_reallocfunc = realloc_offset;
        test_freefunc = free_offset;
    }

    mpd_mallocfunc = malloc_fail;
    mpd_callocfunc = calloc_fail;
    mpd_reallocfunc = realloc_fail;
    mpd_free = test_freefunc;
}

#ifdef MPD_CONFIG_32
void
set_alloc_limit(size_t size)
{
    alloc_limit = size;
}
#endif

void
set_alloc(decimal::Context &ctx)
{
    ctx.traps(MPD_Malloc_error);
    alloc_idx = 0;
    alloc_fail = UINT64_MAX;
}

void
set_alloc_fail(decimal::Context &ctx, uint64_t n)
{
    if (enable_check_alloc) {
        ctx.traps(MPD_Malloc_error);
        alloc_idx = 0;
        alloc_fail = n;
    }
}

}  /* namespace test */
