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


#ifndef LIBMPDECXX_DECIMAL_HH_
#define LIBMPDECXX_DECIMAL_HH_


#include <cassert>
#include <cstddef>
#include <cstdint>

#include <algorithm>
#include <atomic>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#include <mpdecimal.h>

#undef iscanonical /* math.h */
#undef isfinite    /* math.h */
#undef isinf       /* math.h */
#undef isnan       /* math.h */
#undef isnormal    /* math.h */
#undef issubnormal /* math.h */
#undef iszero      /* math.h */
#undef isspecial   /* ctype.h */

#undef IMPORTEXPORT
#ifdef _MSC_VER
  #if defined (BUILD_LIBMPDECXX)
    #define IMPORTEXPORT __declspec(dllexport)
  #elif defined(_DLL)
    #define IMPORTEXPORT __declspec(dllimport)
  #else
    #define IMPORTEXPORT
  #endif
  #define ALWAYS_INLINE __forceinline
#else
  #define IMPORTEXPORT
  #define ALWAYS_INLINE inline
#endif


namespace decimal {

/******************************************************************************/
/*                          Constants from libmpdec                           */
/******************************************************************************/

enum round {
  ROUND_UP = MPD_ROUND_UP,               /* round away from 0               */
  ROUND_DOWN = MPD_ROUND_DOWN,           /* round toward 0 (truncate)       */
  ROUND_CEILING = MPD_ROUND_CEILING,     /* round toward +infinity          */
  ROUND_FLOOR = MPD_ROUND_FLOOR,         /* round toward -infinity          */
  ROUND_HALF_UP = MPD_ROUND_HALF_UP,     /* 0.5 is rounded up               */
  ROUND_HALF_DOWN = MPD_ROUND_HALF_DOWN, /* 0.5 is rounded down             */
  ROUND_HALF_EVEN = MPD_ROUND_HALF_EVEN, /* 0.5 is rounded to even          */
  ROUND_05UP = MPD_ROUND_05UP,           /* round zero or five away from 0  */
  ROUND_TRUNC = MPD_ROUND_TRUNC,         /* truncate, but set infinity      */
  ROUND_GUARD = MPD_ROUND_GUARD
};

/*
 * Aliases for a spelling that is consistent with the exceptions below.
 * Use whichever form you prefer.
 */
constexpr uint32_t DecClamped = MPD_Clamped;
constexpr uint32_t DecConversionSyntax = MPD_Conversion_syntax;
constexpr uint32_t DecDivisionByZero = MPD_Division_by_zero;
constexpr uint32_t DecDivisionImpossible = MPD_Division_impossible;
constexpr uint32_t DecDivisionUndefined = MPD_Division_undefined;
constexpr uint32_t DecFpuError = MPD_Fpu_error; /* unused */
constexpr uint32_t DecInexact = MPD_Inexact;
constexpr uint32_t DecInvalidContext = MPD_Invalid_context;
constexpr uint32_t DecInvalidOperation = MPD_Invalid_operation;
constexpr uint32_t DecMallocError = MPD_Malloc_error;
constexpr uint32_t DecNotImplemented = MPD_Not_implemented; /* unused */
constexpr uint32_t DecOverflow = MPD_Overflow;
constexpr uint32_t DecRounded = MPD_Rounded;
constexpr uint32_t DecSubnormal = MPD_Subnormal;
constexpr uint32_t DecUnderflow = MPD_Underflow;

/* Flag sets */
constexpr uint32_t DecIEEEInvalidOperation = MPD_IEEE_Invalid_operation;
                                            /* DecConversionSyntax */
                                            /* DecDivisionImpossible */
                                            /* DecDivisionUndefined */
                                            /* DecFpuError */
                                            /* DecInvalidContext */
                                            /* DecInvalidOperation */
                                            /* DecMallocError */

constexpr uint32_t DecErrors = MPD_Errors;
                               /* DecIEEEInvalidOperation */
                               /* DecDivisionByZero */

constexpr uint32_t DecMaxStatus = MPD_Max_status;
                                  /* All flags */

/* IEEEContext(): common arguments */
constexpr int DECIMAL32 = MPD_DECIMAL32;
constexpr int DECIMAL64 = MPD_DECIMAL64;
constexpr int DECIMAL128 = MPD_DECIMAL128;

/* IEEEContext(): maximum argument value */
constexpr int IEEE_CONTEXT_MAX_BITS = MPD_IEEE_CONTEXT_MAX_BITS;


/******************************************************************************/
/*                             Decimal Exceptions                             */
/******************************************************************************/

class DecimalException : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

/* Signals */
class IEEEInvalidOperation : public DecimalException {
  using DecimalException::DecimalException;
};

class DivisionByZero : public DecimalException {
  using DecimalException::DecimalException;
};

class Overflow : public DecimalException {
  using DecimalException::DecimalException;
};

class Underflow : public DecimalException {
  using DecimalException::DecimalException;
};

class Subnormal : public DecimalException {
  using DecimalException::DecimalException;
};

class Inexact : public DecimalException {
  using DecimalException::DecimalException;
};

class Rounded : public DecimalException {
  using DecimalException::DecimalException;
};

class Clamped : public DecimalException {
  using DecimalException::DecimalException;
};

/* Conditions */
class InvalidOperation : public IEEEInvalidOperation {
  using IEEEInvalidOperation::IEEEInvalidOperation;
};

class ConversionSyntax : public IEEEInvalidOperation {
  using IEEEInvalidOperation::IEEEInvalidOperation;
};

class DivisionImpossible : public IEEEInvalidOperation {
  using IEEEInvalidOperation::IEEEInvalidOperation;
};

class DivisionUndefined : public IEEEInvalidOperation {
  using IEEEInvalidOperation::IEEEInvalidOperation;
};


/******************************************************************************/
/*                               Other Exceptions                             */
/******************************************************************************/

class MallocError : public DecimalException {
  using DecimalException::DecimalException;
};

class RuntimeError : public DecimalException {
  using DecimalException::DecimalException;
};

class ValueError : public DecimalException {
  using DecimalException::DecimalException;
};


/******************************************************************************/
/*                              Context object                                */
/******************************************************************************/

class Context;

IMPORTEXPORT extern Context context_template;
#if defined(__OpenBSD__) || defined(__sun) || defined(_MSC_VER) && defined(_DLL)
IMPORTEXPORT Context& getcontext();
static thread_local Context& context{getcontext()};
#else
extern thread_local Context context;
#endif

class Context {
 private:
  mpd_context_t ctx;
  IMPORTEXPORT static void raiseit(uint32_t status);

 public:
  /***********************************************************************/
  /*                             Constructors                            */
  /***********************************************************************/
  Context(const Context& c) = default;
  Context(Context&& c) = default;

  explicit Context(const mpd_context_t &m) noexcept : ctx(m) {}

  explicit Context(mpd_ssize_t prec=context_template.prec(),
                   mpd_ssize_t emax=context_template.emax(),
                   mpd_ssize_t emin=context_template.emin(),
                   int round=context_template.round(),
                   uint32_t traps=context_template.traps(),
                   int clamp=context_template.clamp(),
                   int allcr=context_template.allcr()) {
    this->prec(prec);
    this->emax(emax);
    this->emin(emin);
    this->traps(traps);
    this->round(round);
    this->clamp(clamp);
    this->allcr(allcr);
    this->ctx.status = 0;
    this->ctx.newtrap = 0;
  }

  /***********************************************************************/
  /*                             Destructor                              */
  /***********************************************************************/
  ~Context() noexcept = default;

  /***********************************************************************/
  /*                         Assignment operators                        */
  /***********************************************************************/
  Context& operator= (const Context& c) = default;
  Context& operator= (Context&& c) = default;

  /***********************************************************************/
  /*                         Comparison operators                        */
  /***********************************************************************/
  bool operator== (const Context& other) const noexcept {
    return ctx.prec == other.ctx.prec &&
           ctx.emax == other.ctx.emax &&
           ctx.emin == other.ctx.emin &&
           ctx.traps == other.ctx.traps &&
           ctx.status == other.ctx.status &&
           ctx.round == other.ctx.round &&
           ctx.clamp == other.ctx.clamp &&
           ctx.allcr == other.ctx.allcr &&
           ctx.newtrap == other.ctx.newtrap;
  }

  bool operator!= (const Context& other) const noexcept {
    return !(*this == other);
  }

  /***********************************************************************/
  /*                              Accessors                              */
  /***********************************************************************/
  /* Get pointers to the full context */
  ALWAYS_INLINE mpd_context_t *get() { return &ctx; }
  ALWAYS_INLINE const mpd_context_t *getconst() const { return &ctx; }

  /* Get individual fields */
  ALWAYS_INLINE mpd_ssize_t prec() const { return ctx.prec; }
  ALWAYS_INLINE mpd_ssize_t emax() const { return ctx.emax; }
  ALWAYS_INLINE mpd_ssize_t emin() const { return ctx.emin; }
  ALWAYS_INLINE int round() const { return ctx.round; }
  ALWAYS_INLINE uint32_t status() const { return ctx.status; }
  ALWAYS_INLINE uint32_t traps() const { return ctx.traps; }
  ALWAYS_INLINE int clamp() const { return ctx.clamp; }
  ALWAYS_INLINE int allcr() const { return ctx.allcr; }
  ALWAYS_INLINE int64_t etiny() const { return mpd_etiny(&ctx); }
  ALWAYS_INLINE int64_t etop() const { return mpd_etop(&ctx); }

  /* Set individual fields */
  ALWAYS_INLINE void prec(mpd_ssize_t v) {
    if (!mpd_qsetprec(&ctx, v)) {
      throw ValueError("valid range for prec is [1, MAX_PREC]");
    }
  }

  ALWAYS_INLINE void emax(mpd_ssize_t v) {
    if (!mpd_qsetemax(&ctx, v)) {
      throw ValueError("valid range for emax is [0, MAX_EMAX]");
    }
  }

  ALWAYS_INLINE void emin(mpd_ssize_t v) {
    if (!mpd_qsetemin(&ctx, v)) {
      throw ValueError("valid range for emin is [MIN_EMIN, 0]");
    }
  }

  ALWAYS_INLINE void round(int v) {
    if (!mpd_qsetround(&ctx, v)) {
      throw ValueError("valid values for rounding are:\n"
                       "  [ROUND_CEILING, ROUND_FLOOR, ROUND_UP, ROUND_DOWN,\n"
                       "   ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_EVEN,\n"
                       "   ROUND_05UP]");
    }
  }

  ALWAYS_INLINE void status(uint32_t v) {
    if (!mpd_qsetstatus(&ctx, v)) {
      throw ValueError("invalid status flag");
    }
  }

  ALWAYS_INLINE void traps(uint32_t v) {
    if (!mpd_qsettraps(&ctx, v)) {
      throw ValueError("invalid status flag");
    }
  }

  ALWAYS_INLINE void clamp(int v) {
    if (!mpd_qsetclamp(&ctx, v)) {
      throw ValueError("invalid value for clamp");
    }
  }

  ALWAYS_INLINE void allcr(int v) {
    if (!mpd_qsetcr(&ctx, v)) {
      throw ValueError("invalid value for allcr");
    }
  }

  /***********************************************************************/
  /*                     Status and exception handling                   */
  /***********************************************************************/
  /* Add flags to status and raise an exception if a relevant trap is active */
  ALWAYS_INLINE void raise(uint32_t flags) {
    ctx.status |= (flags & ~MPD_Malloc_error);
    const uint32_t active_traps = flags & (ctx.traps|MPD_Malloc_error);
    if (active_traps) {
      raiseit(active_traps);
    }
  }

  /* Same, but with cleanup for constructors */
  ALWAYS_INLINE void raise(uint32_t flags, mpd_t *a, bool isstatic) {
    ctx.status |= (flags & ~MPD_Malloc_error);
    const uint32_t active_traps = flags & (ctx.traps|MPD_Malloc_error);
    if (active_traps) {
      if (!isstatic) {
        mpd_del(a);
      }
      raiseit(active_traps);
    }
  }

  /* Add selected status flags */
  ALWAYS_INLINE void add_status(uint32_t flags) {
    if (flags > MPD_Max_status) {
      throw ValueError("invalid flags");
    }
    ctx.status |= flags;
  }

  /* Clear all status flags */
  ALWAYS_INLINE void clear_status() {
    ctx.status = 0;
  }

  /* Clear selected status flags */
  ALWAYS_INLINE void clear_status(uint32_t flags) {
    if (flags > MPD_Max_status) {
      throw ValueError("invalid flags");
    }
    ctx.status &= ~flags;
  }

  /* Add selected traps */
  ALWAYS_INLINE void add_traps(uint32_t flags) {
    if (flags > MPD_Max_status) {
      throw ValueError("invalid flags");
    }
    ctx.traps |= flags;
  }

  /* Clear all traps */
  ALWAYS_INLINE void clear_traps() {
    ctx.traps = 0;
  }

  /* Clear selected traps */
  ALWAYS_INLINE void clear_traps(uint32_t flags) {
    if (flags > MPD_Max_status) {
      throw ValueError("invalid flags");
    }
    ctx.traps &= ~flags;
  }

  /***********************************************************************/
  /*                          String conversion                          */
  /***********************************************************************/
  IMPORTEXPORT std::string repr() const;
  IMPORTEXPORT friend std::ostream& operator<<(std::ostream& os, const Context& c);
};

IMPORTEXPORT Context MaxContext();
IMPORTEXPORT Context IEEEContext(int bits);


/******************************************************************************/
/*                                    Util                                    */
/******************************************************************************/

namespace util {

template <typename dest_t, typename src_t>
inline dest_t
safe_downcast(src_t v) {
  if (v < std::numeric_limits<dest_t>::min() ||
      v > std::numeric_limits<dest_t>::max()) {
    throw ValueError("cast changes the original value");
  }

  return static_cast<dest_t>(v);
}

inline std::shared_ptr<const char>
shared_cp(const char *cp) {
  if (cp == nullptr) {
    throw RuntimeError("util::shared_cp: invalid nullptr argument");
  }

  return std::shared_ptr<const char>(cp, [](const char *s){ mpd_free(const_cast<char *>(s)); });
}

inline std::string
string_from_cp(const char *cp) {
  const auto p = shared_cp(cp);
  return std::string(p.get());
}

template <typename T>
struct int64_compat {
#define INT64_SUBSET(T) \
  (INT64_MIN <= std::numeric_limits<T>::min() && std::numeric_limits<T>::max() <= INT64_MAX)

  static const bool value = std::is_same<T, int8_t>::value ||
                            std::is_same<T, int16_t>::value ||
                            std::is_same<T, int32_t>::value ||
                            std::is_same<T, int64_t>::value ||
                            (std::is_same<T, signed char>::value && INT64_SUBSET(signed char)) ||
                            (std::is_same<T, short>::value && INT64_SUBSET(short)) ||
                            (std::is_same<T, int>::value && INT64_SUBSET(int)) ||
                            (std::is_same<T, long>::value && INT64_SUBSET(long)) ||
                            (std::is_same<T, long long>::value && INT64_SUBSET(long long));
};

template <typename T>
struct uint64_compat {
#define UINT64_SUBSET(T) (std::numeric_limits<T>::max() <= UINT64_MAX)

  static const bool value = std::is_same<T, uint8_t>::value ||
                            std::is_same<T, uint16_t>::value ||
                            std::is_same<T, uint32_t>::value ||
                            std::is_same<T, uint64_t>::value ||
                            (std::is_same<T, unsigned char>::value && UINT64_SUBSET(unsigned char)) ||
                            (std::is_same<T, unsigned short>::value && UINT64_SUBSET(unsigned short)) ||
                            (std::is_same<T, unsigned int>::value && UINT64_SUBSET(unsigned int)) ||
                            (std::is_same<T, unsigned long>::value && UINT64_SUBSET(unsigned long)) ||
                            (std::is_same<T, unsigned long long>::value && UINT64_SUBSET(unsigned long long));
};

#define ENABLE_IF_SIGNED(T) \
  template<typename T,      \
           typename = typename std::enable_if<util::int64_compat<T>::value>::type>

#define ENABLE_IF_UNSIGNED(T) \
  template<typename T,        \
           typename = typename std::enable_if<util::uint64_compat<T>::value>::type, typename = void>

#define ENABLE_IF_INTEGRAL(T) \
  template<typename T,        \
           typename = typename std::enable_if<util::int64_compat<T>::value || util::uint64_compat<T>::value>::type>

#define ASSERT_SIGNED(T) \
  static_assert(util::int64_compat<T>::value, \
               "internal error: selected type is not int64 compatible")

#define ASSERT_UNSIGNED(T) \
  static_assert(util::uint64_compat<T>::value, \
               "internal error: selected type is not uint64 compatible")

#define ASSERT_INTEGRAL(T) \
  static_assert(util::int64_compat<T>::value || util::uint64_compat<T>::value, \
               "internal error: selected type is not a suitable integer type")
}  // namespace util


/******************************************************************************/
/*                              Decimal object                                */
/******************************************************************************/

constexpr mpd_ssize_t MINALLOC = 4;

class Decimal {
 private:
  mpd_uint_t data[MINALLOC] = {0};

  mpd_t value {
    MPD_STATIC|MPD_STATIC_DATA|MPD_SNAN, /* flags */
    0,                                   /* exp */
    0,                                   /* digits */
    0,                                   /* len */
    MINALLOC,                            /* alloc */
    data                                 /* data */
  };

  /* mpd_t accessors */
  ALWAYS_INLINE bool isstatic() const { return value.data == data; }

  /* Reset rhs to snan after moving data to lhs */
  ALWAYS_INLINE void reset() {
    value = {
      MPD_STATIC|MPD_STATIC_DATA|MPD_SNAN, /* flags */
      0,                                   /* exp */
      0,                                   /* digits */
      0,                                   /* len */
      MINALLOC,                            /* alloc */
      data                                 /* data */
    };
  }

  /* Copy flags, preserving memory attributes of result */
  ALWAYS_INLINE uint8_t
  copy_flags(const uint8_t rflags, const uint8_t aflags) {
      return (rflags & (MPD_STATIC|MPD_DATAFLAGS)) |
             (aflags & ~(MPD_STATIC|MPD_DATAFLAGS));
  }

  ALWAYS_INLINE void
  copy_value(const mpd_t *const src, const bool fastcopy) {
    assert(mpd_isstatic(&value));
    assert(mpd_isstatic(src));
    assert(value.alloc >= MINALLOC);
    assert(src->alloc >= MINALLOC);
    assert(MPD_MINALLOC == MINALLOC);
    if (fastcopy) {
      value.data[0] = src->data[0];
      value.data[1] = src->data[1];
      value.data[2] = src->data[2];
      value.data[3] = src->data[3];
      value.flags = copy_flags(value.flags, src->flags);
      value.exp = src->exp;
      value.digits = src->digits;
      value.len = src->len;
    } else {
      if (!mpd_qcopy_cxx(&value, src)) {
        context.raise(MPD_Malloc_error);
      }
    }
  }

  ALWAYS_INLINE void
  move_value(const mpd_t *const src, const bool fastcopy) {
    assert(mpd_isstatic(&value));
    assert(mpd_isstatic(src));
    assert(value.alloc >= MINALLOC);
    assert(src->alloc >= MINALLOC);
    assert(MPD_MINALLOC == MINALLOC);
    if (fastcopy) {
      value.data[0] = src->data[0];
      value.data[1] = src->data[1];
      value.data[2] = src->data[2];
      value.data[3] = src->data[3];
      value.flags = copy_flags(value.flags, src->flags);
      value.exp = src->exp;
      value.digits = src->digits;
      value.len = src->len;
    }
    else {
      assert(mpd_isdynamic_data(src));
      if (mpd_isdynamic_data(&value)) {
        mpd_free(value.data);
      }
      value = *src;
      assert(mpd_isstatic(&value));
      assert(mpd_isdynamic_data(&value));
    }
  }

  ALWAYS_INLINE Decimal unary_func_status(
    int (* func)(mpd_t *, const mpd_t *, uint32_t *)) const {
      Decimal result;
      uint32_t status = 0;
      if (!func(result.get(), getconst(), &status)) {
          throw MallocError("out of memory");
      }
      return result;
  }

  ALWAYS_INLINE Decimal unary_func(
    void (* func)(mpd_t *, const mpd_t *, const mpd_context_t *, uint32_t *),
    Context& c=context) const {
      Decimal result;
      uint32_t status = 0;
      func(result.get(), getconst(), c.getconst(), &status);
      c.raise(status);
      return result;
  }

  ALWAYS_INLINE Decimal binary_func_noctx(
    int (* func)(mpd_t *, const mpd_t *, const mpd_t *),
    const Decimal& other) const {
      Decimal result;
      (void)func(result.get(), getconst(), other.getconst());
      return result;
  }

  ALWAYS_INLINE Decimal int_binary_func(
    int (* func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_context_t *, uint32_t *),
    const Decimal& other,
    Context& c=context) const {
      Decimal result;
      uint32_t status = 0;
      (void)func(result.get(), getconst(), other.getconst(), c.getconst(), &status);
      c.raise(status);
      return result;
  }

  ALWAYS_INLINE Decimal binary_func(
    void (* func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_context_t *, uint32_t *),
    const Decimal& other,
    Context& c=context) const {
      Decimal result;
      uint32_t status = 0;
      func(result.get(), getconst(), other.getconst(), c.getconst(), &status);
      c.raise(status);
      return result;
  }

  ALWAYS_INLINE Decimal& inplace_binary_func(
    void (* func)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_context_t *, uint32_t *),
    const Decimal& other,
    Context& c=context) {
      uint32_t status = 0;
      func(get(), getconst(), other.getconst(), c.getconst(), &status);
      c.raise(status);
      return *this;
  }

  ALWAYS_INLINE Decimal inplace_shiftl(const int64_t n, Context& c=context) {
    uint32_t status = 0;
    mpd_ssize_t nn = util::safe_downcast<mpd_ssize_t, int64_t>(n);
    mpd_qshiftl(get(), getconst(), nn, &status);
    c.raise(status);
    return *this;
  }

  ALWAYS_INLINE Decimal inplace_shiftr(const int64_t n, Context& c=context) {
    uint32_t status = 0;
    mpd_ssize_t nn = util::safe_downcast<mpd_ssize_t, int64_t>(n);
    mpd_qshiftr(get(), getconst(), nn, &status);
    c.raise(status);
    return *this;
  }

 public:
  /***********************************************************************/
  /*               Exact conversions regardless of context               */
  /***********************************************************************/

  /* Implicit */
  Decimal() noexcept = default;
  Decimal(const Decimal& other) { *this = other; }
  Decimal(Decimal&& other) noexcept { *this = std::move(other); }

  ENABLE_IF_SIGNED(T)
  Decimal(const T& other) {
    ASSERT_SIGNED(T);
    uint32_t status = 0;
    mpd_qset_i64_exact(&value, other, &status);
    context.raise(status, &value, isstatic());
  }

  ENABLE_IF_UNSIGNED(T)
  Decimal(const T& other) {
    ASSERT_UNSIGNED(T);
    uint32_t status = 0;
    mpd_qset_u64_exact(&value, other, &status);
    context.raise(status, &value, isstatic());
  }

  /* Explicit */
  explicit Decimal(const char * const s) {
    uint32_t status = 0;
    if (s == nullptr) {
      throw ValueError("Decimal: string argument in constructor is NULL");
    }
    mpd_qset_string_exact(&value, s, &status);
    context.raise(status, &value, isstatic());
  }

  explicit Decimal(const std::string& s) {
    uint32_t status = 0;
    mpd_qset_string_exact(&value, s.c_str(), &status);
    context.raise(status, &value, isstatic());
  }

  explicit Decimal(const mpd_uint128_triple_t& triple) {
    uint32_t status = 0;
    if (mpd_from_uint128_triple(&value, &triple, &status) < 0) {
      context.raise(status, &value, isstatic());
    }
  }

  /***********************************************************************/
  /*                Inexact conversions that use a context               */
  /***********************************************************************/
  explicit Decimal(const Decimal& other, Context& c) {
    const mpd_context_t *ctx = c.getconst();

    *this = other;

    if (mpd_isnan(&value) && value.digits > ctx->prec - ctx->clamp) {
      /* Special case:  too many NaN payload digits */
      mpd_setspecial(&value, MPD_POS, MPD_NAN);
      c.raise(MPD_Conversion_syntax, &value, isstatic());
    }
    else {
      uint32_t status = 0;
      mpd_qfinalize(&value, ctx, &status);
      c.raise(status, &value, isstatic());
    }
  }

  ENABLE_IF_SIGNED(T)
  explicit Decimal(const T& other, Context& c) {
    ASSERT_SIGNED(T);
    uint32_t status = 0;
    mpd_qset_i64(&value, other, c.getconst(), &status);
    c.raise(status, &value, isstatic());
  }

  ENABLE_IF_UNSIGNED(T)
  explicit Decimal(const T& other, Context& c) {
    ASSERT_UNSIGNED(T);
    uint32_t status = 0;
    mpd_qset_u64(&value, other, c.getconst(), &status);
    c.raise(status, &value, isstatic());
  }

  explicit Decimal(const char * const s, Context& c) {
    uint32_t status = 0;
    if (s == nullptr) {
      throw ValueError("Decimal: string argument in constructor is NULL");
    }
    mpd_qset_string(&value, s, c.getconst(), &status);
    c.raise(status, &value, isstatic());
  }

  explicit Decimal(const std::string& s, Context& c) {
    uint32_t status = 0;
    mpd_qset_string(&value, s.c_str(), c.getconst(), &status);
    c.raise(status, &value, isstatic());
  }

  /***********************************************************************/
  /*                              Accessors                              */
  /***********************************************************************/
  ALWAYS_INLINE mpd_t *get() { return &value; }
  ALWAYS_INLINE const mpd_t *getconst() const { return &value; }
  ALWAYS_INLINE int sign() const { return mpd_isnegative(&value) ? -1 : 1; }

  ALWAYS_INLINE Decimal coeff() const {
    if (isspecial()) {
      throw ValueError("coefficient is undefined for special values");
    }

    Decimal result = *this;
    mpd_set_positive(&result.value);
    result.value.exp = 0;
    return result;
  }

  ALWAYS_INLINE int64_t exponent() const {
    if (isspecial()) {
      throw ValueError("exponent is undefined for special values");
    }

    return value.exp;
  }

  ALWAYS_INLINE Decimal payload() const {
    if (!isnan()) {
      throw ValueError("payload is only defined for NaNs");
    }
    if (value.len == 0) {
      return Decimal(0);
    }

    Decimal result = *this;
    mpd_set_flags(&result.value, 0);
    result.value.exp = 0;
    return result;
  }

  /***********************************************************************/
  /*                             Destructor                              */
  /***********************************************************************/
  ~Decimal() { if (value.data != data) mpd_del(&value); }

  /***********************************************************************/
  /*                         Assignment operators                        */
  /***********************************************************************/
  ALWAYS_INLINE Decimal& operator= (const Decimal& other) {
    copy_value(other.getconst(), other.isstatic());
    return *this;
  }

  ALWAYS_INLINE Decimal& operator= (Decimal&& other) noexcept {
    if (this != &other) {
      move_value(other.getconst(), other.isstatic());
      other.reset();
    }
    return *this;
  }

  ALWAYS_INLINE Decimal& operator+= (const Decimal& other) { return inplace_binary_func(mpd_qadd, other); }
  ALWAYS_INLINE Decimal& operator-= (const Decimal& other) { return inplace_binary_func(mpd_qsub, other); }
  ALWAYS_INLINE Decimal& operator*= (const Decimal& other) { return inplace_binary_func(mpd_qmul, other); }
  ALWAYS_INLINE Decimal& operator/= (const Decimal& other) { return inplace_binary_func(mpd_qdiv, other); }
  ALWAYS_INLINE Decimal& operator%= (const Decimal& other) { return inplace_binary_func(mpd_qrem, other); }

  /***********************************************************************/
  /*                         Comparison operators                        */
  /***********************************************************************/
  ALWAYS_INLINE bool operator== (const Decimal& other) const {
    uint32_t status = 0;
    const int r = mpd_qcmp(getconst(), other.getconst(), &status);
    if (r == INT_MAX) {
      if (issnan() || other.issnan()) {
        context.raise(status);
      }
      return false;
    }
    return r == 0;
  }

  ALWAYS_INLINE bool operator!= (const Decimal& other) const {
    uint32_t status = 0;
    const int r = mpd_qcmp(getconst(), other.getconst(), &status);
    if (r == INT_MAX) {
      if (issnan() || other.issnan()) {
          context.raise(status);
      }
      return true;
    }
    return r != 0;
  }

  ALWAYS_INLINE bool operator< (const Decimal& other) const {
    uint32_t status = 0;
    const int r = mpd_qcmp(getconst(), other.getconst(), &status);
    if (r == INT_MAX) {
      context.raise(status);
      return false;
    }
    return r < 0;
  }

  ALWAYS_INLINE bool operator<= (const Decimal& other) const {
    uint32_t status = 0;
    const int r = mpd_qcmp(getconst(), other.getconst(), &status);
    if (r == INT_MAX) {
      context.raise(status);
      return false;
    }
    return r <= 0;
  }

  ALWAYS_INLINE bool operator>= (const Decimal& other) const {
    uint32_t status = 0;
    const int r = mpd_qcmp(getconst(), other.getconst(), &status);
    if (r == INT_MAX) {
      context.raise(status);
      return false;
    }
    return r >= 0;
  }

  ALWAYS_INLINE bool operator> (const Decimal& other) const {
    uint32_t status = 0;
    const int r = mpd_qcmp(getconst(), other.getconst(), &status);
    if (r == INT_MAX) {
      context.raise(status);
      return false;
    }
    return r > 0;
  }

  /***********************************************************************/
  /*                      Unary arithmetic operators                     */
  /***********************************************************************/
  ALWAYS_INLINE Decimal operator- () const { return unary_func(mpd_qminus); }
  ALWAYS_INLINE Decimal operator+ () const { return unary_func(mpd_qplus); }

  /***********************************************************************/
  /*                      Binary arithmetic operators                    */
  /***********************************************************************/
  ALWAYS_INLINE Decimal operator+ (const Decimal& other) const { return binary_func(mpd_qadd, other); }
  ALWAYS_INLINE Decimal operator- (const Decimal& other) const { return binary_func(mpd_qsub, other); }
  ALWAYS_INLINE Decimal operator* (const Decimal& other) const { return binary_func(mpd_qmul, other); }
  ALWAYS_INLINE Decimal operator/ (const Decimal& other) const { return binary_func(mpd_qdiv, other); }
  ALWAYS_INLINE Decimal operator% (const Decimal& other) const { return binary_func(mpd_qrem, other); }

  /***********************************************************************/
  /*                             Predicates                              */
  /***********************************************************************/
  /* Predicates, no context arg */
  ALWAYS_INLINE bool iscanonical() const { return mpd_iscanonical(getconst()); }
  ALWAYS_INLINE bool isfinite() const { return mpd_isfinite(getconst()); }
  ALWAYS_INLINE bool isinfinite() const { return mpd_isinfinite(getconst()); }
  ALWAYS_INLINE bool isspecial() const { return mpd_isspecial(getconst()); }
  ALWAYS_INLINE bool isnan() const { return mpd_isnan(getconst()); }
  ALWAYS_INLINE bool isqnan() const { return mpd_isqnan(getconst()); }
  ALWAYS_INLINE bool issnan() const { return mpd_issnan(getconst()); }
  ALWAYS_INLINE bool issigned() const { return mpd_issigned(getconst()); }
  ALWAYS_INLINE bool iszero() const { return mpd_iszero(getconst()); }
  ALWAYS_INLINE bool isinteger() const { return mpd_isinteger(getconst()); }

  /* Predicates, optional context arg */
  ALWAYS_INLINE bool isnormal(const Context& c=context) const { return mpd_isnormal(getconst(), c.getconst()); }
  ALWAYS_INLINE bool issubnormal(const Context& c=context) const { return mpd_issubnormal(getconst(), c.getconst()); }

  /***********************************************************************/
  /*                           Unary functions                           */
  /***********************************************************************/
  /* Unary functions, no context arg */
  ALWAYS_INLINE int64_t adjexp() const {
    if (isspecial()) {
      throw ValueError("adjusted exponent undefined for special values");
    }
    return mpd_adjexp(getconst());
  }

  ALWAYS_INLINE Decimal canonical() const { return *this; }
  ALWAYS_INLINE Decimal copy() const { return unary_func_status(mpd_qcopy); }
  ALWAYS_INLINE Decimal copy_abs() const { return unary_func_status(mpd_qcopy_abs); }
  ALWAYS_INLINE Decimal copy_negate() const { return unary_func_status(mpd_qcopy_negate); }

  /* Unary functions, optional context arg */
  ALWAYS_INLINE std::string number_class(Context& c=context) const { return mpd_class(getconst(), c.getconst()); }

  ALWAYS_INLINE Decimal abs(Context& c=context) const { return unary_func(mpd_qabs, c); }
  ALWAYS_INLINE Decimal ceil(Context& c=context) const { return unary_func(mpd_qceil, c); }
  ALWAYS_INLINE Decimal exp(Context& c=context) const { return unary_func(mpd_qexp, c); }
  ALWAYS_INLINE Decimal floor(Context& c=context) const { return unary_func(mpd_qfloor, c); }
  ALWAYS_INLINE Decimal invroot(Context& c=context) const { return unary_func(mpd_qinvroot, c); }
  ALWAYS_INLINE Decimal logical_invert(Context& c=context) const { return unary_func(mpd_qinvert, c); }
  ALWAYS_INLINE Decimal ln(Context& c=context) const { return unary_func(mpd_qln, c); }
  ALWAYS_INLINE Decimal log10(Context& c=context) const { return unary_func(mpd_qlog10, c); }
  ALWAYS_INLINE Decimal logb(Context& c=context) const { return unary_func(mpd_qlogb, c); }
  ALWAYS_INLINE Decimal minus(Context& c=context) const { return unary_func(mpd_qminus, c); }
  ALWAYS_INLINE Decimal next_minus(Context& c=context) const { return unary_func(mpd_qnext_minus, c); }
  ALWAYS_INLINE Decimal next_plus(Context& c=context) const { return unary_func(mpd_qnext_plus, c); }
  ALWAYS_INLINE Decimal plus(Context& c=context) const { return unary_func(mpd_qplus, c); }
  ALWAYS_INLINE Decimal reduce(Context& c=context) const { return unary_func(mpd_qreduce, c); }
  ALWAYS_INLINE Decimal to_integral(Context& c=context) const { return unary_func(mpd_qround_to_int, c); }
  ALWAYS_INLINE Decimal to_integral_exact(Context& c=context) const { return unary_func(mpd_qround_to_intx, c); }
  ALWAYS_INLINE Decimal sqrt(Context& c=context) const { return unary_func(mpd_qsqrt, c); }
  ALWAYS_INLINE Decimal trunc(Context& c=context) const { return unary_func(mpd_qtrunc, c); }

  /***********************************************************************/
  /*                           Binary functions                          */
  /***********************************************************************/
  /* Binary functions, no context arg */
  ALWAYS_INLINE Decimal compare_total(const Decimal& other) const { return binary_func_noctx(mpd_compare_total, other); }
  ALWAYS_INLINE Decimal compare_total_mag(const Decimal& other) const { return binary_func_noctx(mpd_compare_total_mag, other); }

  /* Binary arithmetic functions, optional context arg */
  ALWAYS_INLINE Decimal add(const Decimal& other, Context& c=context) const { return binary_func(mpd_qadd, other, c); }
  ALWAYS_INLINE Decimal div(const Decimal& other, Context& c=context) const { return binary_func(mpd_qdiv, other, c); }
  ALWAYS_INLINE Decimal divint(const Decimal& other, Context& c=context) const { return binary_func(mpd_qdivint, other, c); }
  ALWAYS_INLINE Decimal compare(const Decimal& other, Context& c=context) const { return int_binary_func(mpd_qcompare, other, c); }
  ALWAYS_INLINE Decimal compare_signal(const Decimal& other, Context& c=context) const { return int_binary_func(mpd_qcompare_signal, other, c); }
  ALWAYS_INLINE Decimal logical_and(const Decimal& other, Context& c=context) const { return binary_func(mpd_qand, other, c); }
  ALWAYS_INLINE Decimal logical_or(const Decimal& other, Context& c=context) const { return binary_func(mpd_qor, other, c); }
  ALWAYS_INLINE Decimal logical_xor(const Decimal& other, Context& c=context) const { return binary_func(mpd_qxor, other, c); }
  ALWAYS_INLINE Decimal max(const Decimal& other, Context& c=context) const { return binary_func(mpd_qmax, other, c); }
  ALWAYS_INLINE Decimal max_mag(const Decimal& other, Context& c=context) const { return binary_func(mpd_qmax_mag, other, c); }
  ALWAYS_INLINE Decimal min(const Decimal& other, Context& c=context) const { return binary_func(mpd_qmin, other, c); }
  ALWAYS_INLINE Decimal min_mag(const Decimal& other, Context& c=context) const { return binary_func(mpd_qmin_mag, other, c); }
  ALWAYS_INLINE Decimal mul(const Decimal& other, Context& c=context) const { return binary_func(mpd_qmul, other, c); }
  ALWAYS_INLINE Decimal next_toward(const Decimal& other, Context& c=context) const { return binary_func(mpd_qnext_toward, other, c); }
  ALWAYS_INLINE Decimal pow(const Decimal& other, Context& c=context) const { return binary_func(mpd_qpow, other, c); }
  ALWAYS_INLINE Decimal quantize(const Decimal& other, Context& c=context) const { return binary_func(mpd_qquantize, other, c); }
  ALWAYS_INLINE Decimal rem(const Decimal& other, Context& c=context) const { return binary_func(mpd_qrem, other, c); }
  ALWAYS_INLINE Decimal rem_near(const Decimal& other, Context& c=context) const { return binary_func(mpd_qrem_near, other, c); }
  ALWAYS_INLINE Decimal rotate(const Decimal& other, Context& c=context) const { return binary_func(mpd_qrotate, other, c); }
  ALWAYS_INLINE Decimal scaleb(const Decimal& other, Context& c=context) const { return binary_func(mpd_qscaleb, other, c); }
  ALWAYS_INLINE Decimal shift(const Decimal& other, Context& c=context) const { return binary_func(mpd_qshift, other, c); }
  ALWAYS_INLINE Decimal sub(const Decimal& other, Context& c=context) const { return binary_func(mpd_qsub, other, c); }

  /* Binary arithmetic function, two return values */
  ALWAYS_INLINE std::pair<Decimal, Decimal> divmod(const Decimal& other, Context& c=context) const {
    std::pair<Decimal, Decimal> result;
    uint32_t status = 0;
    mpd_qdivmod(result.first.get(), result.second.get(), getconst(), other.getconst(), c.getconst(), &status);
    c.raise(status);
    return result;
  }

  /***********************************************************************/
  /*                          Ternary functions                          */
  /***********************************************************************/
  ALWAYS_INLINE Decimal fma(const Decimal& other, const Decimal& third, Context& c=context) const {
    Decimal result;
    uint32_t status = 0;
    mpd_qfma(result.get(), getconst(), other.getconst(), third.getconst(), c.getconst(), &status);
    c.raise(status);
    return result;
  }

  ALWAYS_INLINE Decimal powmod(const Decimal& other, const Decimal& third, Context& c=context) const {
    Decimal result;
    uint32_t status = 0;
    mpd_qpowmod(result.get(), getconst(), other.getconst(), third.getconst(), c.getconst(), &status);
    c.raise(status);
    return result;
  }

  /***********************************************************************/
  /*                         Irregular functions                         */
  /***********************************************************************/
  ALWAYS_INLINE Decimal apply(Context& c=context) const {
    Decimal result = *this;
    uint32_t status = 0;

    mpd_qfinalize(result.get(), c.getconst(), &status);
    c.raise(status);
    return result;
  }

  ALWAYS_INLINE int cmp(const Decimal& other) const {
    uint32_t status = 0;
    return mpd_qcmp(getconst(), other.getconst(), &status);
  }

  ALWAYS_INLINE int cmp_total(const Decimal& other) const {
    return mpd_cmp_total(getconst(), other.getconst());
  }

  ALWAYS_INLINE int cmp_total_mag(const Decimal& other) const {
    return mpd_cmp_total_mag(getconst(), other.getconst());
  }

  ALWAYS_INLINE Decimal copy_sign(const Decimal& other) const {
    Decimal result;
    uint32_t status = 0;
    if (!mpd_qcopy_sign(result.get(), getconst(), other.getconst(), &status)) {
      throw MallocError("out of memory");
    }
    return result;
  }

  ALWAYS_INLINE Decimal rescale(const int64_t exp, Context& c=context) const {
    Decimal result;
    uint32_t status = 0;
    mpd_ssize_t xexp = util::safe_downcast<mpd_ssize_t, int64_t>(exp);
    mpd_qrescale(result.get(), getconst(), xexp, c.getconst(), &status);
    c.raise(status);
    return result;
  }

  ALWAYS_INLINE bool same_quantum(const Decimal& other) const {
    return mpd_same_quantum(getconst(), other.getconst());
  }

  ALWAYS_INLINE Decimal shiftn(const int64_t n, Context& c=context) const {
    Decimal result;
    uint32_t status = 0;
    mpd_ssize_t nn = util::safe_downcast<mpd_ssize_t, int64_t>(n);
    mpd_qshiftn(result.get(), getconst(), nn, c.getconst(), &status);
    c.raise(status);
    return result;
  }

  ALWAYS_INLINE Decimal shiftl(const int64_t n, Context& c=context) const {
    Decimal result;
    uint32_t status = 0;
    if (isspecial()) {
      throw ValueError("shiftl: cannot handle special numbers");
    }
    if (n < 0 || n > MPD_MAX_PREC - getconst()->digits) {
      throw ValueError("shiftl: shift is negative or too large");
    }
    mpd_ssize_t nn = util::safe_downcast<mpd_ssize_t, int64_t>(n);
    mpd_qshiftl(result.get(), getconst(), nn, &status);
    c.raise(status);
    return result;
  }

  ALWAYS_INLINE Decimal shiftr(const int64_t n, Context& c=context) const {
    Decimal result;
    uint32_t status = 0;
    if (isspecial()) {
      throw ValueError("shiftr: cannot handle special numbers");
    }
    if (n < 0) {
      throw ValueError("shiftr: shift is negative");
    }
    mpd_ssize_t nn = util::safe_downcast<mpd_ssize_t, int64_t>(n);
    mpd_qshiftr(result.get(), getconst(), nn, &status);
    c.raise(status);
    return result;
  }

  IMPORTEXPORT static Decimal exact(const char *s, Context& c);
  IMPORTEXPORT static Decimal exact(const std::string& s, Context& c);
  IMPORTEXPORT static Decimal ln10(int64_t n, Context& c=context);
  IMPORTEXPORT static int32_t radix();

  /***********************************************************************/
  /*                          Integer conversion                         */
  /***********************************************************************/
  ALWAYS_INLINE int64_t i64() const {
    uint32_t status = 0;
    const int64_t result = mpd_qget_i64(getconst(), &status);
    if (status) {
      throw ValueError("cannot convert to int64_t");
    }
    return result;
  }

  ALWAYS_INLINE int32_t i32() const {
    uint32_t status = 0;
    const int32_t result = mpd_qget_i32(getconst(), &status);
    if (status) {
      throw ValueError("cannot convert to int32_t");
    }
    return result;
  }

  ALWAYS_INLINE uint64_t u64() const {
    uint32_t status = 0;
    const uint64_t result = mpd_qget_u64(getconst(), &status);
    if (status) {
      throw ValueError("cannot convert to uint64_t");
    }
    return result;
  }

  ALWAYS_INLINE uint32_t u32() const {
    uint32_t status = 0;
    const uint32_t result = mpd_qget_u32(getconst(), &status);
    if (status) {
      throw ValueError("cannot convert to uint32_t");
    }
    return result;
  }

  /***********************************************************************/
  /*                           Triple conversion                         */
  /***********************************************************************/
  ALWAYS_INLINE mpd_uint128_triple_t as_uint128_triple() const {
    return mpd_as_uint128_triple(getconst());
  }

  /***********************************************************************/
  /*                          String conversion                          */
  /***********************************************************************/
  /* String representations */
  IMPORTEXPORT std::string repr(bool capitals=true) const;

  inline std::string to_sci(bool capitals=true) const {
    const char *cp = mpd_to_sci(getconst(), capitals);
    if (cp == nullptr) {
      throw MallocError("out of memory");
    }

    return util::string_from_cp(cp);
  }

  inline std::string to_eng(bool capitals=true) const {
    const char *cp = mpd_to_eng(getconst(), capitals);
    if (cp == nullptr) {
      throw MallocError("out of memory");
    }

    return util::string_from_cp(cp);
  }

  inline std::string format(const char *fmt, const Context& c=context) const {
    uint32_t status = 0;
    mpd_context_t ctx;

    if (fmt == nullptr) {
      throw ValueError("Decimal.format: fmt argument is NULL");
    }

    mpd_maxcontext(&ctx);
    ctx.round = c.getconst()->round;
    ctx.traps = 0;

    const char *cp = mpd_qformat(getconst(), fmt, &ctx, &status);
    if (cp == nullptr) {
      if (status & MPD_Malloc_error) {
        throw MallocError("out of memory");
      }
      else if (status & MPD_Invalid_operation) {
        throw ValueError("invalid format string");
      }
      else {
        throw RuntimeError("internal error: unexpected status");
      }
    }

    return util::string_from_cp(cp);
  }

  inline std::string format(const std::string& s, const Context& c=context) const {
    return format(s.c_str(), c);
  }

  IMPORTEXPORT friend std::ostream& operator<< (std::ostream& os, const Decimal& dec);
};

/***********************************************************************/
/*                      Reverse comparison operators                   */
/***********************************************************************/
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE bool operator==(const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) == self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE bool operator!= (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) != self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE bool operator< (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) < self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE bool operator<= (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) <= self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE bool operator>= (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) >= self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE bool operator> (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) > self; }

/***********************************************************************/
/*                      Reverse arithmetic operators                   */
/***********************************************************************/
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE Decimal operator+ (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) + self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE Decimal operator- (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) - self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE Decimal operator* (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) * self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE Decimal operator/ (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) / self; }
ENABLE_IF_INTEGRAL(T) ALWAYS_INLINE Decimal operator% (const T& other, const Decimal& self) { ASSERT_INTEGRAL(T); return Decimal(other) % self; }


#undef IMPORTEXPORT
#undef ALWAYS_INLINE
#undef INT64_SUBSET
#undef UINT64_SUBSET
#undef ENABLE_IF_SIGNED
#undef ENABLE_IF_UNSIGNED
#undef ENABLE_IF_INTEGRAL
#undef ASSERT_SIGNED
#undef ASSERT_UNSIGNED
#undef ASSERT_INTEGRAL
}  // namespace decimal


#endif  // LIBMPDECXX_DECIMAL_HH_
