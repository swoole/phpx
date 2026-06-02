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


#ifndef TESTS_HH_
#define TESTS_HH_


#include <exception>
#include <string>
#include <sstream>
#include <vector>


namespace test {


/******************************************************************************/
/*                                    Util                                    */
/******************************************************************************/

template<typename T>
static inline const std::string
str(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

static inline const std::string
stringize()
{
    return std::string();
}

template<typename T, typename... Args>
static inline const std::string
stringize(const T& t, Args... args)
{
    return str(t) + stringize(args...);
}


/******************************************************************************/
/*                                 Exceptions                                 */
/******************************************************************************/

class Failure: public std::exception {
 private:
    std::runtime_error m;
 public:
    template<typename... Args>
    explicit Failure(Args... args) : m(stringize(args...)) {}
    virtual const char* what() const noexcept;
};

template<typename... Args>
static void
raise(const char *file, const int64_t line, Args... args)
{
    throw Failure("error: ", args..., "  [", file, ":", line, "]");
}


/******************************************************************************/
/*                                Test support                                */
/******************************************************************************/

void assert_true(const char *file, const int64_t line, const bool p);
void assert_false(const char *file, const int64_t line, const bool p);

template<class T, class U>
void
assert_equal(const char *file, const int64_t line, const T& calc, const U& expected)
{
    if (calc != expected) {
        raise(file, line, "values not equal: ", "expected: ", test::str(expected),
                          " got: ", test::str(calc));
    }
}

template<class T, class U>
void
assert_equal_str(const char *file, int64_t line, const T& calc, const U& expected)
{
    if (str(calc) != str(expected)) {
        raise(file, line, "string representations not equal: expected: ", test::str(expected),
                          " got: ", test::str(calc));
    }
}

template<typename Exc, typename F>
void
assert_raises(const char *file, const int64_t line, const F& f)
{
    try {
        f();
        raise(file, line, "exception not raised");
    }
    catch (Exc& e) {
        (void)e;
        return;
    }
    catch (std::exception& e) {
        raise(file, line, "unexpected exception: ", e.what());
    }
}

#define assertTrue(p) test::assert_true(__FILE__, __LINE__, p)
#define assertFalse(p) test::assert_false(__FILE__, __LINE__, p)
#define assertEqual(calc, expected) test::assert_equal(__FILE__, __LINE__, calc, expected)
#define assertEqualStr(calc, expected) test::assert_equal_str(__FILE__, __LINE__, calc, expected)
#define assertRaises(ex, func) test::assert_raises<ex>(__FILE__, __LINE__, func)

#define err_exit(msg) \
  do {std::cerr << __FILE__ << ":" << __LINE__ << ": error: "; \
      std::cerr << msg  << std::endl;                          \
      std::exit(EXIT_FAILURE);                                 \
  } while (0)

#define err_raise(...) \
  do { throw test::Failure( "error: ", __VA_ARGS__, "  [", __FILE__, ":", __LINE__, "]"); } while (0)

#define err_token(token, ...) \
  do { throw test::Failure(token.at(0), ": ", __VA_ARGS__, "  [", __FILE__, ":", __LINE__, "]"); } while (0)

#define DECIMAL_ASSERT(p, token) \
  do { if (!(p)) { err_token(token, "assertion failure"); } } while (0)


/******************************************************************************/
/*                      API for testing allocation failures                   */
/******************************************************************************/

void init_alloc(bool custom_alloc, bool check_alloc);

#ifdef MPD_CONFIG_32
void set_alloc_limit(size_t size);
#endif

void set_alloc_fail(decimal::Context &ctx, uint64_t n);
void set_alloc(decimal::Context &ctx);

}  // namespace test


#endif  // TESTS_HH_
