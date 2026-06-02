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


#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <ctime>

#include "mpdecimal.h"
#include "decimal.hh"


using decimal::Decimal;
using decimal::Context;
using decimal::context;


/* Nonsense version of escape-time algorithm for calculating a Mandelbrot
 * set. Just for benchmarking. */
void
color_point(Decimal& x0, const Decimal& y0, long maxiter)
{
    Decimal x = 0;
    Decimal y = 0;

    Decimal sq_x = 0;
    Decimal sq_y = 0;

    Decimal two{2};

    for (long i = 0; i < maxiter; i++) {
        y = x * y;
        y = y * two;
        y = y + y0;

        x = sq_x - sq_y;
        x = x + x0;

        sq_x = x * x;
        sq_y = y * y;
    }

    x0 = x;
}

int
main(int argc, char **argv)
{
    const double clocks_per_sec = CLOCKS_PER_SEC;
    clock_t start_clock, end_clock;
    uint32_t prec;
    long iter;

    assert(MPD_MINALLOC == 4);

    if (argc != 3) {
        fprintf(stderr, "usage: bench prec iter\n");
        exit(1);
    }
    prec = strtoul(argv[1], NULL, 10);
    iter = strtol(argv[2], NULL, 10);

    context.prec(prec);

    Decimal x0{"0.222"};
    Decimal y0{"0.333"};

    start_clock = clock();
    color_point(x0, y0, iter);
    end_clock = clock();

    std::cout << x0 << std::endl;

    fprintf(stderr, "time: %f\n\n", (end_clock-start_clock)/clocks_per_sec);

    return 0;
}

