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


#include <iostream>

#include "decimal.hh"


using decimal::Decimal;
using decimal::MaxContext;
using decimal::context;

using decimal::ConversionSyntax;
using decimal::InvalidOperation;
using decimal::MallocError;

using decimal::DecRounded;
using decimal::DecInexact;


Decimal
f(const Decimal& n, const Decimal& m)
{
    if (n > m) {
        return f(m, n);
    }
    else if (m == 0) {
        return 1;
    }
    else if (n == m) {
        return n;
    }
    else {
        return f(n, (n + m).divint(2)) * f((n + m).divint(2) + 1, m);
    }
}

Decimal
factorial(const Decimal& n)
{
    context = MaxContext();

    // DecRounded can be skipped if integer results with non-zero
    // exponents are allowed.
    context.add_traps(DecInexact|DecRounded);

    return f(n, Decimal(0));
}

void
err_exit(const std::string& msg)
{
    std::cerr << msg << std::endl;
    std::exit(1);
}

int
main(int argc, char *argv[])
{
    Decimal n;

    if (argc != 2) {
        err_exit("usage: ./factorial n");
    }

    try {
        n = Decimal(argv[1]);
    }
    catch (ConversionSyntax&) {
        err_exit("invalid decimal string");
    }
    catch (InvalidOperation&) {
        err_exit("value exceeds internal limits");
    }
    catch (MallocError&) {
        err_exit("out of memory");
    }

    // The exponent could be nonzero, this is to avoid surprise at the result.
    if (!n.isinteger() || n.exponent() != 0 || n < 0) {
        err_exit("n must be a non-negative integer with exponent zero");
    }

    std::cout << factorial(n) << std::endl;

    return 0;
}
