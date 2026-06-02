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


#include <cassert>
#include <climits>

#include <iostream>
#include <stdexcept>
#include <string>

#include "decimal.hh"


using decimal::Decimal;
using decimal::context;


/* The algorithm is not optimized for bignum arithmetic */
Decimal
pi(int prec)
{
    assert(1 <= prec && prec <= INT_MAX-2);
    context.prec(prec + 2);

    Decimal lasts = 0;
    Decimal t = 3;
    Decimal s = 3;
    Decimal n = 1;
    Decimal na = 0;
    Decimal d = 0;
    Decimal da = 24;

    while (s != lasts) {
        lasts = s;
        n += na;
        na += 8;
        d += da;
        da += 32;
        t = (t * n) / d;
        s += t;
    }

    context.prec(prec);
    return +s;
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
    size_t pos = 0;
    int prec = 0;

    if (argc != 2) {
        err_exit("usage: ./pi prec");
    }
    std::string s = argv[1];

    try {
        prec = std::stoi(s, &pos);
    } catch (const std::invalid_argument&) {
        err_exit("not a number");
    } catch (const std::out_of_range &) {
        err_exit("out of range");
    }

    if (pos < s.size()) {
        err_exit("trailing characters");
    }
    if (prec <= 0 || prec > 999999) {
        err_exit("prec must be in [1, 999999]");
    }

    std::cout << pi(prec) << std::endl;

    return 0;
}
