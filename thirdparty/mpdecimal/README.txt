

libmpdec
========

libmpdec is a fast C/C++ library for correctly-rounded arbitrary precision
decimal floating point arithmetic.  It is a complete implementation of
Mike Cowlishaw/IBM's General Decimal Arithmetic Specification. The full
specification is available here:

http://speleotrove.com/decimal/


libmpdec will - with minor restrictions - also conform to the IEEE 754-2008
Standard for Floating-Point Arithmetic, provided that the appropriate context
parameters are set.

libmpdec is the basis for the decimal module in Python-3.3.


The library has been tested on the following platforms:

   amd64:  Linux, FreeBSD, OpenBSD, OpenSolaris, Windows

   ppc64:  AIX

   x86:    Linux, FreeBSD, OpenBSD, OpenSolaris, Windows

   mips32: Debian


libmpdec++
==========

libmpdec++ is a complete implementation of the General Decimal Arithmetic
Specification.  libmpdec++ is mostly a header library around libmpdec's
C functions.

The library frees users from manual memory management and has an easy API
with inline operators similar to the one in Python's decimal module. Like
Python's decimal module, libmpdec++ has a thread local context for inline
operators and other functions that use the implicit context.

In benchmarks the speed is close to libmpdec (about 4% slower due to the
copying, destructor overhead and the thread local context).

libmpdec++ has been tested on 64/32-bit Linux, 64/32-bit FreeBSD and OpenBSD
and 64/32-bit Windows.


Contact: Stefan Krah <skrah@bytereef.org>


