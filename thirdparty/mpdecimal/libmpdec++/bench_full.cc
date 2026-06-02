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
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "mpdecimal.h"
#include "decimal.hh"


using decimal::Decimal;
using decimal::Context;
using decimal::context;


/*
 * Example from: http://en.wikipedia.org/wiki/Mandelbrot_set
 *
 * Escape time algorithm for drawing the set:
 *
 * Point x0, y0 is deemed to be in the Mandelbrot set if the return
 * value is maxiter. Lower return values indicate how quickly points
 * escaped and can be used for coloring.
 */
int
color_point(const Decimal& x0, const Decimal& y0, const int maxiter)
{
    int i = 0;

    Decimal x = 0;
    Decimal y = 0;
    Decimal sq_x = 0;
    Decimal sq_y = 0;

    const Decimal two = 2;
    const Decimal four = 4;
    Decimal c = 0;

    for (i = 0; i < maxiter && c <= four; i++) {
        y = x * y;
        y *= two;
        y += y0;

        x = sq_x - sq_y;
        x += x0;

        sq_x = x * x;
        sq_y = y * y;
        c = sq_x + sq_y;
    }

    return i;
}

int
main(int argc, char **argv)
{
    const double clocks_per_sec = CLOCKS_PER_SEC;
    clock_t start_clock, end_clock;
    uint32_t prec = 19;
    int iter = 1000;
    int points[40][80];
    int i, j;

    if (argc != 3) {
        fprintf(stderr, "usage: ./bench prec iter\n");
        exit(1);
    }
    prec = strtoul(argv[1], NULL, 10);
    iter = strtol(argv[2], NULL, 10);

    context.prec(prec);

    Decimal x0;
    Decimal sqrt_2 = Decimal(2).sqrt();
    Decimal xstep = sqrt_2 / 40;
    Decimal ystep = sqrt_2 / 20;

    start_clock = clock();
    Decimal y0 = sqrt_2;
    for (i = 0; i < 40; i++) {
        x0 = -sqrt_2;
        for (j = 0; j < 80; j++) {
            points[i][j] = color_point(x0, y0, iter);
            x0 += xstep;
        }
        y0 -= ystep;
    }
    end_clock = clock();

#ifdef BENCH_VERBOSE
    for (i = 0; i < 40; i++) {
        for (j = 0; j < 80; j++) {
            if (points[i][j] == iter) {
                putchar('*');
            }
            else if (points[i][j] >= 10) {
                putchar('+');
            }
            else if (points[i][j] >= 5) {
                putchar('.');
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    putchar('\n');
#else
    (void)points; /* suppress gcc warning */
#endif

    printf("time: %f\n\n", (end_clock-start_clock)/clocks_per_sec);

    return 0;
}

