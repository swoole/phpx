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


#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <limits>
#include <list>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

#include "mpdecimal.h"

#include "decimal.hh"
#include "test.hh"
#include "vctest.hh"


using decimal::Context;
using decimal::context_template;
using decimal::context;

using decimal::ROUND_UP;
using decimal::ROUND_DOWN;
using decimal::ROUND_CEILING;
using decimal::ROUND_FLOOR;
using decimal::ROUND_HALF_UP;
using decimal::ROUND_HALF_DOWN;
using decimal::ROUND_HALF_EVEN;
using decimal::ROUND_05UP;
using decimal::ROUND_TRUNC;
using decimal::ROUND_GUARD;

using decimal::DecIEEEInvalidOperation;
using decimal::DecConversionSyntax;
using decimal::DecInvalidOperation;
using decimal::DecDivisionImpossible;
using decimal::DecDivisionUndefined;

using decimal::DecDivisionByZero;
using decimal::DecOverflow;
using decimal::DecUnderflow;
using decimal::DecSubnormal;
using decimal::DecInexact;
using decimal::DecRounded;
using decimal::DecClamped;

using decimal::DecMaxStatus;

using decimal::MaxContext;
using decimal::IEEEContext;
using decimal::DECIMAL32;
using decimal::DECIMAL64;
using decimal::DECIMAL128;

using decimal::DecimalException;

using decimal::IEEEInvalidOperation;
using decimal::ConversionSyntax;
using decimal::InvalidOperation;
using decimal::DivisionImpossible;
using decimal::DivisionUndefined;

using decimal::DivisionByZero;
using decimal::Overflow;
using decimal::Underflow;
using decimal::Subnormal;
using decimal::Inexact;
using decimal::Rounded;
using decimal::Clamped;

using decimal::ValueError;
using decimal::RuntimeError;
using decimal::MallocError;

using decimal::Decimal;

using decimal::util::safe_downcast;

using test::Failure;


/******************************************************************************/
/*                Default context for some generated test cases               */
/******************************************************************************/

static const Context pycontext{ 28, 999999, -999999, ROUND_HALF_EVEN,
                                DecIEEEInvalidOperation | DecDivisionByZero | DecOverflow,
                                0, 0 };

/******************************************************************************/
/*                            Exception hierarchy                             */
/******************************************************************************/

static void
ExceptionHierarchyTest()
{
    assertEqual(context, context_template);

    assertTrue((std::is_base_of<std::exception, DecimalException>::value));

        assertTrue((std::is_base_of<DecimalException, IEEEInvalidOperation>::value));
            assertTrue((std::is_base_of<IEEEInvalidOperation, ConversionSyntax>::value));
            assertTrue((std::is_base_of<IEEEInvalidOperation, DivisionImpossible>::value));
            assertTrue((std::is_base_of<IEEEInvalidOperation, DivisionUndefined>::value));
            assertTrue((std::is_base_of<IEEEInvalidOperation, InvalidOperation>::value));

        assertTrue((std::is_base_of<DecimalException, DivisionByZero>::value));
        assertTrue((std::is_base_of<DecimalException, Overflow>::value));
        assertTrue((std::is_base_of<DecimalException, Underflow>::value));
        assertTrue((std::is_base_of<DecimalException, Subnormal>::value));
        assertTrue((std::is_base_of<DecimalException, Inexact>::value));
        assertTrue((std::is_base_of<DecimalException, Rounded>::value));
        assertTrue((std::is_base_of<DecimalException, Clamped>::value));

    assertTrue((std::is_base_of<std::exception, ValueError>::value));
    assertTrue((std::is_base_of<std::exception, RuntimeError>::value));
    assertTrue((std::is_base_of<std::exception, MallocError>::value));
}

/******************************************************************************/
/*                          IEEE interchange contexts                         */
/******************************************************************************/

static void
IEEEContextTest()
{
    assertEqual(context, context_template);

    Context c = IEEEContext(DECIMAL32);
    assertEqual(c.prec(), 7);
    assertEqual(c.emax(), 96);
    assertEqual(c.emin(), -95);
    assertEqual(c.round(), ROUND_HALF_EVEN);
    assertEqual(c.traps(), 0U);
    assertEqual(c.status(), 0U);
    assertEqual(c.clamp(), 1);
    assertEqual(c.allcr(), 1);
    assertEqual(c.etiny(), -101);
    assertEqual(c.etop(), 90);

    c = IEEEContext(DECIMAL64);
    assertEqual(c.prec(), 16);
    assertEqual(c.emax(), 384);
    assertEqual(c.emin(), -383);
    assertEqual(c.round(), ROUND_HALF_EVEN);
    assertEqual(c.traps(), 0U);
    assertEqual(c.status(), 0U);
    assertEqual(c.clamp(), 1);
    assertEqual(c.allcr(), 1);
    assertEqual(c.etiny(), -398);
    assertEqual(c.etop(), 369);

    c = IEEEContext(DECIMAL128);
    assertEqual(c.prec(), 34);
    assertEqual(c.emax(), 6144);
    assertEqual(c.emin(), -6143);
    assertEqual(c.round(), ROUND_HALF_EVEN);
    assertEqual(c.traps(), 0U);
    assertEqual(c.status(), 0U);
    assertEqual(c.clamp(), 1);
    assertEqual(c.allcr(), 1);
    assertEqual(c.etiny(), -6176);
    assertEqual(c.etop(), 6111);

    assertRaises(ValueError, [](){ IEEEContext(-1); });
    assertRaises(ValueError, [](){ IEEEContext(0); });
    assertRaises(ValueError, [](){ IEEEContext(16); });
    assertRaises(ValueError, [](){ IEEEContext(1024); });
}

/******************************************************************************/
/*                              Context get/set                               */
/******************************************************************************/

static void
ContextGetSetTest()
{
    assertEqual(context, context_template);

    Context c = context;

    c.prec(34);
    c.emax(3000);
    c.emin(-3000);
    c.round(ROUND_HALF_UP);
    c.traps(DecMaxStatus);
    c.status(DecMaxStatus);
    c.clamp(1);
    c.allcr(0);

    assertEqual(c.prec(), 34);
    assertEqual(c.emax(), 3000);
    assertEqual(c.emin(), -3000);
    assertEqual(c.round(), ROUND_HALF_UP);
    assertEqual(c.traps(), DecMaxStatus);
    assertEqual(c.status(), DecMaxStatus);
    assertEqual(c.clamp(), 1);
    assertEqual(c.allcr(), 0);
    assertEqual(c.etiny(), -3033);
    assertEqual(c.etop(), 2967);

    /* etop is the same, even though it is only relevant for clamp==1 */
    c.clamp(0);
    assertEqual(c.etiny(), -3033);
    assertEqual(c.etop(), 2967);

    c.clear_status(DecDivisionByZero);
    assertEqual(c.status(), DecMaxStatus & ~DecDivisionByZero);

    c.clear_status();
    assertEqual(c.status(), 0U);

    c.add_status(DecClamped|DecUnderflow);
    assertEqual(c.status(), DecClamped|DecUnderflow);

    c.add_status(DecInvalidOperation);
    assertEqual(c.status(), DecClamped|DecUnderflow|DecInvalidOperation);

    c.clear_traps(DecDivisionUndefined);
    assertEqual(c.traps(), DecMaxStatus & ~DecDivisionUndefined);

    c.clear_traps();
    assertEqual(c.traps(), 0U);

    c.add_traps(DecClamped|DecUnderflow);
    assertEqual(c.traps(), DecClamped|DecUnderflow);

    c.add_traps(DecInvalidOperation);
    assertEqual(c.traps(), DecClamped|DecUnderflow|DecInvalidOperation);
}


/******************************************************************************/
/*                          Context input validation                          */
/******************************************************************************/

static void
ContextInputValidationTest()
{
    assertEqual(context, context_template);

    Context c = context;

    /* prec */
    c.prec(1111);
    assertEqual(c.prec(), 1111);
    assertRaises(ValueError, [&](){ c.prec(-1); });
    assertRaises(ValueError, [&](){ c.prec(MPD_SSIZE_MAX); });

    /* emin */
    c.emin(-1111);
    assertEqual(c.emin(), -1111);
    assertRaises(ValueError, [&](){ c.emin(1); });
    assertRaises(ValueError, [&](){ c.emin(MPD_SSIZE_MIN); });

    /* emax */
    c.emax(1111);
    assertEqual(c.emax(), 1111);
    assertRaises(ValueError, [&](){ c.emax(-1); });
    assertRaises(ValueError, [&](){ c.emax(MPD_SSIZE_MAX); });

    /* round */
    assertRaises(ValueError, [&](){ c.round(-1); });
    assertRaises(ValueError, [&](){ c.round(ROUND_GUARD); });

    /* traps */
    assertRaises(ValueError, [&](){ c.traps(DecMaxStatus+1); });
    assertRaises(ValueError, [&](){ c.traps(UINT32_MAX); });

    /* clamp */
    assertRaises(ValueError, [&](){ c.clamp(-1); });
    assertRaises(ValueError, [&](){ c.clamp(2); });
    assertRaises(ValueError, [&](){ c.clamp(INT_MAX); });

    /* constructor */
    assertRaises(ValueError, [&](){ Context(1, 1, -1, 999999); });
}

/******************************************************************************/
/*                                Small context                               */
/******************************************************************************/

static void
SmallContextTest()
{
    assertEqual(context, context_template);

    Context &c = context;

    Context xc{pycontext};
    xc.prec(1);
    xc.emax(1);
    xc.emin(-1);

    assertEqual(Decimal(9, xc), 9);

    xc.clear_status();
    assertRaises(ConversionSyntax, [&](){ Decimal("xyz", xc); });
    assertEqual(xc.status(), DecConversionSyntax);
    assertEqual(c.status(), 0U);

    xc.clear_status();
    assertEqual(Decimal(2).exp(xc), 7);
    assertRaises(Overflow, [&](){ Decimal(8).exp(xc); });
    assertTrue(xc.status() & DecOverflow);
    assertEqual(c.status(), 0U);

    xc.clear_status();
    assertEqual(Decimal(2).ln(xc), Decimal("0.7"));
    assertRaises(InvalidOperation, [&](){ Decimal(-1).ln(xc); });
    assertTrue(xc.status() & DecInvalidOperation);
    assertFalse(c.status() & DecInvalidOperation);

    assertEqual(Decimal(0).log10(xc), Decimal("-inf"));
    assertEqual(Decimal(-1).next_minus(xc), -2);
    assertEqual(Decimal(-1).next_plus(xc), Decimal("-0.9"));
    assertEqual(Decimal("9.73").reduce(xc), Decimal("1E+1"));
    assertEqual(Decimal("9999").to_integral(xc), 9999);
    assertEqual(Decimal("-2000").to_integral_exact(xc), -2000);
    assertEqual(Decimal("0.0625").sqrt(xc), Decimal("0.2"));

    assertEqual(Decimal("0.0625").compare(3, xc), -1);

    xc.clear_status();
    assertRaises(InvalidOperation, [&](){ Decimal("0").compare_signal(Decimal("nan"), xc); });
    assertTrue(xc.status() & DecInvalidOperation);
    assertFalse(c.status() & DecInvalidOperation);

    assertEqual(Decimal("0.01").max(Decimal("0.0101"), xc), Decimal("0.0"));
    assertEqual(Decimal("0.01").max(Decimal("0.0101"), xc), Decimal("0.0"));
    assertEqual(Decimal("0.2").max_mag(Decimal("-0.3"), xc),
                Decimal("-0.3"));
    assertEqual(Decimal("0.02").min(Decimal("-0.03"), xc), Decimal("-0.0"));
    assertEqual(Decimal("0.02").min_mag(Decimal("-0.03"), xc),
                Decimal("0.0"));
    assertEqual(Decimal("0.2").next_toward(Decimal("-1"), xc), Decimal("0.1"));

    xc.clear_status();
    assertRaises(InvalidOperation, [&](){ Decimal("0.2").quantize(Decimal("1e10"), xc); });
    assertTrue(xc.status() & DecInvalidOperation);
    assertFalse(c.status() & DecInvalidOperation);
    assertEqual(Decimal("9.99").rem_near(Decimal("1.5"), xc), Decimal("-0.5"));

    assertEqual(Decimal("9.9").fma(7, Decimal("0.9"), xc), Decimal("7E+1"));

    assertFalse(Decimal("0.01").isnormal(xc));
    assertTrue(Decimal("0.01").issubnormal(xc));

    assertEqual(Decimal(-111).logb(xc), 2);
    assertEqual(Decimal(0).logical_invert(xc), 1);
    assertEqual(Decimal("0.01").number_class(xc), std::string("+Subnormal"));
    assertEqual(Decimal("0.21").to_eng(), "0.21");
    assertEqual(Decimal("9.99e10").to_eng(), "99.9E+9");

    assertEqual(Decimal("11").logical_and(Decimal("10"), xc), 0);
    assertEqual(Decimal("11").logical_or(Decimal("10"), xc), 1);
    assertEqual(Decimal("01").logical_xor(Decimal("10"), xc), 1);
    assertEqual(Decimal("23").rotate(1, xc), 3);
    assertEqual(Decimal("23").rotate(1, xc), 3);

    xc.clear_status();
    assertRaises(Overflow, [&](){ Decimal("23").scaleb(1, xc); });
    assertTrue(xc.status() & DecOverflow);
    assertFalse(c.status() & DecOverflow);
    assertEqual(Decimal("23").shift(-1, xc), 0);

    assertEqual(Decimal(1).canonical(), 1);
}

/******************************************************************************/
/*                           Context representation                           */
/******************************************************************************/

static void
ContextReprTest()
{
    assertEqual(context, context_template);

    context.prec(425000000);
    context.emax(425000000);
    context.emin(-425000000);
    context.round(ROUND_HALF_UP);
    context.clamp(1);
    context.allcr(1);
    context.traps(DecMaxStatus);
    context.status(DecMaxStatus);

    const char *t =
"Context(prec=425000000, emax=425000000, emin=-425000000, round=ROUND_HALF_UP, clamp=1, "
"traps=[IEEEInvalidOperation, DivisionByZero, Overflow, Underflow, "
       "Subnormal, Inexact, Rounded, Clamped], "
"status=[IEEEInvalidOperation, DivisionByZero, Overflow, Underflow, "
        "Subnormal, Inexact, Rounded, Clamped])";

    auto s = context.repr();
    assertEqualStr(s, t);

    s = test::str(context);
    assertEqualStr(s, t);
}

/******************************************************************************/
/*                          Exact conversions (default)                       */
/******************************************************************************/

static const char *large_prec[] = {
/* int */
"12345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890",

/* negative int */
"-12345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890",

/* float */
"1.2345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890E+999999",

/* negative float */
"-1.2345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890E+999999",

/* tiny float */
"1.2345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890E-999999",

/* negative tiny float */
"1.2345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890E-999999",

/* nan */
"NaN12345678901234567890123456789012345678901234567890123456789012345678901234567890"
"234567890123456789012345678901234567890",

/* negative nan */
"-NaN12345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890",

/* snan */
"sNaN12345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890",

/* negative snan */
"-sNaN12345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890",
};

template<class T>
static void
signed_construction()
{
    const T min = std::numeric_limits<T>::min();
    const T max = std::numeric_limits<T>::max();

    const std::vector<T> values = {min, -1, 0, 1, max};
    for (const T& v : values) {
        const Decimal d = {v};
        const std::string ds = d.to_sci();
        const std::string vs = std::to_string(v);
        assertEqual(d, v);
        assertEqual(v, d);
        assertEqual(ds, vs);
        assertEqual(vs, ds);
    }

    const std::vector<T> signs = {-1, 1};
    for (int n = 0; n < std::numeric_limits<T>::digits; n++) {
        for (const T& sign : signs) {
            for (T x = -5; x < 5;  x++) {
                const T i = static_cast<T>(sign * ((static_cast<T>(1) << n) + x));
                const Decimal d = {i};
                assertEqual(d, i);
                assertEqual(i, d);
            }
        }
    }
}

template<class T>
static void
unsigned_construction()
{
    const T max = std::numeric_limits<T>::max();

    const std::vector<T> values = {0, 1, max};
    for (const T& v : values) {
        const Decimal d = {v};
        const std::string ds = d.to_sci();
        const std::string vs = std::to_string(v);
        assertEqual(d, v);
        assertEqual(v, d);
        assertEqual(ds, vs);
        assertEqual(vs, ds);
    }

    for (int n = 0; n < std::numeric_limits<T>::digits; n++) {
        for (T x = 0; x < 5;  x++) {
            const T i = static_cast<T>((static_cast<T>(1) << n) + x);
            const Decimal d = {i};
            assertEqual(d, i);
            assertEqual(i, d);
        }
    }
}

static void
ExactConstructionTest()
{
    assertEqual(context, context_template);

    context.prec(1);
    context.emax(1);
    context.emin(-1);
    context.traps(DecMaxStatus);

    /*****************************************************************/
    /*                       Implicit conversions                    */
    /*****************************************************************/

    /* from empty */
    Decimal empty;
    assertTrue(empty.issnan());

    /* from const Decimal& */
    for (auto& s : {"-NaN", "-4096", "4096", "4.5E+3", "Infinity"}) {
        const Decimal init{Decimal(s)};
        Decimal x = {init};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    for (auto& s : large_prec) {
        const Decimal init{Decimal(s)};
        Decimal x = {init};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    /* from Decimal&& */
    for (auto& s : {"-NaN", "-4096", "4096", "4.5E+3", "Infinity"}) {
        Decimal init{Decimal(s)};
        Decimal x = {std::move(init)};
        assertTrue(init.issnan());
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    for (auto& s : large_prec) {
        Decimal init{Decimal(s)};
        Decimal x = {std::move(init)};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    /* from integers */
    signed_construction<signed char>();
    signed_construction<short>();
    signed_construction<int>();
    signed_construction<long>();
    signed_construction<long long>();

    signed_construction<int8_t>();
    signed_construction<int16_t>();
    signed_construction<int32_t>();
    signed_construction<int64_t>();

    unsigned_construction<unsigned char>();
    unsigned_construction<unsigned short>();
    unsigned_construction<unsigned int>();
    unsigned_construction<unsigned long>();
    unsigned_construction<unsigned long long>();

    unsigned_construction<uint8_t>();
    unsigned_construction<uint16_t>();
    unsigned_construction<uint32_t>();
    unsigned_construction<uint64_t>();

    /*****************************************************************/
    /*                       Explicit conversions                    */
    /*****************************************************************/

    /* from string */
    for (auto& s : {"-NaN", "-4096", "4096", "4.5E+3", "Infinity"}) {
        Decimal x{s};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    for (auto& s : large_prec) {
        Decimal x{s};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    /* from std::string */
    for (auto& s : {"-sNaN", "123", "1E+999999", "1E-999999"}) {
        Decimal x{std::string(s)};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    for (auto& s : large_prec) {
        Decimal x{std::string(s)};
        assertEqualStr(x, s);
        assertEqualStr(s, x);
    }

    assertEqual(context.status(), 0U);

    /* from string, out of bounds for exact conversion */
    context.traps(DecInvalidOperation);

    std::string s = std::string("0E") + std::to_string(INT64_MAX);
    assertRaises(InvalidOperation, [&](){ Decimal x{s}; });

    s = std::string("0E") + std::to_string(INT64_MIN);
    assertRaises(InvalidOperation, [&](){ Decimal x{s}; });

    s = std::string("1E") + std::to_string(INT64_MAX);
    assertRaises(InvalidOperation, [&](){ Decimal x{s}; });

    s = std::string("1E") + std::to_string(INT64_MIN);
    assertRaises(InvalidOperation, [&](){ Decimal x{s}; });

    /* pass explicit context for error reporting */
    Context c = Context();
    c.clear_traps();
    s = std::string("0E") + std::to_string(INT64_MAX);
    Decimal res = Decimal::exact(s, c);
    assertEqual(c.status(), DecInvalidOperation);

    /* large values */
    const char *decstring = "9.999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999e425000000";
    const char *large_exp = "9.999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999e99999999999999999999";
    Decimal large{decstring};

    c.traps(DecMaxStatus-1);
    c.prec(1);

    Decimal xlarge = Decimal(large);
    assertEqual(xlarge, large);

    xlarge = Decimal(std::move(large));
    assertEqual(xlarge, Decimal(decstring));
    assertTrue(large.issnan());

    assertRaises(InvalidOperation, [&](){ Decimal x = Decimal(large_exp); });

    s = std::string(large_exp);
    assertRaises(InvalidOperation, [&](){ Decimal x = Decimal(s); });

    context.clear_status();
    context.clear_traps();
}


/******************************************************************************/
/*                     Conversions that respect the context                   */
/******************************************************************************/

template<class T>
static void
signed_construction_ctx(Context& ctx)
{
    const T min = std::numeric_limits<T>::min();
    const T max = std::numeric_limits<T>::max();

    for (const T& v : {min, max}) {
        ctx.clear_traps();
        ctx.clear_status();
        const Decimal expected = Decimal(std::to_string(v), ctx);
        const uint32_t expected_status = ctx.status();

        ctx.clear_status();
        const Decimal calc = Decimal(v, ctx);
        const uint32_t calc_status = ctx.status();

        assertEqual(calc, expected);
        assertEqual(calc_status, expected_status);

        ctx.traps(DecInexact);
        ctx.clear_status();
        assertRaises(Inexact, [&](){ Decimal(v, ctx); });
        assertEqual(ctx.status(), DecInexact|DecRounded);
        ctx.clear_traps();
    }
}

template<class T>
static void
unsigned_construction_ctx(Context& ctx)
{
    const T v = std::numeric_limits<T>::max();
    ctx.clear_traps();

    ctx.clear_status();
    const Decimal expected = Decimal(std::to_string(v), ctx);
    const uint32_t expected_status = ctx.status();

    ctx.clear_status();
    const Decimal calc = Decimal(v, ctx);
    const uint32_t calc_status = ctx.status();

    assertEqual(calc, expected);
    assertEqual(calc_status, expected_status);

    ctx.traps(DecInexact);
    ctx.clear_status();
    assertRaises(Inexact, [&](){ Decimal(v, ctx); });
    assertEqual(ctx.status(), DecInexact|DecRounded);
    ctx.clear_traps();
}

static void
InexactConstructionTest()
{
    assertEqual(context, context_template);
    context.traps(DecMaxStatus);

    Context ctx{context_template};
    ctx.prec(1);
    ctx.emax(1);
    ctx.emin(-1);

    /*****************************************************************/
    /*                       Explicit conversions                    */
    /*****************************************************************/

    /* from const Decimal& */
    ctx.clear_traps();
    ctx.clear_status();

    Decimal nan = Decimal("-NaN123");
    Decimal integer = Decimal("-4096");
    Decimal floating = Decimal("4.5E+1");


    Decimal x = Decimal(nan, ctx);
    assertEqualStr(x, "NaN");
    assertEqual(ctx.status(), DecConversionSyntax);

    ctx.clear_status();
    x = Decimal(integer, ctx);
    assertEqualStr(x, "-Infinity");
    assertEqual(ctx.status(), (DecInexact | DecOverflow | DecRounded));

    ctx.clear_status();
    x = Decimal(floating, ctx);
    assertEqualStr(x, "4E+1");
    assertEqual(ctx.status(), (DecInexact | DecRounded));

    ctx.traps(DecMaxStatus);
    ctx.clear_status();
    assertRaises(ConversionSyntax, [&](){ Decimal(nan, ctx); });
    assertEqual(ctx.status(), DecConversionSyntax);

    ctx.clear_status();
    assertRaises(Overflow, [&](){ Decimal(integer, ctx); });
    assertEqual(ctx.status(), (DecInexact | DecOverflow | DecRounded));

    ctx.clear_status();
    assertRaises(Inexact, [&](){ Decimal(floating, ctx); });
    assertEqual(ctx.status(), (DecInexact | DecRounded));
    ctx.clear_traps();

    /* from integers */
    ctx.prec(1);
    ctx.emax(19);
    ctx.emin(-19);

    signed_construction_ctx<signed char>(ctx);
    signed_construction_ctx<short>(ctx);
    signed_construction_ctx<int>(ctx);
    signed_construction_ctx<long>(ctx);
    signed_construction_ctx<long long>(ctx);

    signed_construction_ctx<int8_t>(ctx);
    signed_construction_ctx<int16_t>(ctx);
    signed_construction_ctx<int32_t>(ctx);
    signed_construction_ctx<int64_t>(ctx);

    unsigned_construction_ctx<unsigned char>(ctx);
    unsigned_construction_ctx<unsigned short>(ctx);
    unsigned_construction_ctx<unsigned int>(ctx);
    unsigned_construction_ctx<unsigned long>(ctx);
    unsigned_construction_ctx<unsigned long long>(ctx);

    unsigned_construction_ctx<uint8_t>(ctx);
    unsigned_construction_ctx<uint16_t>(ctx);
    unsigned_construction_ctx<uint32_t>(ctx);
    unsigned_construction_ctx<uint64_t>(ctx);

    /* from string */
    ctx.prec(3);
    ctx.clear_status();
    ctx.clear_traps();

    Decimal d = Decimal("456789");
    assertEqualStr(d, "456789");
    d = Decimal("456789", ctx);
    assertEqualStr(d, "4.57E+5");

    ctx.traps(DecInexact);
    assertRaises(Inexact, [&](){ Decimal("456789", ctx); });
    ctx.clear_status();
    ctx.clear_traps();

    ctx.traps(DecRounded);
    assertRaises(Rounded, [&](){ Decimal("456789", ctx); });
    ctx.clear_status();
    ctx.clear_traps();

    ctx.traps(DecConversionSyntax);
    assertRaises(ConversionSyntax, [&](){ Decimal("NaN12345", ctx); });
    ctx.clear_status();
    ctx.clear_traps();

    /* from std::string */
    d = Decimal(std::string("456789"));
    assertEqualStr(d, "456789");
    d = Decimal(std::string("456789"), ctx);
    assertEqualStr(d, "4.57E+5");

    ctx.traps(DecInexact);
    assertRaises(Inexact, [&](){ Decimal(std::string("456789"), ctx); });
    ctx.clear_status();
    ctx.clear_traps();

    ctx.traps(DecRounded);
    assertRaises(Rounded, [&](){ Decimal(std::string("456789"), ctx); });
    ctx.clear_status();
    ctx.clear_traps();

    ctx.traps(DecConversionSyntax);
    assertRaises(ConversionSyntax, [&](){ Decimal(std::string("NaN12345"), ctx); });

#ifndef __mips__ /* miscompilation */
    /* large values */
    const char *decstring = "9.999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999e425000000";
    const char *large_exp = "9.999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999e99999999999999999999";
    Decimal large{decstring};

    ctx.traps(DecMaxStatus-1);
    ctx.prec(100);
    ctx.emax(425000000);
    ctx.emin(-425000000);

    Decimal xlarge = Decimal(large, ctx);
    assertEqual(xlarge, large);

    ctx.prec(1);
    assertRaises(Overflow, [&](){ Decimal x = Decimal(large_exp, ctx); });

    std::string s = std::string(large_exp);
    assertRaises(Overflow, [&](){ Decimal x = Decimal(s, ctx); });
#endif

    ctx.clear_status();
    ctx.clear_traps();
}

/******************************************************************************/
/*                         Exceptions during construction                     */
/******************************************************************************/

static void
ConstructionExceptionTest()
{
    assertEqual(context, context_template);

    /*** from string ***/

    /* invalid syntax */
    context.add_traps(DecConversionSyntax);
    assertRaises(ConversionSyntax, [](){ Decimal(""); });
    assertRaises(ConversionSyntax, [](){ Decimal("xyz"); });
    assertRaises(ConversionSyntax, [](){ Decimal("1 23"); });
    assertRaises(ConversionSyntax, [](){ Decimal("123\n"); });
    context.clear_traps(DecConversionSyntax);

    context.add_traps(DecIEEEInvalidOperation);
    assertRaises(IEEEInvalidOperation, [](){ Decimal("xyz"); });
    assertRaises(IEEEInvalidOperation, [](){ Decimal("1 23"); });
    assertRaises(IEEEInvalidOperation, [](){ Decimal("123\n"); });
    context.clear_traps(DecIEEEInvalidOperation);

    /* too large for exact conversion */
    context.add_traps(DecInvalidOperation);
    assertRaises(InvalidOperation, [](){ Decimal("1e9999999999999999999"); });
    assertRaises(InvalidOperation, [](){ Decimal("-1e9999999999999999999"); });
    assertRaises(InvalidOperation, [](){ Decimal("1e-9999999999999999999"); });
    assertRaises(InvalidOperation, [](){ Decimal("-1e-9999999999999999999"); });
    context.clear_traps(DecInvalidOperation);

    /*** from std::string ***/

    /* invalid syntax */
    context.add_traps(DecConversionSyntax);
    assertRaises(ConversionSyntax, [](){ Decimal(std::string("xyz")); });
    assertRaises(ConversionSyntax, [](){ Decimal(std::string("1 23")); });
    context.clear_traps(DecConversionSyntax);

    context.add_traps(DecIEEEInvalidOperation);
    assertRaises(IEEEInvalidOperation, [](){ Decimal(std::string("xyz")); });
    assertRaises(IEEEInvalidOperation, [](){ Decimal(std::string("1 23")); });
    context.clear_traps(DecIEEEInvalidOperation);

    /* too large for exact conversion */
    context.add_traps(DecInvalidOperation);
    assertRaises(InvalidOperation, [](){ Decimal(std::string("1e9999999999999999999")); });
    assertRaises(InvalidOperation, [](){ Decimal(std::string("-1e9999999999999999999")); });
    assertRaises(InvalidOperation, [](){ Decimal(std::string("1e-9999999999999999999")); });
    assertRaises(InvalidOperation, [](){ Decimal(std::string("-1e-9999999999999999999")); });
    context.clear_traps(DecInvalidOperation);
}

/******************************************************************************/
/*                                  Accessors                                 */
/******************************************************************************/

static void
AccessorTest()
{
    assertEqual(context, context_template);

    Decimal d = Decimal("1.234E+200");
    assertEqual(d.sign(), 1);
    assertEqual(d.exponent(), 197);
    assertEqual(d.coeff(), 1234);
    assertRaises(ValueError, [&](){ d.payload(); });

    d = Decimal("-1.234E-20");
    assertEqual(d.sign(), -1);
    assertEqual(d.exponent(), -23);
    assertEqual(d.coeff(), 1234);
    assertRaises(ValueError, [&](){ d.payload(); });

    d = Decimal("inf");
    assertEqual(d.sign(), 1);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });
    assertRaises(ValueError, [&](){ d.payload(); });

    d = Decimal("-inf");
    assertEqual(d.sign(), -1);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });
    assertRaises(ValueError, [&](){ d.payload(); });

    d = Decimal("nan");
    assertEqual(d.sign(), 1);
    assertEqual(d.payload(), 0);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });

    d = Decimal("-nan");
    assertEqual(d.sign(), -1);
    assertEqual(d.payload(), 0);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });

    d = Decimal("snan");
    assertEqual(d.payload(), 0);
    assertEqual(d.sign(), 1);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });

    d = Decimal("-snan");
    assertEqual(d.payload(), 0);
    assertEqual(d.sign(), -1);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });

    d = Decimal("nan123");
    assertEqual(d.sign(), 1);
    assertEqual(d.payload(), 123);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });

    std::string payload = "123456789123456789123456789123456789123456789123456789123456789123456789"
                          "123456789123456789123456789123456789123456789123456789123456789123456789";
    d = Decimal("-nan" + payload);
    assertEqual(d.sign(), -1);
    assertEqualStr(d.payload(), payload);
    assertRaises(ValueError, [&](){ d.exponent(); });
    assertRaises(ValueError, [&](){ d.coeff(); });
}


/******************************************************************************/
/*                             Assignment operators                           */
/******************************************************************************/

template <class T>
static void
signed_assignment()
{
    const T min = std::numeric_limits<T>::min();
    const T max = std::numeric_limits<T>::max();
    const std::vector<T> values = {min, -2, 2, max};

    for (const T& v : values) {
        Decimal x = v;
        assertEqual(x, Decimal(v));

        x = Decimal(-10000); x += v;
        assertEqual(x, Decimal(-10000) + v);

        x = Decimal(2122); x -= v;
        assertEqual(x, Decimal(2122) - v);

        x = Decimal("1.231e10"); x *= v;
        assertEqual(x, Decimal("1.231e10") * v);

        x = Decimal("225e-10"); x /= v;
        assertEqual(x, Decimal("225e-10") / v);

        x = Decimal("25"); x %= v;
        assertEqual(x, Decimal("25") % v);
    }
}

template <class T>
static void
unsigned_assignment()
{
    const T max = std::numeric_limits<T>::max();
    const std::vector<T> values = {2, max};

    for (const T& v : values) {
        Decimal x = v;
        assertEqual(x, Decimal(v));

        x = Decimal(-10000); x += v;
        assertEqual(x, Decimal(-10000) + v);

        x = Decimal(2122); x -= v;
        assertEqual(x, Decimal(2122) - v);

        x = Decimal("1.231e10"); x *= v;
        assertEqual(x, Decimal("1.231e10") * v);

        x = Decimal("225e-10"); x /= v;
        assertEqual(x, Decimal("225e-10") / v);

        x = Decimal("25"); x %= v;
        assertEqual(x, Decimal("25") % v);
    }
}

static void
AssignmentOperatorTest()
{
    assertEqual(context, context_template);

    /* Decimal */
    context.prec(10000);

    Decimal x = Decimal(10).pow(1200);
    assertEqual(x, Decimal(10).pow(1200));

    x = Decimal(10).pow(1200); x += Decimal("1.1127312");
    assertEqual(x, Decimal(10).pow(1200) + Decimal("1.1127312"));

    x = Decimal(10).pow(1200); x -= Decimal("1.1127312");
    assertEqual(x, Decimal(10).pow(1200) - Decimal("1.1127312"));

    x = -Decimal(10).pow(1200); x *= Decimal("1.1127312");
    assertEqual(x, -Decimal(10).pow(1200) * Decimal("1.1127312"));

    x = -Decimal(10).pow(1200); x /= Decimal("1.1127312");
    assertEqual(x, -Decimal(10).pow(1200) / Decimal("1.1127312"));

    x = Decimal(10).pow(1200); x %= Decimal("1.1127312");
    assertEqual(x, Decimal(10).pow(1200) % Decimal("1.1127312"));

    /* integers */
    context.prec(3);
    context.clear_status();

    signed_assignment<signed char>();
    signed_assignment<short>();
    signed_assignment<int>();
    signed_assignment<long>();
    signed_assignment<long long>();

    signed_assignment<int8_t>();
    signed_assignment<int16_t>();
    signed_assignment<int32_t>();
    signed_assignment<int64_t>();

    unsigned_assignment<unsigned char>();
    unsigned_assignment<unsigned short>();
    unsigned_assignment<unsigned int>();
    unsigned_assignment<unsigned long>();
    unsigned_assignment<unsigned long long>();

    unsigned_assignment<uint8_t>();
    unsigned_assignment<uint16_t>();
    unsigned_assignment<uint32_t>();
    unsigned_assignment<uint64_t>();
}

static void
PointerAssignmentOperatorTest()
{
    assertEqual(context, context_template);

    const Decimal *d = new Decimal;
    assertTrue(d->issnan());

    const Decimal *x = d;
    assertEqual(x, d);

/* CheriBSD: the operator<< overload for uintptr_t is missing (purecap mode) */
#if !defined(__CHERI__)
    x += 10;
    assertEqual(reinterpret_cast<uintptr_t>(x), reinterpret_cast<uintptr_t>(d) + 10 * (sizeof *d));

    x -= 10;
    assertEqual(reinterpret_cast<uintptr_t>(x), reinterpret_cast<uintptr_t>(d));
#endif

    delete x;
}


/******************************************************************************/
/*                             Comparison operators                           */
/******************************************************************************/

template<class T>
static void
signed_comparison()
{
    const T min = std::numeric_limits<T>::min();
    const T max = std::numeric_limits<T>::max();
    const std::vector<T> values = {min, -1, 0, 1, max};

    const Decimal less = Decimal("-1000000000000000000000000000000000");
    const Decimal less_equal = Decimal(min);
    const Decimal greater_equal = Decimal(max);
    const Decimal greater = Decimal("1000000000000000000000000000000000");

    for (const T& v : values) {
        assertTrue(v == Decimal(v));
        assertTrue(Decimal(v) == v);
        assertFalse(v != Decimal(v));
        assertFalse(Decimal(v) != v);

        assertTrue(2 != Decimal(v));
        assertTrue(Decimal(v) != 2);
        assertFalse(2 == Decimal(v));
        assertFalse(Decimal(v) == 2);

        assertTrue(v < greater);
        assertTrue(less < v);

        assertTrue(v <= greater_equal);
        assertTrue(less_equal <= v);

        assertTrue(v >= less_equal);
        assertTrue(greater_equal >= v);

        assertTrue(v > less);
        assertTrue(greater > v);
    }
}

template<class T>
static void
unsigned_comparison()
{
    const T max = std::numeric_limits<T>::max();
    const std::vector<T> values = {0, 1, max};

    Decimal less = Decimal("-1000000000000000000000000000000000");
    Decimal less_equal = Decimal(0);
    Decimal greater_equal = Decimal(max);
    Decimal greater = Decimal("1000000000000000000000000000000000");

    for (const T& v : values) {
        assertTrue(v == Decimal(v));
        assertTrue(Decimal(v) == v);
        assertFalse(v != Decimal(v));
        assertFalse(Decimal(v) != v);

        assertTrue(2 != Decimal(v));
        assertTrue(Decimal(v) != 2);
        assertFalse(2 == Decimal(v));
        assertFalse(Decimal(v) == 2);

        assertTrue(v < greater);
        assertTrue(less < v);

        assertTrue(v <= greater_equal);
        assertTrue(less_equal <= v);

        assertTrue(v >= less_equal);
        assertTrue(greater_equal >= v);

        assertTrue(v > less);
        assertTrue(greater > v);
    }
}

static void
ComparisonOperatorTest()
{
    assertEqual(context, context_template);

    context.emax(1);
    context.emin(-1);
    context.clear_status();
    context.traps(DecMaxStatus);

    /* integer comparisons */
    signed_comparison<signed char>();
    signed_comparison<short>();
    signed_comparison<int>();
    signed_comparison<long>();
    signed_comparison<long long>();

    signed_comparison<int8_t>();
    signed_comparison<int16_t>();
    signed_comparison<int32_t>();
    signed_comparison<int64_t>();

    unsigned_comparison<unsigned char>();
    unsigned_comparison<unsigned short>();
    unsigned_comparison<unsigned int>();
    unsigned_comparison<unsigned long>();
    unsigned_comparison<unsigned long long>();

    unsigned_comparison<uint8_t>();
    unsigned_comparison<uint16_t>();
    unsigned_comparison<uint32_t>();
    unsigned_comparison<uint64_t>();


    /* Decimal */
    Context ctx = MaxContext();
    ctx.traps(DecMaxStatus);
    assertTrue(Decimal(10).pow(1200, ctx) == Decimal(10).pow(1200, ctx));
    assertTrue(Decimal(10).pow(1201, ctx) != Decimal(10).pow(1200, ctx));
    assertTrue(Decimal(10).pow(1200, ctx) < Decimal(10).pow(1201, ctx));
    assertTrue(Decimal(10).pow(1200, ctx) <= Decimal(10).pow(1200, ctx));
    assertTrue(Decimal(10).pow(1200, ctx) >= Decimal(10).pow(1200, ctx));
    assertTrue(Decimal(10).pow(1201, ctx) > Decimal(10).pow(1200, ctx));
    assertEqual(ctx.status(), 0U);

    /* Decimal NaN */
    context.clear_status();
    context.traps(DecInvalidOperation);

    assertFalse(Decimal("NaN") == 2);
    assertFalse(2 == Decimal("NaN"));
    assertFalse(Decimal("NaN") == Decimal("NaN"));
    assertTrue(Decimal("NaN") != Decimal("NaN"));
    assertEqual(context.status(), 0U);

    assertRaises(InvalidOperation, [](){ void(Decimal("NaN") < 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("NaN") <= 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("NaN") >= 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("NaN") > 2); });
    assertEqual(context.status(), DecInvalidOperation);

    /* Decimal sNaN */
    context.clear_status();
    context.traps(DecInvalidOperation);

    assertRaises(InvalidOperation, [](){ void(Decimal("sNaN") == 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("sNaN") != 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("sNaN") < 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("sNaN") <= 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("sNaN") >= 2); });
    assertRaises(InvalidOperation, [](){ void(Decimal("sNaN") > 2); });
    assertEqual(context.status(), DecInvalidOperation);
}

static void
PointerComparisonOperatorTest()
{
    assertEqual(context, context_template);

    const Decimal *d = new Decimal;
    assertTrue(d->issnan());

    const Decimal *x = d + 10;
    assertFalse(x == d);
    assertTrue(x != d);
    assertTrue(d < x);
    assertTrue(x <= x);
    assertTrue(x >= d);
    assertTrue(x > d);

    delete d;
}

/******************************************************************************/
/*                         Unary arithmetic operators                         */
/******************************************************************************/

static void
UnaryOperatorTest()
{
    assertEqual(context, context_template);

    context.prec(3);
    assertEqualStr(+Decimal(10000), "1.00E+4");
    assertEqualStr(-Decimal(10000), "-1.00E+4");
}

static void
PointerUnaryOperatorTest()
{
    assertEqual(context, context_template);

    context.prec(3);
    Decimal *d = new Decimal(10000);

    Decimal *x = +d;
    assertEqual(x, d);

    ++x;
    assertEqual(x-1, d);

    --x;
    assertEqual(x, d);

    x++;
    assertEqual(x-1, d);

    x--;
    assertEqual(x, d);

    bool b = !x;
    assertEqual(b, false);

    assertEqual(*x, 10000);
    assertEqual(**(&x), 10000);

    delete d;
}

/******************************************************************************/
/*                         Binary arithmetic operators                        */
/******************************************************************************/

template <class T>
static void
signed_arithmetic()
{
    const T min = std::numeric_limits<T>::min();
    const T max = std::numeric_limits<T>::max();
    const std::vector<T> values = {min, -2, 2, max};

    for (const T& v : values) {
        assertEqual(Decimal(10) + v, Decimal(10) + Decimal(v));
        assertEqual(v + Decimal(10), Decimal(v) + Decimal(10));

        assertEqual(Decimal(27) - v, Decimal(27) - Decimal(v));
        assertEqual(v - Decimal(27), Decimal(v) - Decimal(27));

        assertEqual(Decimal(1729) * v, Decimal(1729) * Decimal(v));
        assertEqual(v * Decimal(1729), Decimal(1729) * Decimal(v));

        assertEqual(Decimal(225) / v, Decimal(225) / Decimal(v));
        assertEqual(v / Decimal(225), Decimal(v) / Decimal(225));

        assertEqual(Decimal(15222) % v, Decimal(15222) % Decimal(v));
        assertEqual(v % Decimal(15222), Decimal(v) % Decimal(15222));
    }
}

template <class T>
static void
unsigned_arithmetic()
{
    const T max = std::numeric_limits<T>::max();
    const std::vector<T> values = {2, max};

    for (const T& v : values) {
        assertEqual(Decimal(10) + v, Decimal(10) + Decimal(v));
        assertEqual(v + Decimal(10), Decimal(v) + Decimal(10));

        assertEqual(Decimal(27) - v, Decimal(27) - Decimal(v));
        assertEqual(v - Decimal(27), Decimal(v) - Decimal(27));

        assertEqual(Decimal(1729) * v, Decimal(1729) * Decimal(v));
        assertEqual(v * Decimal(1729), Decimal(1729) * Decimal(v));

        assertEqual(Decimal(225) / v, Decimal(225) / Decimal(v));
        assertEqual(v / Decimal(225), Decimal(v) / Decimal(225));

        assertEqual(Decimal(15222) % v, Decimal(15222) % Decimal(v));
        assertEqual(v % Decimal(15222), Decimal(v) % Decimal(15222));
    }
}

static void
ArithmeticOperatorTest()
{
    assertEqual(context, context_template);

    /* Decimal */
    context.prec(9);
    assertEqual(Decimal(20) + Decimal(2), 22);
    assertEqual(Decimal(5) + 123456789000, Decimal(123456789000));
    assertEqual(Decimal(22) - Decimal(2), 20);
    assertEqual(Decimal(20) * Decimal(20), 400);
    assertEqual(Decimal(10) / Decimal(2), 5);
    assertEqual(Decimal(10) % Decimal(3), 1);

    /* integers */
    context.prec(1000);

    signed_arithmetic<signed char>();
    signed_arithmetic<short>();
    signed_arithmetic<int>();
    signed_arithmetic<long>();
    signed_arithmetic<long long>();

    signed_arithmetic<int8_t>();
    signed_arithmetic<int16_t>();
    signed_arithmetic<int32_t>();
    signed_arithmetic<int64_t>();

    unsigned_arithmetic<unsigned char>();
    unsigned_arithmetic<unsigned short>();
    unsigned_arithmetic<unsigned int>();
    unsigned_arithmetic<unsigned long>();
    unsigned_arithmetic<unsigned long long>();

    unsigned_arithmetic<uint8_t>();
    unsigned_arithmetic<uint16_t>();
    unsigned_arithmetic<uint32_t>();
    unsigned_arithmetic<uint64_t>();
}

static void
PointerArithmeticOperatorTest()
{
    assertEqual(context, context_template);

    const Decimal *d = new Decimal;
    assertTrue(d->issnan());

/* CheriBSD: the operator<< overload for uintptr_t is missing (purecap mode) */
#if !defined(__CHERI__)
    const Decimal *x = d + 10;
    assertEqual(reinterpret_cast<uintptr_t>(x), reinterpret_cast<uintptr_t>(d) + 10 * (sizeof *d));

    x = x - 10;
    assertEqual(reinterpret_cast<uintptr_t>(x), reinterpret_cast<uintptr_t>(d));
#endif

    delete d;
}

/******************************************************************************/
/*                                  Predicates                                */
/******************************************************************************/

static void
PredicateTest()
{
    assertEqual(context, context_template);

    const Decimal finite("10.1");
    const Decimal infinite("-inf");
    const Decimal nan("nan");
    const Decimal snan("-snan");
    const Decimal zero("-0");
    const Decimal integer("9.999E+100000");
    const Decimal subnormal = Decimal(0).next_plus();

    assertTrue(finite.iscanonical());
    assertTrue(finite.isfinite());
    assertFalse(finite.isinfinite());
    assertFalse(finite.isspecial());
    assertFalse(finite.isnan());
    assertFalse(finite.isqnan());
    assertFalse(finite.issnan());
    assertFalse(finite.issigned());
    assertFalse(finite.iszero());
    assertFalse(finite.isinteger());
    assertTrue(finite.isnormal());
    assertFalse(finite.issubnormal());

    assertTrue(infinite.iscanonical());
    assertFalse(infinite.isfinite());
    assertTrue(infinite.isinfinite());
    assertTrue(infinite.isspecial());
    assertFalse(infinite.isnan());
    assertFalse(infinite.isqnan());
    assertFalse(infinite.isqnan());
    assertTrue(infinite.issigned());
    assertFalse(infinite.iszero());
    assertFalse(infinite.isinteger());
    assertFalse(infinite.isnormal());
    assertFalse(infinite.issubnormal());

    assertTrue(nan.iscanonical());
    assertFalse(nan.isfinite());
    assertFalse(nan.isinfinite());
    assertTrue(nan.isspecial());
    assertTrue(nan.isnan());
    assertTrue(nan.isqnan());
    assertFalse(nan.issnan());
    assertFalse(nan.issigned());
    assertFalse(nan.iszero());
    assertFalse(nan.isinteger());
    assertFalse(nan.isnormal());
    assertFalse(nan.issubnormal());

    assertTrue(snan.iscanonical());
    assertFalse(snan.isfinite());
    assertFalse(snan.isinfinite());
    assertTrue(snan.isspecial());
    assertTrue(snan.isnan());
    assertFalse(snan.isqnan());
    assertTrue(snan.issnan());
    assertTrue(snan.issigned());
    assertFalse(snan.iszero());
    assertFalse(snan.isinteger());
    assertFalse(snan.isnormal());
    assertFalse(snan.issubnormal());

    assertTrue(zero.iscanonical());
    assertTrue(zero.isfinite());
    assertFalse(zero.isinfinite());
    assertFalse(zero.isspecial());
    assertFalse(zero.isnan());
    assertFalse(zero.isqnan());
    assertFalse(zero.issnan());
    assertTrue(zero.issigned());
    assertTrue(zero.iszero());
    assertTrue(zero.isinteger());
    assertFalse(zero.isnormal());
    assertFalse(zero.issubnormal());

    assertTrue(integer.iscanonical());
    assertTrue(integer.isfinite());
    assertFalse(integer.isinfinite());
    assertFalse(integer.isspecial());
    assertFalse(integer.isnan());
    assertFalse(integer.isqnan());
    assertFalse(integer.issnan());
    assertFalse(integer.issigned());
    assertFalse(integer.iszero());
    assertTrue(integer.isinteger());
    assertTrue(integer.isnormal());
    assertFalse(integer.issubnormal());

    assertTrue(subnormal.iscanonical());
    assertTrue(subnormal.isfinite());
    assertFalse(subnormal.isinfinite());
    assertFalse(subnormal.isspecial());
    assertFalse(subnormal.isnan());
    assertFalse(subnormal.isqnan());
    assertFalse(subnormal.issnan());
    assertFalse(subnormal.issigned());
    assertFalse(subnormal.iszero());
    assertFalse(subnormal.isinteger());
    assertFalse(subnormal.isnormal());
    assertTrue(subnormal.issubnormal());

    Context ctx{1, 1, -1};
    Decimal sub = Decimal("0.00000001");
    assertFalse(sub.isnormal(ctx));
    assertTrue(sub.issubnormal(ctx));
}

/******************************************************************************/
/*                              Unary functions                               */
/******************************************************************************/

static void
UnaryFunctionTest()
{
    assertEqual(context, context_template);

    /* Unary functions, no context arg */
    Decimal x = Decimal("-123.113E+25100");

    assertEqual(x.adjexp(), 25102);
    assertEqual(Decimal("1234e9999").adjexp(), 10002);

    assertRaises(ValueError, [](){ Decimal("nan").adjexp(); });
    assertRaises(ValueError, [](){ Decimal("inf").adjexp(); });

    assertEqual(Decimal::radix(), 10);

    assertEqual(x.canonical(), x);

    x = Decimal(123456789);
    assertEqual(x.copy(), x);

    for (const auto& s : large_prec) {
        x = Decimal(s);
        assertEqualStr(x.copy(), x);
    }

    x = Decimal(-123456789);
    assertEqual(x.copy_abs(), 123456789);

    x = Decimal(123456789);
    assertEqual(x.copy_negate(), -123456789);

    context.prec(10000);
    auto large = -Decimal(1172).pow(1712);
    assertEqual(large.copy_abs(), -large);
    assertEqual(large.copy_negate(), -large);
    assertEqual(large.copy_sign(1), -large);
    context.prec(9);

    /* Unary functions, optional context arg */
    Context ctx{1, 1, -1};

    assertEqualStr(Decimal("-0.00001").number_class(), "-Normal");
    assertEqualStr(Decimal("-0.00001").number_class(ctx), "-Subnormal");

    assertEqual(Decimal(-123456789).abs(), 123456789);
    assertEqual(Decimal(-15).abs(ctx), Decimal("2E+1"));

    assertEqual(Decimal(-1123).exp(), Decimal("1.93774588E-488"));
    assertEqual(Decimal(2).exp(ctx), 7);

    assertEqual(Decimal(1123).invroot(), Decimal("0.0298407766"));
    assertEqual(Decimal(7).invroot(ctx), Decimal("0.4"));

    assertEqual(Decimal(0).logical_invert(), Decimal("111111111"));
    assertEqual(Decimal(0).logical_invert(ctx), Decimal("1"));

    assertEqual(Decimal(10).ln(), Decimal("2.30258509"));
    assertEqual(Decimal(10).ln(ctx), Decimal("2"));

    assertEqual(Decimal(20).log10(), Decimal("1.30103000"));
    assertEqual(Decimal(20).log10(ctx), Decimal("1"));

    assertEqual(Decimal("2250000000000000000000000000").logb(), Decimal("27"));
    assertEqual(Decimal("2250000000000000000000000000").logb(ctx), Decimal("3E+1"));

    assertEqual(Decimal("2250000000000000000000000000").minus(), Decimal("-2.25000000E+27"));
    assertEqual(Decimal("25").minus(ctx), Decimal("-2E+1"));

    assertEqual(Decimal("2250000000000000000000000000").next_minus(), Decimal("2.24999999E+27"));
    assertEqual(Decimal("2250000000000000000000000000").next_minus(ctx), Decimal("9E+1"));

    assertEqual(Decimal("2250000000000000000000000000").plus(), Decimal("2.25000000E+27"));
    assertEqual(Decimal("28").plus(ctx), Decimal("3E+1"));

    assertEqual(Decimal("2250000000000000000000000000").reduce(), Decimal("2.25E+27"));
    assertEqual(Decimal("-28").reduce(ctx), Decimal("-3E+1"));

    assertEqual(Decimal("22500000.12").to_integral(), Decimal("22500000"));
    assertEqual(Decimal("22500000.12").to_integral(ctx), Decimal("22500000"));

    assertEqual(Decimal("22500000.12").to_integral_exact(), Decimal("22500000"));
    assertEqual(Decimal("22500000.12").to_integral_exact(ctx), Decimal("22500000"));

    assertEqual(Decimal("90025").sqrt(), Decimal("300.041664"));
    assertEqual(Decimal("99").sqrt(ctx), Decimal("1E+1"));

    ctx.round(ROUND_UP);
    x = Decimal("99999999999999999999999999.9").to_integral(ctx);
    assertEqual(x, Decimal("100000000000000000000000000"));

    x = Decimal("99999999999999999999999999.9").to_integral_exact(ctx);
    assertEqual(x, Decimal("100000000000000000000000000"));

    ctx.add_traps(DecInexact);
    assertRaises(Inexact, [&](){ Decimal("999.9").to_integral_exact(ctx); });
}

static void
CeilTest()
{
    assertEqual(context, context_template);

    context.traps(DecMaxStatus);

    const std::vector<std::pair<const char *, long long>> pairs = {
        {"123.00", 123},
        {"3.2", 4},
        {"3.54", 4},
        {"3.899", 4},
        {"-2.3", -2},
        {"-11.0", -11},
        {"0.0", 0},
        {"-0E3", 0},
        {"898211712379812736.1", 898211712379812737LL},
    };

    for (auto& p : pairs) {
        const char *s = p.first;
        long long i = p.second;

        assertEqual(Decimal(s).ceil(), i);
    }

    context.status(0);
    assertRaises(InvalidOperation, [](){ Decimal("NaN").ceil(); });
    assertRaises(InvalidOperation, [](){ Decimal("NaN123").ceil(); });
    assertRaises(InvalidOperation, [](){ Decimal("Inf").ceil(); });
    assertRaises(InvalidOperation, [](){ Decimal("-Inf").ceil(); });
    assertRaises(InvalidOperation, [](){ Decimal("sNaN").ceil(); });
    assertEqual(context.status(), DecInvalidOperation);
}

static void
FloorTest()
{
    assertEqual(context, context_template);

    context.traps(DecMaxStatus);

    const std::vector<std::pair<const char *, long long>> pairs = {
        {"123.00", 123},
        {"3.2", 3},
        {"3.54", 3},
        {"3.899", 3},
        {"-2.3", -3},
        {"-11.0", -11},
        {"0.0", 0},
        {"-0E3", 0},
        {"898211712379812736.1", 898211712379812736LL},
    };

    for (auto& p : pairs) {
        const char *s = p.first;
        long long i = p.second;

        assertEqual(Decimal(s).floor(), i);
    }

    context.status(0);
    assertRaises(InvalidOperation, [](){ Decimal("NaN").floor(); });
    assertRaises(InvalidOperation, [](){ Decimal("NaN123").floor(); });
    assertRaises(InvalidOperation, [](){ Decimal("Inf").floor(); });
    assertRaises(InvalidOperation, [](){ Decimal("-Inf").floor(); });
    assertRaises(InvalidOperation, [](){ Decimal("sNaN").floor(); });
    assertEqual(context.status(), DecInvalidOperation);
}

static void
TruncTest()
{
    assertEqual(context, context_template);

    char buf[10];
    context.traps(DecMaxStatus);

    const std::vector<std::pair<const char *, long long>> pairs = {
        {"123.00", 123},
        {"3.2", 3},
        {"3.54", 3},
        {"3.899", 3},
        {"-2.3", -2},
        {"-11.0", -11},
        {"-11.8", -11},
        {"0.0", 0},
        {"-0E3", 0},
        {"898211712379812736.1", 898211712379812736LL},
    };

    for (auto& p : pairs) {
        const char *s = p.first;
        long long i = p.second;

        assertEqual(Decimal(s).trunc(), i);
    }

    context.round(ROUND_DOWN);
    for (int i = -250; i < 250; i++) {
        int n = snprintf(buf, sizeof buf, "%0.2f", i / 100.0);
        assertTrue(n >= 0 && n < 10);
        Decimal d = Decimal(static_cast<const char *>(buf));
        Decimal r = d.to_integral();
        assertEqual(d.trunc(), r);
    }

    context.status(0);
    assertRaises(InvalidOperation, [](){ Decimal("NaN").trunc(); });
    assertRaises(InvalidOperation, [](){ Decimal("NaN123").trunc(); });
    assertRaises(InvalidOperation, [](){ Decimal("Inf").trunc(); });
    assertRaises(InvalidOperation, [](){ Decimal("-Inf").trunc(); });
    assertRaises(InvalidOperation, [](){ Decimal("sNaN").trunc(); });
    assertEqual(context.status(), DecInvalidOperation);
}

/******************************************************************************/
/*                              Binary functions                              */
/******************************************************************************/

static void
BinaryFunctionTest()
{
    assertEqual(context, context_template);

    /* Binary functions, no context arg */
    assertEqual(Decimal("123").compare_total(Decimal("sNaN")), Decimal("-1"));
    assertEqual(Decimal("-123").compare_total_mag(Decimal("10")), Decimal("1"));

    /* Binary functions */
    Context ctx{3, 100, -100};
    ctx.round(ROUND_UP);
    ctx.clamp(1);
    ctx.traps(DecIEEEInvalidOperation);

    assertEqualStr(Decimal(1234567890).add(Decimal("-9988888.23")), "1.22457900E+9");
    assertEqualStr(Decimal(1234567890).add(Decimal("-9988888.23"), ctx), "1.23E+9");

    assertEqualStr(Decimal(1234567890).div(Decimal("-9988888.23")), "-123.594124");
    assertEqualStr(Decimal(1234567890).div(Decimal("-9988888.23"), ctx), "-124");

    assertEqualStr(Decimal(1234567890).divint(Decimal("-9988888.23")), "-123");
    assertEqualStr(Decimal(1234567890).divint(Decimal("-9988888.23"), ctx), "-123");

    assertEqualStr(Decimal(1234567890).compare(Decimal("-9988888.23")), 1);
    assertEqualStr(Decimal(1234567890).compare(Decimal("-9988888.23"), ctx), 1);

    assertEqualStr(Decimal(1234567890).compare_signal(Decimal("-9988888.23")), 1);
    assertEqualStr(Decimal(1234567890).compare_signal(Decimal("-9988888.23"), ctx), 1);

    assertEqualStr(Decimal("101111").logical_and(Decimal("110001101")), "1101");
    assertEqualStr(Decimal("101111").logical_and(Decimal("110001101"), ctx), "101");

    assertEqualStr(Decimal("101111").logical_or(Decimal("110001101")), "110101111");
    assertEqualStr(Decimal("101111").logical_or(Decimal("110001101"), ctx), "111");

    assertEqualStr(Decimal("101111").logical_xor(Decimal("110001101")), "110100010");
    assertEqualStr(Decimal("101111").logical_xor(Decimal("110001101"), ctx), "10");

    assertEqualStr(Decimal(1234567890).max(Decimal("-9988888.23")), "1.23456789E+9");
    assertEqualStr(Decimal(1234567890).max(Decimal("-9988888.23"), ctx), "1.24E+9");

    assertEqualStr(Decimal(1234567890).max_mag(Decimal("-9988888.23")), "1.23456789E+9");
    assertEqualStr(Decimal(1234567890).max_mag(Decimal("-9988888.23"), ctx), "1.24E+9");

    assertEqualStr(Decimal(1234567890).min(Decimal("-9988888.23")), "-9988888.23");
    assertEqualStr(Decimal(1234567890).min(Decimal("-9988888.23"), ctx), "-9.99E+6");

    assertEqualStr(Decimal(1234567890).min_mag(Decimal("-9988888.23")), "-9988888.23");
    assertEqualStr(Decimal(1234567890).min_mag(Decimal("-9988888.23"), ctx), "-9.99E+6");

    assertEqualStr(Decimal(1234567890).mul(Decimal("-9988888.23")), "-1.23319607E+16");
    assertEqualStr(Decimal(1234567890).mul(Decimal("-9988888.23"), ctx), "-1.24E+16");

    assertEqualStr(Decimal(1234567890).next_toward(Decimal("-9988888.23")), "1.23456788E+9");
    assertEqualStr(Decimal(1234567890).next_toward(Decimal("-9988888.23"), ctx), "1.23E+9");

    assertEqualStr(Decimal(1234567890).pow(Decimal("-9988888.23")), "0E-1000007");
    assertEqualStr(Decimal(1234567890).pow(Decimal("-9988888.23"), ctx), "1E-102");
    ctx.clear_status();
    assertEqual(Decimal("1.0").pow(100, ctx), Decimal("1.00"));
    assertTrue(ctx.status() & DecRounded);
    ctx.clear_status();
    ctx.emax(1);
    ctx.emin(-1);
    assertEqual(Decimal(10000).pow(Decimal("0.5"), ctx), Decimal("inf"));
    assertTrue(ctx.status() & DecOverflow);
    ctx.emax(100);
    ctx.emin(-100);

    assertEqualStr(Decimal(1234567890).rem(Decimal("-9988888.23")), "5934637.71");
    assertEqualStr(Decimal(1234567890).rem(Decimal("-9988888.23"), ctx), "5.94E+6");

    assertEqualStr(Decimal(1234567890).rem_near(Decimal("-9988888.23")), "-4054250.52");
    assertEqualStr(Decimal(1234567890).rem_near(Decimal("-9988888.23"), ctx), "-4.06E+6");

    assertEqualStr(Decimal(1234567890).rotate(2), "456789023");
    assertEqualStr(Decimal(1234567890).rotate(2, ctx), "89");

    assertEqualStr(Decimal(20).quantize(Decimal("1E-2")), "20.00");
    assertRaises(InvalidOperation, [&](){ Decimal(20).quantize(Decimal("1E-2"), ctx); });
    assertEqualStr(Decimal(20).quantize(Decimal("1E-1"), ctx), "20.0");

    assertEqualStr(Decimal(20).scaleb(Decimal("100")), "2.0E+101");
    ctx.add_traps(DecOverflow);
    assertRaises(Overflow, [&](){ Decimal(20).scaleb(Decimal("100"), ctx); });
    assertEqualStr(Decimal(20).scaleb(Decimal("10"), ctx), "2.0E+11");

    assertEqualStr(Decimal(1).shift(8), Decimal("100000000"));
    assertRaises(InvalidOperation, [&](){ Decimal(1).shift(8, ctx); });
    assertEqualStr(Decimal(1).shift(2, ctx), 100);

    assertEqualStr(Decimal(1234567890).sub(Decimal("-9988888.23")), "1.24455678E+9");
    assertEqualStr(Decimal(1234567890).sub(Decimal("-9988888.23"), ctx), "1.25E+9");
}

/******************************************************************************/
/*                                   Divmod                                   */
/******************************************************************************/

static void
DivmodTest()
{
    assertEqual(context, context_template);

    /* Binary functions */
    Context ctx{3, 100, -100};
    ctx.round(ROUND_UP);
    ctx.clamp(1);
    ctx.traps(DecIEEEInvalidOperation);

    auto result = Decimal("1234567890").divmod(12716);
    assertEqual(result.first, 97087);
    assertEqual(result.second, 9598);

    assertRaises(DivisionImpossible, [&](){ Decimal("1234567890").divmod(12716, ctx); });

    result = Decimal("1234567890").divmod(12716172);
    assertEqualStr(result.first, "97");
    assertEqualStr(result.second, "1099206");

    result = Decimal("10912837129").divmod(1001);
    assertEqual(result.first, Decimal("10901935"));
    assertEqual(result.second, Decimal("194"));

    result = Decimal("NaN").divmod(7);
    assertTrue(result.first.isqnan());
    assertTrue(result.second.isqnan());

    context.clear_traps();
    context.clear_status();
    result = Decimal("inf").divmod(Decimal("inf"));
    assertTrue(result.first.isqnan());
    assertTrue(result.second.isqnan());
    assertTrue(context.status() & DecInvalidOperation);

    context.clear_status();
    result = Decimal("inf").divmod(Decimal("101"));
    assertTrue(result.first.isinfinite());
    assertTrue(result.second.isqnan());
    assertTrue(context.status() & DecInvalidOperation);

    context.clear_status();
    result = Decimal("0").divmod(Decimal("0"));
    assertTrue(result.first.isqnan());
    assertTrue(result.second.isqnan());
    assertTrue(context.status() & DecDivisionUndefined);

    context.clear_status();
    result = Decimal("11").divmod(Decimal("0"));
    assertTrue(result.first.isinfinite());
    assertTrue(result.second.isqnan());
    assertTrue(context.status() & DecInvalidOperation);
    assertTrue(context.status() & DecDivisionByZero);
}

/******************************************************************************/
/*                                  Quantize                                  */
/******************************************************************************/

static void
QuantizeTest()
{
    assertEqual(context, context_template);

    context.clear_status();

    Context c = Context(9, 99999, -99999, ROUND_DOWN);
    assertEqual(Decimal("7.335").quantize(Decimal(".01")), Decimal("7.34"));
    assertEqual(Decimal("7.335").quantize(Decimal(".01"), c), Decimal("7.33"));

    c = Context(28, 99999, -99999);
    c.traps(DecInvalidOperation);
    assertRaises(InvalidOperation, [&](){ Decimal("10e99999").quantize(Decimal("1e100000"), c); });

    c = Context();
    c.round(ROUND_DOWN);
    Decimal d = Decimal("0.871831e800");
    Decimal x = d.quantize(Decimal("1e797"), c);
    assertEqual(x, Decimal("8.71E+799"));
}

/******************************************************************************/
/*                              Ternary functions                             */
/******************************************************************************/

static void
TernaryFunctionTest()
{
    assertEqual(context, context_template);

    Context ctx{3, 100, -100};
    ctx.round(ROUND_UP);
    ctx.clamp(1);
    ctx.traps(DecIEEEInvalidOperation);

    assertEqual(Decimal("1234").fma(919, Decimal("3.2507355")), Decimal("1134049.25"));
    assertEqual(Decimal("1234").fma(919, Decimal("3.2507355"), ctx), Decimal("1.14E+6"));

    assertEqual(Decimal("1234").powmod(919, Decimal("123456789")), Decimal("119347714"));
    assertRaises(InvalidOperation, [&](){ Decimal("1234").powmod(919, Decimal("123456789"), ctx); });
    assertEqual(Decimal("1234").powmod(919, Decimal("996")), Decimal("892"));

    ctx.prec(2);
    assertRaises(InvalidOperation, [&](){ Decimal("1000").powmod(1, Decimal("501"), ctx); });
}

/******************************************************************************/
/*                             Irregular functions                            */
/******************************************************************************/

static void
IrregularFunctionTest()
{
    assertEqual(context, context_template);

    Context ctx{3, 100, -100};
    ctx.round(ROUND_UP);
    ctx.clamp(1);
    ctx.traps(DecIEEEInvalidOperation);

    assertEqual(Decimal("1").cmp(10), -1);
    assertEqual(Decimal("10").cmp(10), 0);
    assertEqual(Decimal("10").cmp(1), 1);
    assertEqual(Decimal("1").cmp(Decimal("inf")), -1);
    assertEqual(Decimal("1").cmp(Decimal("-inf")), 1);
    assertEqual(Decimal("inf").cmp(Decimal("1")), 1);
    assertEqual(Decimal("-inf").cmp(Decimal("1")), -1);
    assertEqual(Decimal("-inf").cmp(Decimal("inf")), -1);
    assertEqual(Decimal("inf").cmp(Decimal("-inf")), 1);
    assertEqual(Decimal("10").cmp(Decimal("nan")), INT_MAX);
    assertEqual(Decimal("inf").cmp(Decimal("nan")), INT_MAX);
    assertEqual(Decimal("nan").cmp(Decimal("nan")), INT_MAX);
    assertEqual(Decimal("nan").cmp(Decimal("snan")), INT_MAX);
    assertEqual(Decimal("snan").cmp(Decimal("snan")), INT_MAX);

    assertEqual(Decimal("1").cmp_total(10), -1);
    assertEqual(Decimal("10").cmp_total(10), 0);
    assertEqual(Decimal("10").cmp_total(1), 1);
    assertEqual(Decimal("1").cmp_total(Decimal("inf")), -1);
    assertEqual(Decimal("1").cmp_total(Decimal("-inf")), 1);
    assertEqual(Decimal("inf").cmp_total(Decimal("1")), 1);
    assertEqual(Decimal("-inf").cmp_total(Decimal("1")), -1);
    assertEqual(Decimal("-inf").cmp_total(Decimal("inf")), -1);
    assertEqual(Decimal("inf").cmp_total(Decimal("-inf")), 1);
    assertEqual(Decimal("10").cmp_total(Decimal("nan")), -1);
    assertEqual(Decimal("inf").cmp_total(Decimal("nan")), -1);
    assertEqual(Decimal("nan").cmp_total(Decimal("inf")), 1);
    assertEqual(Decimal("nan").cmp_total(Decimal("nan")), 0);
    assertEqual(Decimal("nan").cmp_total(Decimal("snan")), 1);
    assertEqual(Decimal("snan").cmp_total(Decimal("snan")), 0);

    assertEqual(Decimal("1").compare_total_mag(10), -1);
    assertEqual(Decimal("-10").compare_total_mag(1), 1);
    assertEqual(Decimal("10").compare_total_mag(1), 1);
    assertEqual(Decimal("1").compare_total_mag(Decimal("inf")), -1);
    assertEqual(Decimal("1").compare_total_mag(Decimal("-inf")), -1);
    assertEqual(Decimal("inf").compare_total_mag(Decimal("1")), 1);
    assertEqual(Decimal("-inf").compare_total_mag(Decimal("1")), 1);
    assertEqual(Decimal("-inf").compare_total_mag(Decimal("inf")), 0);
    assertEqual(Decimal("inf").compare_total_mag(Decimal("-inf")), 0);
    assertEqual(Decimal("10").compare_total_mag(Decimal("nan")), -1);
    assertEqual(Decimal("inf").compare_total_mag(Decimal("nan")), -1);
    assertEqual(Decimal("nan").compare_total_mag(Decimal("inf")), 1);
    assertEqual(Decimal("nan").compare_total_mag(Decimal("nan")), 0);
    assertEqual(Decimal("nan").compare_total_mag(Decimal("snan")), 1);
    assertEqual(Decimal("snan").compare_total_mag(Decimal("snan")), 0);

    assertEqual(Decimal("10").copy_sign(-1), -10);

    ctx.round(ROUND_DOWN);
    assertEqual(Decimal("123456785").rescale(1, ctx), Decimal("1.2345678E+8"));
    ctx.round(ROUND_UP);
    assertEqual(Decimal("123456785").rescale(1, ctx), Decimal("1.2345679E+8"));

    assertTrue(Decimal("123456785").same_quantum(10));
    assertFalse(Decimal("123456785").same_quantum(Decimal("1E+1")));

    assertEqual(Decimal("1").shiftn(8), Decimal("1E+8"));
    assertRaises(InvalidOperation, [&](){ Decimal("1").shiftn(8, ctx); });
    assertEqual(Decimal("1000").shiftn(-1), Decimal("100"));

    assertEqual(Decimal("1").shiftl(100), Decimal("1E+100"));
    assertEqual(Decimal("1").shiftl(100, ctx), Decimal("1E+100"));
    assertRaises(ValueError, [](){ Decimal("NaN").shiftl(100); });
    assertRaises(ValueError, [](){ Decimal("sNaN").shiftl(100); });
    assertRaises(ValueError, [](){ Decimal("Infinity").shiftl(100); });

    assertEqual(Decimal("1000000000000").shiftr(1), Decimal("100000000000"));
    assertEqual(Decimal("1000000000000").shiftr(1, ctx), Decimal("100000000000"));
    assertRaises(ValueError, [](){ Decimal("NaN").shiftl(100); });
    assertRaises(ValueError, [](){ Decimal("sNaN").shiftl(100); });
    assertRaises(ValueError, [](){ Decimal("Infinity").shiftl(100); });

    assertEqual(Decimal::ln10(9), Decimal("2.30258509"));
}

/******************************************************************************/
/*                                   Apply                                    */
/******************************************************************************/

static void
ApplyTest()
{
    assertEqual(context, context_template);

    context.prec(2);

    Decimal d = Decimal("1.234E+200");
    assertEqual(+d, Decimal("1.2E+200"));
    assertEqual(d.apply(context), Decimal("1.2E+200"));
    assertEqual(Decimal("1.2E+200", context), Decimal("1.2E+200"));

    d = Decimal("-0");
    assertEqualStr(+d, "0");
    assertEqualStr(d.apply(context), "-0");
    assertEqualStr(Decimal("-0", context), "-0");

    d = Decimal("NaN0123456789");
    assertEqualStr(+d, "NaN89");
    assertEqualStr(d.apply(context), "NaN89");
    assertEqualStr(Decimal(d, context), "NaN");

    context.add_traps(DecIEEEInvalidOperation);
    assertRaises(ConversionSyntax, [&](){ Decimal(d, context); });
}

/******************************************************************************/
/*                             Integer conversion                             */
/******************************************************************************/

static void
IntegerConversionTest()
{
    assertEqual(context, context_template);

    assertEqual(Decimal(INT64_MIN).i64(), INT64_MIN);
    assertEqual(Decimal(INT64_MAX).i64(), INT64_MAX);
    assertEqual(Decimal("1E+3").i64(), 1000);
    assertRaises(ValueError, [](){ Decimal("1E+20").i64(); });
    assertRaises(ValueError, [](){ Decimal("-1E+20").i64(); });
    assertRaises(ValueError, [](){ Decimal("1E-20").i64(); });
    assertRaises(ValueError, [](){ Decimal("nan").i64(); });
    assertRaises(ValueError, [](){ Decimal("inf").i64(); });

    assertEqual(Decimal(INT32_MIN).i32(), INT32_MIN);
    assertEqual(Decimal(INT32_MAX).i32(), INT32_MAX);
    assertEqual(Decimal("1E+3").i32(), 1000);
    assertRaises(ValueError, [](){ Decimal("1E+11").i32(); });
    assertRaises(ValueError, [](){ Decimal("-1E+11").i32(); });
    assertRaises(ValueError, [](){ Decimal("1E-11").i32(); });
    assertRaises(ValueError, [](){ Decimal("nan").i32(); });
    assertRaises(ValueError, [](){ Decimal("inf").i32(); });

    assertEqual(Decimal(UINT64_MAX).u64(), UINT64_MAX);
    assertEqual(Decimal("1E+3").u64(), 1000U);
    assertRaises(ValueError, [](){ Decimal("-1").u64(); });
    assertRaises(ValueError, [](){ Decimal("1E+20").u64(); });
    assertRaises(ValueError, [](){ Decimal("-1E+20").u64(); });
    assertRaises(ValueError, [](){ Decimal("1E-20").u64(); });
    assertRaises(ValueError, [](){ Decimal("nan").u64(); });
    assertRaises(ValueError, [](){ Decimal("inf").u64(); });

    assertEqual(Decimal(UINT32_MAX).u32(), UINT32_MAX);
    assertEqual(Decimal("1E+3").u32(), 1000U);
    assertRaises(ValueError, [](){ Decimal("-1").u32(); });
    assertRaises(ValueError, [](){ Decimal("1E+11").u32(); });
    assertRaises(ValueError, [](){ Decimal("-1E+11").u32(); });
    assertRaises(ValueError, [](){ Decimal("1E-11").u32(); });
    assertRaises(ValueError, [](){ Decimal("nan").u32(); });
    assertRaises(ValueError, [](){ Decimal("inf").u32(); });
}

/******************************************************************************/
/*                              Exact arithmetic                              */
/******************************************************************************/

static void
ExactArithTest()
{
    assertEqual(context, context_template);

    context = MaxContext();

    assertEqual(Decimal(0).exp(), 1);
    assertEqual(Decimal(1).ln(), 0);
    assertEqual(Decimal(1).log10(), 0);
    assertEqual(Decimal(100).log10(), 2);
    assertEqual(Decimal("1E+223").log10(), 223);
    assertEqual(Decimal("1E+19").logb(), 19);
    assertEqual(Decimal(4).sqrt(), 2);
    assertEqual(Decimal("40E+9").sqrt(), Decimal("2.0E+5"));
    assertEqual(Decimal(10).divint(3), 3);
    assertEqual(Decimal(4) / 2, 2);
    assertEqual(Decimal(400).pow(-1), Decimal("0.0025"));
}

/******************************************************************************/
/*                        Containers and data structures                      */
/******************************************************************************/

static void
DataStructuresTest(void)
{
    assertEqual(context, context_template);

    /* array */
    Decimal *x = new Decimal[10]();

    for (size_t i = 0; i < 10; i++) {
        assertTrue(x[i].issnan());
        x[i] = i;
    }
    for (size_t i = 0; i < 10; i++) {
        assertEqual(x[i], i);
    }

    delete[] x;

    /* array of pointers */
    Decimal **y = new Decimal *[10];

    for (size_t i = 0; i < 10; i++) {
        y[i] = new Decimal();
        assertTrue((*y[i]).issnan());
        *y[i] = i;
    }
    for (size_t i = 0; i < 10; i++) {
        assertEqual(*y[i], i);
    }
    for (size_t i = 0; i < 10; i++) {
        delete y[i];
    }

    delete[] y;

    /* linked list */
    std::list<Decimal> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_front(Decimal(i));
    }
    lst.sort();
    size_t n = 0;
    for (const Decimal& d : lst) {
        assertEqual(d, n++);
    }

    /* map */
    std::map<const char *, Decimal> map1;
    std::vector<const char *> keys = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (auto& k : keys) {
        map1[k] = Decimal(k);
    }
    for (auto& k : keys) {
        assertEqual(map1.at(k), Decimal(k));
    }

    /* map */
    std::map<Decimal, const char *> map2;
    std::vector<const char *> values = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (auto& v : values) {
        map2[Decimal(v)] = v;
    }

    for (auto& v : values) {
        assertEqual(map2.at(Decimal(v)), v);
    }
}

static void
LargeDataStructuresTest(void)
{
    assertEqual(context, context_template);

    std::vector<Decimal> powers(10);

    context.prec(10000);
    context.traps(DecMaxStatus);

    for (size_t i = 0; i < 10; i++) {
        powers[i] = Decimal(i).pow(2100);
    }

    /* array */
    Decimal *x = new Decimal[10]();

    for (size_t i = 0; i < 10; i++) {
        assertTrue(x[i].issnan());
        x[i] = powers[i];
    }
    for (size_t i = 0; i < 10; i++) {
        assertEqual(x[i], powers[i]);
    }

    delete[] x;

    /* array of pointers */
    Decimal **y = new Decimal *[10];

    for (size_t i = 0; i < 10; i++) {
        y[i] = new Decimal();
        assertTrue((*y[i]).issnan());
        *y[i] = powers[i];
    }
    for (size_t i = 0; i < 10; i++) {
        assertEqual(*y[i], powers[i]);
    }
    for (size_t i = 0; i < 10; i++) {
        delete y[i];
    }

    delete[] y;

    /* linked list */
    std::list<Decimal> lst;

    for (size_t i = 0; i < 10; i++) {
        lst.push_front(powers[i]);
    }
    lst.sort();
    size_t n = 0;
    for (const Decimal& d : lst) {
        assertEqual(d, powers[n++]);
    }

    /* map */
    std::map<const char *, Decimal> map1;
    std::vector<const char *> keys = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (size_t i = 0; i < 10; i++) {
        map1[keys[i]] = powers[i];
    }

    for (size_t i = 0; i < 10; i++) {
        assertEqual(map1.at(keys[i]), powers[i]);
    }

    std::map<Decimal, Decimal> map2;
    std::vector<const char *> values = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (size_t i = 0; i < 10; i++) {
        map2[Decimal(values[i])] = powers[i];
    }

    for (size_t i = 0; i < 10; i++) {
        assertEqual(map2.at(Decimal(values[i])), powers[i]);
    }
}

/******************************************************************************/
/*                               String and repr                              */
/******************************************************************************/

static void
StringReprTest()
{
    assertEqual(context, context_template);

    context.traps(DecMaxStatus);

    std::stringstream ss;

    Decimal d = Decimal("225E+1000");

    ss << d;
    assertEqual(ss.str(), "2.25E+1002");

    assertEqual(d.repr(), "Decimal(\"2.25E+1002\")");
    assertEqual(d.repr(true), "Decimal(\"2.25E+1002\")");
    assertEqual(d.repr(false), "Decimal(\"2.25e+1002\")");

    assertEqual(context.status(), 0U);
}

/******************************************************************************/
/*                                   Format                                   */
/******************************************************************************/

static void
FormatTest()
{
    assertEqual(context, context_template);

    const std::vector<std::vector<const char *>> test_cases = {
        {"e", "0E-15", "0e-15"},
        {"e", "2.3E-15", "2.3e-15"},
        {"e", "2.30E+2", "2.30e+2"},
        {"e", "2.30000E-15", "2.30000e-15"},
        {"e", "1.23456789123456789e40", "1.23456789123456789e+40"},
        {"e", "1.5", "1.5e+0"},
        {"e", "0.15", "1.5e-1"},
        {"e", "0.015", "1.5e-2"},
        {"e", "0.0000000000015", "1.5e-12"},
        {"e", "15.0", "1.50e+1"},
        {"e", "-15", "-1.5e+1"},
        {"e", "0", "0e+0"},
        {"e", "0E1", "0e+1"},
        {"e", "0.0", "0e-1"},
        {"e", "0.00", "0e-2"},
        {".6e", "0E-15", "0.000000e-9"},
        {".6e", "0", "0.000000e+6"},
        {".6e", "9.999999", "9.999999e+0"},
        {".6e", "9.9999999", "1.000000e+1"},
        {".6e", "-1.23e5", "-1.230000e+5"},
        {".6e", "1.23456789e-3", "1.234568e-3"},
        {"f", "0", "0"},
        {"f", "0.0", "0.0"},
        {"f", "0E-2", "0.00"},
        {"f", "0.00E-8", "0.0000000000"},
        {"f", "0E1", "0"},
        {"f", "3.2E1", "32"},
        {"f", "3.2E2", "320"},
        {"f", "3.20E2", "320"},
        {"f", "3.200E2", "320.0"},
        {"f", "3.2E-6", "0.0000032"},
        {".6f", "0E-15", "0.000000"},
        {".6f", "0E1", "0.000000"},
        {".6f", "0", "0.000000"},
        {".0f", "0", "0"},
        {".0f", "0e-2", "0"},
        {".0f", "3.14159265", "3"},
        {".1f", "3.14159265", "3.1"},
        {".4f", "3.14159265", "3.1416"},
        {".6f", "3.14159265", "3.141593"},
        {".7f", "3.14159265", "3.1415926"},
        {".8f", "3.14159265", "3.14159265"},
        {".9f", "3.14159265", "3.141592650"},

        {"g", "0", "0"},
        {"g", "0.0", "0.0"},
        {"g", "0E1", "0e+1"},
        {"G", "0E1", "0E+1"},
        {"g", "0E-5", "0.00000"},
        {"g", "0E-6", "0.000000"},
        {"g", "0E-7", "0e-7"},
        {"g", "-0E2", "-0e+2"},
        {".0g", "3.14159265", "3"},
        {".0n", "3.14159265", "3"},
        {".1g", "3.14159265", "3"},
        {".2g", "3.14159265", "3.1"},
        {".5g", "3.14159265", "3.1416"},
        {".7g", "3.14159265", "3.141593"},
        {".8g", "3.14159265", "3.1415926"},
        {".9g", "3.14159265", "3.14159265"},
        {".10g", "3.14159265", "3.14159265"},

        {"%", "0E1", "0%"},
        {"%", "0E0", "0%"},
        {"%", "0E-1", "0%"},
        {"%", "0E-2", "0%"},
        {"%", "0E-3", "0.0%"},
        {"%", "0E-4", "0.00%"},

        {".3%", "0", "0.000%"},
        {".3%", "0E10", "0.000%"},
        {".3%", "0E-10", "0.000%"},
        {".3%", "2.34", "234.000%"},
        {".3%", "1.234567", "123.457%"},
        {".0%", "1.23", "123%"},

        {"e", "NaN", "NaN"},
        {"f", "-NaN123", "-NaN123"},
        {"+g", "NaN456", "+NaN456"},
        {".3e", "Inf", "Infinity"},
        {".16f", "-Inf", "-Infinity"},
        {".0g", "-sNaN", "-sNaN"},

        {"", "1.00", "1.00"},

        {"6", "123", "   123"},
        {"<6", "123", "123   "},
        {">6", "123", "   123"},
        {"^6", "123", " 123  "},
        {"=+6", "123", "+  123"},
        {"#<10", "NaN", "NaN#######"},
        {"#<10", "-4.3", "-4.3######"},
        {"#<+10", "0.0130", "+0.0130###"},
        {"#< 10", "0.0130", " 0.0130###"},
        {"@>10", "-Inf", "@-Infinity"},
        {"#>5", "-Inf", "-Infinity"},
        {"?^5", "123", "?123?"},
        {"%^6", "123", "%123%%"},
        {" ^6", "-45.6", "-45.6 "},
        {"/=10", "-45.6", "-/////45.6"},
        {"/=+10", "45.6", "+/////45.6"},
        {"/= 10", "45.6", " /////45.6"},

        {",", "1234567", "1,234,567"},
        {",", "123456", "123,456"},
        {",", "12345", "12,345"},
        {",", "1234", "1,234"},
        {",", "123", "123"},
        {",", "12", "12"},
        {",", "1", "1"},
        {",", "0", "0"},
        {",", "-1234567", "-1,234,567"},
        {",", "-123456", "-123,456"},
        {"7,", "123456", "123,456"},
        {"8,", "123456", " 123,456"},
        {"08,", "123456", "0,123,456"},
        {"+08,", "123456", "+123,456"},
        {" 08,", "123456", " 123,456"},
        {"08,", "-123456", "-123,456"},
        {"+09,", "123456", "+0,123,456"},

        {"07,", "1234.56", "1,234.56"},
        {"08,", "1234.56", "1,234.56"},
        {"09,", "1234.56", "01,234.56"},
        {"010,", "1234.56", "001,234.56"},
        {"011,", "1234.56", "0,001,234.56"},
        {"012,", "1234.56", "0,001,234.56"},
        {"08,.1f", "1234.5", "01,234.5"},

        {",", "1.23456789", "1.23456789"},
        {",%", "123.456789", "12,345.6789%"},
        {",e", "123456", "1.23456e+5"},
        {",E", "123456", "1.23456E+5"},

        {"a=-7.0", "0.12345", "aaaa0.1"},

        {"<^+15.20%", "inf", "<<+Infinity%<<<"},
        {"\x07>,%", "sNaN1234567", "sNaN1234567%"},
        {"=10.10%", "NaN123", "   NaN123%"},
    };

    for (const std::vector<const char *>& v : test_cases) {
        const char *fmt = v.at(0);
        const char *d = v.at(1);
        const char *result = v.at(2);
        assertEqual(Decimal(d).format(fmt), result);
        assertEqual(Decimal(std::string(d)).format(std::string(fmt)), result);
    }

    assertRaises(ValueError, [](){ Decimal(1).format("<>=10.10"); });
    const std::string fmt = "=" + std::to_string(MPD_SSIZE_MAX) + ".1";
    assertRaises(ValueError, [&](){ Decimal("1.23456789").format(fmt); });
}

/******************************************************************************/
/*                                  Run tests                                 */
/******************************************************************************/

struct test_case {
    const char *name;
    void (*f)(void);
};

static const size_t NUM_TESTS = 35;
static const std::array<struct test_case, NUM_TESTS> test_cases {
  {
    /* Context tests */
    { "ExceptionHierarchyTest",        ExceptionHierarchyTest },
    { "IEEEContextTest",               IEEEContextTest },
    { "ContextGetSetTest",             ContextGetSetTest },
    { "ContextInputValidationTest",    ContextInputValidationTest },
    { "SmallContextTest",              SmallContextTest },
    { "ContextReprTest",               ContextReprTest },

    /* Decimal tests */
    { "ExactConstructionTest",         ExactConstructionTest },
    { "InexactConstructionTest",       InexactConstructionTest },
    { "ConstructionExceptionTest",     ConstructionExceptionTest },

    { "AccessorTest",                  AccessorTest },

    { "UnaryOperatorTest",             UnaryOperatorTest },
    { "PointerUnaryOperatorTest",      PointerUnaryOperatorTest },

    { "ComparisonOperatorTest",        ComparisonOperatorTest },
    { "PointerComparisonOperatorTest", PointerComparisonOperatorTest },

    { "AssignmentOperatorTest",        AssignmentOperatorTest },
    { "PointerAssignmentOperatorTest", PointerAssignmentOperatorTest },

    { "ArithmeticOperatorTest",        ArithmeticOperatorTest },
    { "PointerArithmeticOperatorTest", PointerArithmeticOperatorTest },

    { "PredicateTest",                 PredicateTest },
    { "UnaryFunctionTest",             UnaryFunctionTest },

    { "CeilTest",                      CeilTest },
    { "FloorTest",                     FloorTest },
    { "TruncTest",                     TruncTest },

    { "BinaryFunctionTest",            BinaryFunctionTest },
    { "DivmodTest",                    DivmodTest },
    { "QuantizeTest",                  QuantizeTest },

    { "TernaryFunctionTest",           TernaryFunctionTest },

    { "IrregularFunctionTest",         IrregularFunctionTest },
    { "ApplyTest",                     ApplyTest },

    { "IntegerConversionTest",         IntegerConversionTest },

    { "ExactArithTest",                ExactArithTest },

    { "DataStructuresTest",            DataStructuresTest },
    { "LargeDataStructuresTest",       LargeDataStructuresTest },

    { "StringReprTest",                StringReprTest },
    { "FormatTest",                    FormatTest },
  }
};

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

/* run a single function */
static void
do_test(const struct test_case& t, std::vector<std::string>& status, size_t i)
{
    try {
        assertEqual(context, context_template);

        t.f();
    } catch (Failure& e) {
        status[i] = e.what();
    }
}

/* process a function list */
static int
do_tests(const std::array<struct test_case, NUM_TESTS>& tests)
{
    const size_t n = tests.size();
    std::vector<std::string> status(n, "PASS");

    for (size_t i = 0; i < n; i++) {
        std::cout << tests[i].name << " ... " << std::flush;
        do_test(tests[i], status, i);
        context = context_template;
        std::cout << status[i] << "\n" << std::flush;
    }

    std::cout << "\n" << std::flush;

    return exit_status(status);
}

/* process a file list, threaded */
static int
do_tests_threaded(const std::array<struct test_case, NUM_TESTS>& tests)
{
    const size_t n = tests.size();
    std::vector<std::string> status(n, "PASS");
    std::vector<std::thread> t(n);

    for (size_t i = 0; i < n; i++) {
        t[i] = std::thread(do_test, tests[i], std::ref(status), i);
    }

    for (size_t i = 0; i < n; i++) {
        t[i].join();
    }

    for (size_t i = 0; i < n; i++) {
        std::cout << tests[i].name << " ... " << status[i] << "\n" << std::flush;
    }

    std::cout << "\n" << std::flush;

    return exit_status(status);
}

/* repeatedly process a randomized function list */
static int
do_tests_repeat(const std::array<struct test_case, NUM_TESTS>& tests)
{
    const size_t n = tests.size();
    std::vector<std::string> status(n, "PASS");
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<size_t> a(n);

    for (size_t i = 0; i < n; i++) {
        a[i] = i;
    }

    for (int64_t i = 0; i < 100; i++) {
        std::shuffle(a.begin(), a.end(), g);

        for (size_t k = 0; k < n; k++) {
            do_test(tests[a[k]], status, a[k]);
            context = context_template;
        }

        if (exit_status(status) != EXIT_SUCCESS) {
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}

/* process a file list, threaded */
static int
do_tests_threaded_repeat(const std::array<struct test_case, NUM_TESTS>& tests)
{
    const size_t n = tests.size();
    std::vector<std::string> status(n, "PASS");
    std::vector<std::thread> t(n);
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<size_t> a(n);

    for (size_t i = 0; i < n; i++) {
        a[i] = i;
    }

    for (int64_t i = 0; i < 100; i++) {
        std::shuffle(a.begin(), a.end(), g);

        for (size_t k = 0; k < n; k++) {
            t[k] = std::thread(do_test, tests[a[k]], std::ref(status), a[k]);
        }

        for (size_t k = 0; k < n; k++) {
            t[k].join();
        }

        if (exit_status(status) != EXIT_SUCCESS) {
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}


/*
 * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=77704
 *
 * valgrind --tool=helgrind shows a data race in libstdc++.  The race
 * disappears when streams are used before calling any threads.
 */
static void
init_libc(void)
{
    std::ostringstream ss;
    ss << 1;
}

static void
usage(void)
{
    std::cerr << "apitest: usage: apitest [--custom] [--thread] [--repeat]" << std::endl;
    exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
    std::vector<std::string> args(argv + (argc!=0), argv + argc);
    bool custom_alloc = false;
    bool thread = false;
    bool repeat = false;

    for (auto arg : args) {
        if (!custom_alloc && arg == "--custom") {
            custom_alloc = true;
        }
        else if (!thread && arg == "--thread") {
            thread = true;
        }
        else if (!repeat && arg == "--repeat") {
            repeat = true;
        }
        else {
            usage();
        }
    }

    /* Initialize streams (see above) */
    init_libc();

    /* Initialize custom allocation functions */
    test::init_alloc(custom_alloc, /*check_alloc=*/false);

    /* Initialize context template */
    context_template = Context(9, 999999, -999999, ROUND_HALF_EVEN, 0, 0, 0);

    /* Initialize context for the main thread */
    context = context_template;

    /* Check version numbers */
    static_assert(MPD_MAJOR_VERSION == 4, "MPD_MAJOR_VERSION must be 4");
    static_assert(MPD_MINOR_VERSION == 0, "MPD_MINOR_VERSION must be 0");
    static_assert(MPD_MICRO_VERSION == 1, "MPD_MICRO_VERSION must be 1");

    if (mpd_version() != std::string("4.0.1")) {
        err_exit("mpd_version() != 4.0.1");
    }
    if (MPD_VERSION != std::string("4.0.1")) {
        err_exit("MPD_VERSION != 4.0.1");
    }

    /* Check fundamental libmpdec++ invariant */
    assertEqual(MPD_MINALLOC, decimal::MINALLOC);


    if (thread) {
        if (repeat) {
            return do_tests_threaded_repeat(test_cases);
        }
        else {
            return do_tests_threaded(test_cases);
        }
    }
    else {
        if (repeat) {
            return do_tests_repeat(test_cases);
        }
        else {
            return do_tests(test_cases);
        }
    }
}
