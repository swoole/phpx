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


#include <cstdint>

#include <iostream>
#include <sstream>
#include <stdexcept>

#include "mpdecimal.h"
#include "decimal.hh"


/*****************************************************************************/
/*                               Library init                                */
/*****************************************************************************/

namespace {
class LibraryInit {
 public:
  LibraryInit() { mpd_setminalloc(decimal::MINALLOC); }
};

const LibraryInit init;
}  // namespace


/*****************************************************************************/
/*                                  Context                                  */
/*****************************************************************************/

namespace {

typedef struct {
  const uint32_t flag;
  const char *name;
  const char *fqname;
  void (* const raise)(const std::string& msg);
} cmap;

template<typename T>
void
raise(const std::string& msg)
{
  throw T(msg);
}

const cmap signal_map[] = {
  { MPD_IEEE_Invalid_operation, "IEEEInvalidOperation", "decimal::IEEEInvalidOperation", raise<decimal::IEEEInvalidOperation> },
  { MPD_Division_by_zero, "DivisionByZero", "decimal::DivisionByZero", raise<decimal::DivisionByZero> },
  { MPD_Overflow, "Overflow", "decimal::Overflow", raise<decimal::Overflow> },
  { MPD_Underflow, "Underflow", "decimal::Underflow", raise<decimal::Underflow> },
  { MPD_Subnormal, "Subnormal", "decimal::Subnormal", raise<decimal::Subnormal> },
  { MPD_Inexact, "Inexact", "decimal::Inexact", raise<decimal::Inexact> },
  { MPD_Rounded, "Rounded", "decimal::Rounded", raise<decimal::Rounded> },
  { MPD_Clamped, "Clamped", "decimal::Clamped", raise<decimal::Clamped> },
  { UINT32_MAX, nullptr, nullptr, nullptr }
};

const cmap cond_map[] = {
  { MPD_Invalid_operation, "InvalidOperation", "decimal::InvalidOperation", raise<decimal::InvalidOperation> },
  { MPD_Conversion_syntax, "ConversionSyntax", "decimal::ConversionSyntax", raise<decimal::ConversionSyntax> },
  { MPD_Division_impossible, "DivisionImpossible", "decimal::DivisionImpossible", raise<decimal::DivisionImpossible> },
  { MPD_Division_undefined, "DivisionUndefined", "decimal::DivisionUndefined", raise<decimal::DivisionUndefined> },
  { UINT32_MAX, nullptr, nullptr, nullptr }
};

std::string
signals(const uint32_t flags)
{
  std::string s;
  s.reserve(MPD_MAX_SIGNAL_LIST);

  s += "[";
  for (const cmap *c = signal_map; c->flag != UINT32_MAX;  c++) {
    if (flags & c->flag) {
      if (s != "[") {
        s += ", ";
      }
      s += c->name;
    }
  }

  s += "]";

  return s;
}

std::string
flags(const uint32_t flags)
{
  std::string s;
  s.reserve(MPD_MAX_FLAG_LIST);

  s += "[";

  for (const cmap *c = cond_map; c->flag != UINT32_MAX;  c++) {
    if (flags & c->flag) {
      if (s != "[") {
        s += ", ";
      }
      s += c->name;
    }
  }

  for (const cmap *c = signal_map+1; c->flag != UINT32_MAX;  c++) {
    if (flags & c->flag) {
      if (s != "[") {
        s += ", ";
      }
      s += c->name;
    }
  }

  s += "]";

  return s;
}

/* Context for exact calculations with (practically) unbounded precision. */
const decimal::Context maxcontext {
  MPD_MAX_PREC,
  MPD_MAX_EMAX,
  MPD_MIN_EMIN,
  MPD_ROUND_HALF_EVEN,
  MPD_IEEE_Invalid_operation,
  0,
  0
};

}  // namespace


/*****************************************************************************/
/*                                Context API                                */
/*****************************************************************************/

namespace decimal {

/* Used for default initialization of new contexts such as TLS contexts. */
Context context_template {
  16,                                                            /* prec */
  999999,                                                        /* emax */
  -999999,                                                       /* emin */
  MPD_ROUND_HALF_EVEN,                                           /* rounding */
  MPD_IEEE_Invalid_operation|MPD_Division_by_zero|MPD_Overflow,  /* traps */
  0,                                                             /* clamp */
  1                                                              /* allcr */
};

#if defined(__OpenBSD__) || defined(__sun) || defined(_MSC_VER) && defined(_DLL)
Context& getcontext() {
  static thread_local Context _context{context_template};
  return _context;
}
#else
thread_local Context context{context_template};
#endif

/* Factory function for creating a context for maximum unrounded arithmetic. */
Context
MaxContext()
{
    return Context(maxcontext);
}

/* Factory function for creating IEEE interchange format contexts. */
Context
IEEEContext(int bits)
{
  mpd_context_t ctx;

  if (mpd_ieee_context(&ctx, bits) < 0) {
    throw ValueError("argument must be a multiple of 32, with a maximum of " +
                     std::to_string(MPD_IEEE_CONTEXT_MAX_BITS));
  }

  return Context(ctx);
}

void
Context::raiseit(const uint32_t status)
{
  if (status & MPD_Malloc_error) {
    throw MallocError("out of memory");
  }

  const std::string msg = flags(status);
  for (const cmap *c = cond_map; c->flag != UINT32_MAX;  c++) {
    if (status & c->flag) {
      c->raise(msg);
    }
  }

  for (const cmap *c = signal_map+1; c->flag != UINT32_MAX;  c++) {
    if (status & c->flag) {
      c->raise(msg);
    }
  }

  throw RuntimeError("internal_error: unknown status flag");
}

std::string
Context::repr() const
{
  const int rounding = round();
  std::ostringstream ss;

  if (rounding < 0 || rounding >= MPD_ROUND_GUARD) {
    throw RuntimeError("internal_error: invalid rounding mode");
  }

  const char *round_str = mpd_round_string[rounding];

  ss << "Context(prec=" << prec() << ", " <<
                "emax=" << emax() << ", " <<
                "emin=" << emin() << ", " <<
                "round=" << round_str << ", " <<
                "clamp=" << clamp() << ", " <<
                "traps=" << signals(traps()) << ", " <<
                "status=" << signals(status()) <<
        ")";

  return ss.str();
}

std::ostream&
operator<<(std::ostream& os, const Context& c)
{
  os << c.repr();
  return os;
}


/*****************************************************************************/
/*                                Decimal API                                */
/*****************************************************************************/

Decimal
Decimal::exact(const char *const s, Context& c)
{
  Decimal result;
  uint32_t status = 0;

  if (s == nullptr) {
    throw ValueError("Decimal::exact: string argument is NULL");
  }

  mpd_qset_string_exact(result.get(), s, &status);
  c.raise(status);
  return result;
}

Decimal
Decimal::exact(const std::string& s, Context& c)
{
  return Decimal::exact(s.c_str(), c);
}

Decimal
Decimal::ln10(int64_t n, Context& c)
{
  Decimal result;
  uint32_t status = 0;

  if (n < 1 || n > MPD_MAX_PREC) {
    throw ValueError("Decimal::ln10: prec argument must in [1, MAX_PREC]");
  }

  mpd_ssize_t nn = util::safe_downcast<mpd_ssize_t, int64_t>(n);
  mpd_qln10(result.get(), nn, &status);

  c.raise(status);
  return result;
}

int32_t
Decimal::radix()
{
  return 10;
}
 
std::string
Decimal::repr(bool capitals) const
{
  std::string s = to_sci(capitals);

  return "Decimal(\"" + s + "\")";
}

std::ostream&
operator<<(std::ostream& os, const Decimal& dec)
{
  os << dec.to_sci();

  return os;
}

}  // namespace decimal
