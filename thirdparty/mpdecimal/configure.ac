AC_COPYRIGHT([
Copyright (c) 2008-2025 Stefan Krah. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
])

AH_TOP([
/*
 * The generated config.h is only included in runtest.cc, and there are
 * no plans to use it elsewhere.  All defines apart from HAVE_PTHREAD_H
 * are purely informational.
 */
])


AC_PREREQ([2.69])

AC_INIT([mpdecimal],
        [4.0.1],
        [mpdecimal-bugs@bytereef.org],
        [mpdecimal],
        [https://www.bytereef.org/mpdecimal/index.html])

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([Makefile
                 libmpdec/Makefile
                 libmpdec/mpdecimal.h
                 libmpdec/.pc/libmpdec.pc
                 libmpdec++/Makefile
                 libmpdec++/.pc/libmpdec++.pc
                 tests/Makefile
                 tests++/Makefile])

# Link files for out-of-tree builds:
AC_CONFIG_LINKS([CHANGELOG.txt:CHANGELOG.txt
                 COPYRIGHT.txt:COPYRIGHT.txt
                 INSTALL.txt:INSTALL.txt
                 Makefile.in:Makefile.in
                 README.txt:README.txt
                 config.guess:config.guess
                 config.h.in:config.h.in
                 config.sub:config.sub
                 configure:configure
                 configure.ac:configure.ac
                 install-sh:install-sh

                 doc/COPYRIGHT.txt:doc/COPYRIGHT.txt
                 doc/libmpdec.3:doc/libmpdec.3
                 doc/libmpdec++.3:doc/libmpdec++.3
                 doc/mpdecimal.3:doc/mpdecimal.3

                 libmpdec/Makefile.in:libmpdec/Makefile.in
                 libmpdec/Makefile.vc:libmpdec/Makefile.vc
                 libmpdec/README.txt:libmpdec/README.txt
                 libmpdec/basearith.c:libmpdec/basearith.c
                 libmpdec/basearith.h:libmpdec/basearith.h
                 libmpdec/bench.c:libmpdec/bench.c
                 libmpdec/bench_full.c:libmpdec/bench_full.c
                 libmpdec/bits.h:libmpdec/bits.h
                 libmpdec/constants.c:libmpdec/constants.c
                 libmpdec/constants.h:libmpdec/constants.h
                 libmpdec/context.c:libmpdec/context.c
                 libmpdec/convolute.c:libmpdec/convolute.c
                 libmpdec/convolute.h:libmpdec/convolute.h
                 libmpdec/crt.c:libmpdec/crt.c
                 libmpdec/crt.h:libmpdec/crt.h
                 libmpdec/difradix2.c:libmpdec/difradix2.c
                 libmpdec/difradix2.h:libmpdec/difradix2.h
                 libmpdec/fnt.c:libmpdec/fnt.c
                 libmpdec/fnt.h:libmpdec/fnt.h
                 libmpdec/fourstep.c:libmpdec/fourstep.c
                 libmpdec/fourstep.h:libmpdec/fourstep.h
                 libmpdec/io.c:libmpdec/io.c
                 libmpdec/io.h:libmpdec/io.h
                 libmpdec/mpalloc.c:libmpdec/mpalloc.c
                 libmpdec/mpalloc.h:libmpdec/mpalloc.h
                 libmpdec/mpdecimal.c:libmpdec/mpdecimal.c
                 libmpdec/mpdecimal32vc.h:libmpdec/mpdecimal32vc.h
                 libmpdec/mpdecimal64vc.h:libmpdec/mpdecimal64vc.h
                 libmpdec/mpdecimal.h.in:libmpdec/mpdecimal.h.in
                 libmpdec/mpsignal.c:libmpdec/mpsignal.c
                 libmpdec/numbertheory.c:libmpdec/numbertheory.c
                 libmpdec/numbertheory.h:libmpdec/numbertheory.h
                 libmpdec/sixstep.c:libmpdec/sixstep.c
                 libmpdec/sixstep.h:libmpdec/sixstep.h
                 libmpdec/transpose.c:libmpdec/transpose.c
                 libmpdec/transpose.h:libmpdec/transpose.h
                 libmpdec/typearith.h:libmpdec/typearith.h
                 libmpdec/umodarith.h:libmpdec/umodarith.h
                 libmpdec/vcdiv64.asm:libmpdec/vcdiv64.asm

                 libmpdec/examples/README.txt:libmpdec/examples/README.txt
                 libmpdec/examples/compare.c:libmpdec/examples/compare.c
                 libmpdec/examples/div.c:libmpdec/examples/div.c
                 libmpdec/examples/divmod.c:libmpdec/examples/divmod.c
                 libmpdec/examples/multiply.c:libmpdec/examples/multiply.c
                 libmpdec/examples/pow.c:libmpdec/examples/pow.c
                 libmpdec/examples/powmod.c:libmpdec/examples/powmod.c
                 libmpdec/examples/shift.c:libmpdec/examples/shift.c
                 libmpdec/examples/sqrt.c:libmpdec/examples/sqrt.c

                 libmpdec/.objs/README.txt:libmpdec/.objs/README.txt
                 libmpdec/.objs/symbols32.exp:libmpdec/.objs/symbols32.exp
                 libmpdec/.objs/symbols64.exp:libmpdec/.objs/symbols64.exp
                 libmpdec/.pc/libmpdec.pc.in:libmpdec/.pc/libmpdec.pc.in
                 libmpdec/.profile/train.sh:libmpdec/.profile/train.sh

                 libmpdec++/Makefile.in:libmpdec++/Makefile.in
                 libmpdec++/Makefile.vc:libmpdec++/Makefile.vc
                 libmpdec++/bench.cc:libmpdec++/bench.cc
                 libmpdec++/bench_full.cc:libmpdec++/bench_full.cc
                 libmpdec++/decimal.cc:libmpdec++/decimal.cc
                 libmpdec++/decimal.hh:libmpdec++/decimal.hh

                 libmpdec++/examples/factorial.cc:libmpdec++/examples/factorial.cc
                 libmpdec++/examples/pi.cc:libmpdec++/examples/pi.cc

                 libmpdec++/.objs/README.txt:libmpdec++/.objs/README.txt
                 libmpdec++/.pc/libmpdec++.pc.in:libmpdec++/.pc/libmpdec++.pc.in
                 libmpdec++/.profile/train.sh:libmpdec++/.profile/train.sh

                 tests/Makefile.in:tests/Makefile.in
                 tests/Makefile.vc:tests/Makefile.vc
                 tests/README.txt:tests/README.txt
                 tests/additional.decTest:tests/additional.decTest
                 tests/gettests.bat:tests/gettests.bat
                 tests/gettests.sh:tests/gettests.sh
                 tests/official.decTest:tests/official.decTest
                 tests/runshort.sh:tests/runshort.sh
                 tests/runshort_alloc.sh:tests/runshort_alloc.sh
                 tests/runtest.c:tests/runtest.c
                 tests/test.c:tests/test.c
                 tests/test.h:tests/test.h
                 tests/vctest.h:tests/vctest.h

                 tests/testdata_dist/baseconv.decTest:tests/testdata_dist/baseconv.decTest
                 tests/testdata_dist/binop_eq.decTest:tests/testdata_dist/binop_eq.decTest
                 tests/testdata_dist/cov.decTest:tests/testdata_dist/cov.decTest
                 tests/testdata_dist/divmod.decTest:tests/testdata_dist/divmod.decTest
                 tests/testdata_dist/divmod_eq.decTest:tests/testdata_dist/divmod_eq.decTest
                 tests/testdata_dist/extra.decTest:tests/testdata_dist/extra.decTest
                 tests/testdata_dist/fma_eq.decTest:tests/testdata_dist/fma_eq.decTest
                 tests/testdata_dist/format.decTest:tests/testdata_dist/format.decTest
                 tests/testdata_dist/getint.decTest:tests/testdata_dist/getint.decTest
                 tests/testdata_dist/invroot.decTest:tests/testdata_dist/invroot.decTest
                 tests/testdata_dist/largeint.decTest:tests/testdata_dist/largeint.decTest
                 tests/testdata_dist/maxprec.decTest:tests/testdata_dist/maxprec.decTest
                 tests/testdata_dist/powmod.decTest:tests/testdata_dist/powmod.decTest
                 tests/testdata_dist/powmod_eq.decTest:tests/testdata_dist/powmod_eq.decTest
                 tests/testdata_dist/shiftlr.decTest:tests/testdata_dist/shiftlr.decTest
                 tests/testdata_dist/testruntest.decTest:tests/testdata_dist/testruntest.decTest

                 tests++/Makefile.in:tests++/Makefile.in
                 tests++/Makefile.vc:tests++/Makefile.vc
                 tests++/README.txt:tests++/README.txt
                 tests++/additional.topTest:tests++/additional.topTest
                 tests++/apitest.cc:tests++/apitest.cc
                 tests++/gettests.bat:tests++/gettests.bat
                 tests++/gettests.sh:tests++/gettests.sh
                 tests++/official.topTest:tests++/official.topTest
                 tests++/runshort.sh:tests++/runshort.sh
                 tests++/runshort_alloc.sh:tests++/runshort_alloc.sh
                 tests++/runtest.cc:tests++/runtest.cc
                 tests++/test.cc:tests++/test.cc
                 tests++/test.hh:tests++/test.hh
                 tests++/vctest.hh:tests++/vctest.hh])

# ==============================================================================
#                               MPD_HEADER_CONFIG
# ==============================================================================

CONFIG_64="
/* ABI: 64-bit */
#define MPD_CONFIG_64 1

#ifdef MPD_CONFIG_32
  #error \"cannot use MPD_CONFIG_32 with 64-bit header.\"
#endif

#ifdef CONFIG_32
  #error \"cannot use CONFIG_32 with 64-bit header.\"
#endif"

CONFIG_32="
/* ABI: 32-bit */
#define MPD_CONFIG_32 1

#ifdef MPD_CONFIG_64
  #error \"cannot use MPD_CONFIG_64 with 32-bit header.\"
#endif

#ifdef CONFIG_64
  #error \"cannot use CONFIG_64 with 32-bit header.\"
#endif"

CONFIG_32_LEGACY="
/* ABI: 32-bit */
#define MPD_CONFIG_32 1

/* libmpdec was compiled without support for int64_t */
#define MPD_LEGACY_COMPILER 1

#ifdef MPD_CONFIG_64
  #error \"cannot use MPD_CONFIG_64 with 32-bit header.\"
#endif

#ifdef CONFIG_64
  #error \"cannot use CONFIG_64 with 32-bit header.\"
#endif"

CONFIG_UNIVERSAL="
/* Mac OS X: support for building universal binaries */
#if defined(MPD_CONFIG_64) || defined(MPD_CONFIG_32)
  #error \"cannot use MPD_CONFIG_64 or MPD_CONFIG_32 with universal header.\"
#endif

#if defined(CONFIG_64) || defined(CONFIG_32)
  #error \"cannot use CONFIG_64 or CONFIG_32 with universal header.\"
#endif

#if defined(__ppc__)
  #define MPD_CONFIG_32 1
  #ifdef UNIVERSAL
    #define CONFIG_32
    #define ANSI
  #endif
#elif defined(__ppc64__)
  #define MPD_CONFIG_64 1
  #ifdef UNIVERSAL
    #define CONFIG_64
    #define ANSI
  #endif
#elif defined(__i386__)
  #define MPD_CONFIG_32 1
  #ifdef UNIVERSAL
    #define CONFIG_32
    #define ANSI
  #endif
#elif defined(__x86_64__)
  #define MPD_CONFIG_64 1
  #ifdef UNIVERSAL
    #define CONFIG_64
    #define ASM
  #endif
#elif defined(__arm64__)
  #define MPD_CONFIG_64 1
  #ifdef UNIVERSAL
    #define CONFIG_64
    #define ANSI
  #endif
#else
  #error \"unknown architecture for universal build.\"
#endif"

CONFIG_UNIVERSAL_AIX_UINT128="
/* AIX: support for multilib */
#if defined(MPD_CONFIG_64) || defined(MPD_CONFIG_32)
  #error \"cannot use MPD_CONFIG_64 or MPD_CONFIG_32 with multilib header.\"
#endif

#if defined(CONFIG_64) || defined(CONFIG_32)
  #error \"cannot use CONFIG_64 or CONFIG_32 with multilib header.\"
#endif

#if defined(__64BIT__)
  #define MPD_CONFIG_64 1
  #ifdef UNIVERSAL
    #define CONFIG_64
    #define ANSI
    #define HAVE_UINT128_T
  #endif
#else
  #define MPD_CONFIG_32 1
  #ifdef UNIVERSAL
    #define CONFIG_32
    #define ANSI
  #endif
#endif"

CONFIG_UNIVERSAL_AIX_ANSI64="
/* AIX: support for multilib */
#if defined(MPD_CONFIG_64) || defined(MPD_CONFIG_32)
  #error \"cannot use MPD_CONFIG_64 or MPD_CONFIG_32 with multilib header.\"
#endif

#if defined(CONFIG_64) || defined(CONFIG_32)
  #error \"cannot use CONFIG_64 or CONFIG_32 with multilib header.\"
#endif

#if defined(__64BIT__)
  #define MPD_CONFIG_64 1
  #ifdef UNIVERSAL
    #define CONFIG_64
    #define ANSI
  #endif
#else
  #define MPD_CONFIG_32 1
  #ifdef UNIVERSAL
    #define CONFIG_32
    #define ANSI
  #endif
#endif"

# ==============================================================================
#                         Detect build and host systems
# ==============================================================================

AC_CANONICAL_HOST

# ==============================================================================
#                              Select library names
# ==============================================================================

# MinGW/Cygwin/MSYS2 support:
ENABLE_MINGW="no"

# Set library names and linker flags:
FPIC="-fPIC"
LIBSTATIC=libmpdec.a
LIBSHARED_USE_AR="no"
LIBIMPORT=
LINK_STATIC=
LINK_DYNAMIC=
case $host in
  *-*-darwin*)
    LIBNAME="libmpdec.dylib"
    LIBSONAME="libmpdec.4.dylib"
    LIBSHARED="libmpdec.4.0.1.dylib"
    CONFIGURE_LDFLAGS="-dynamiclib $FPIC -install_name \$(libdir)/$LIBSONAME -compatibility_version 4.0 -current_version 4.0.1"
    ;;
  *-*-aix*)
    LIBNAME=
    LIBSONAME=
    LIBSHARED="shr.o"
    LIBSHARED_USE_AR="yes"
    CONFIGURE_LDFLAGS="-shared $FPIC -Wl,-bnoentry -Wl,-bE:.objs/symbols.exp"
    LINK_STATIC="-Wl,-bstatic"
    LINK_DYNAMIC="-Wl,-bshared"
    ;;
  *-*-mingw*)
    FPIC=
    LIBNAME=
    LIBIMPORT="libmpdec.dll.a"
    LIBSONAME=
    LIBSHARED="libmpdec-4.dll"
    CONFIGURE_LDFLAGS="-shared -Wl,--out-implib,$LIBIMPORT"
    ENABLE_MINGW="yes"
    ;;
  *-*-cygwin*)
    FPIC=
    LIBNAME=
    LIBIMPORT="libmpdec.dll.a"
    LIBSONAME=
    LIBSHARED="cygmpdec-4.dll"
    CONFIGURE_LDFLAGS="-shared -Wl,--out-implib,$LIBIMPORT"
    ENABLE_MINGW="yes"
    ;;
  *-*-msys)
    FPIC=
    LIBNAME=
    LIBIMPORT="libmpdec.dll.a"
    LIBSONAME=
    LIBSHARED="msys-mpdec-4.dll"
    CONFIGURE_LDFLAGS="-shared -Wl,--out-implib,$LIBIMPORT"
    ENABLE_MINGW="yes"
    ;;
  *)
    LIBNAME="libmpdec.so"
    LIBSONAME="libmpdec.so.4"
    LIBSHARED="libmpdec.so.4.0.1"
    CONFIGURE_LDFLAGS="-shared $FPIC -Wl,-soname,$LIBSONAME"
    ;;
esac

LIBSTATIC_CXX=libmpdec++.a
LIBIMPORT_CXX=
case $host in
  *-*-darwin*)
    LIBNAME_CXX="libmpdec++.dylib"
    LIBSONAME_CXX="libmpdec++.4.dylib"
    LIBSHARED_CXX="libmpdec++.4.0.1.dylib"
    CONFIGURE_LDXXFLAGS="-dynamiclib $FPIC -install_name \$(libdir)/$LIBSONAME_CXX -compatibility_version 4.0 -current_version 4.0.1"
    ;;
  *-*-aix*)
    LIBNAME_CXX=
    LIBSONAME_CXX=
    LIBSHARED_CXX="shr.o"
    CONFIGURE_LDXXFLAGS="-shared $FPIC -Wl,-bnoentry -Wl,-bE:.objs/symbols.exp"
    ;;
  *-*-mingw*)
    LIBNAME_CXX=
    LIBIMPORT_CXX="libmpdec++.dll.a"
    LIBSONAME_CXX=
    LIBSHARED_CXX="libmpdec++-4.dll"
    CONFIGURE_LDXXFLAGS="-shared -Wl,--out-implib,$LIBIMPORT_CXX"
    ;;
  *-*-cygwin*)
    LIBNAME_CXX=
    LIBIMPORT_CXX="libmpdec++.dll.a"
    LIBSONAME_CXX=
    LIBSHARED_CXX="cygmpdec++-4.dll"
    CONFIGURE_LDXXFLAGS="-shared -Wl,--out-implib,$LIBIMPORT_CXX"
    ;;
  *-*-msys)
    LIBNAME_CXX=
    LIBIMPORT_CXX="libmpdec++.dll.a"
    LIBSONAME_CXX=
    LIBSHARED_CXX="msys-mpdec++-4.dll"
    CONFIGURE_LDXXFLAGS="-shared -Wl,--out-implib,$LIBIMPORT_CXX"
    ;;
  *)
    LIBNAME_CXX="libmpdec++.so"
    LIBSONAME_CXX="libmpdec++.so.4"
    LIBSHARED_CXX="libmpdec++.so.4.0.1"
    CONFIGURE_LDXXFLAGS="-shared $FPIC -Wl,-soname,$LIBSONAME_CXX"
    ;;
esac

AC_SUBST(FPIC)
AC_SUBST(LIBSTATIC)
AC_SUBST(LIBNAME)
AC_SUBST(LIBSONAME)
AC_SUBST(LIBSHARED)
AC_SUBST(LIBIMPORT)
AC_SUBST(LIBSHARED_USE_AR)
AC_SUBST(LINK_STATIC)
AC_SUBST(LINK_DYNAMIC)
AC_SUBST(LIBSTATIC_CXX)
AC_SUBST(LIBNAME_CXX)
AC_SUBST(LIBSONAME_CXX)
AC_SUBST(LIBSHARED_CXX)
AC_SUBST(LIBIMPORT_CXX)
AC_SUBST(ENABLE_MINGW)

# ==============================================================================
#                                  User options
# ==============================================================================

# Check whether to build libmpdec++:
AC_MSG_CHECKING(for --enable-cxx)
AC_ARG_ENABLE(cxx, AS_HELP_STRING([--enable-cxx],
                                  [enable building libmpdec++ (default is yes)]))

ENABLE_CXX="$enable_cxx"
if test -z "$ENABLE_CXX"
then
  if test x"$MACHINE" = x"ansi-legacy"; then
    ENABLE_CXX="no"
  else
    ENABLE_CXX="yes"
  fi
fi
AC_MSG_RESULT($ENABLE_CXX)

# Check whether to build the static libraries:
AC_MSG_CHECKING(for --enable-static)
AC_ARG_ENABLE(static, AS_HELP_STRING([--enable-static],
                                     [enable building static libraries (default is yes)]))

ENABLE_STATIC="$enable_static"
if test -z "$ENABLE_STATIC"
then
    ENABLE_STATIC="yes"
fi
AC_MSG_RESULT($ENABLE_STATIC)

# Check whether to build the shared libraries:
AC_MSG_CHECKING(for --enable-shared)
AC_ARG_ENABLE(shared, AS_HELP_STRING([--enable-shared],
                                     [enable building shared libraries (default is yes)]))

ENABLE_SHARED="$enable_shared"
if test -z "$ENABLE_SHARED"
then
  ENABLE_SHARED="yes"
fi
AC_MSG_RESULT($ENABLE_SHARED)

# Check whether at least one library is enabled:
if test x"$ENABLE_STATIC" = x"no" -a x"$ENABLE_SHARED" = x"no"
then
  AC_MSG_ERROR([at least one of --enable-static or --enable-shared must be set])
fi

# AIX: both static and shared libraries must be enabled:
case $host in
  *-*-aix*)
    if test x"$ENABLE_STATIC" = x"no" -o x"$ENABLE_SHARED" = x"no"
    then
      AC_MSG_ERROR([the AIX build requires --enable-static and --enable-shared])
    fi
    ;;
esac

# Check whether to install the documentation:
AC_MSG_CHECKING(for --enable-doc)
AC_ARG_ENABLE(doc, AS_HELP_STRING([--enable-doc],
                                  [enable installing the documentation (default is yes)]))

ENABLE_DOC="$enable_doc"
if test -z "$ENABLE_DOC"
then
  ENABLE_DOC="yes"
fi
AC_MSG_RESULT($ENABLE_DOC)

# Check whether to install the pkg-config files:
AC_MSG_CHECKING(for --enable-pc)
AC_ARG_ENABLE(pc, AS_HELP_STRING([--enable-pc],
                                 [enable installing the pkg-config files (default is yes)]))

ENABLE_PC="$enable_pc"
if test -z "$ENABLE_PC"
then
  ENABLE_PC="yes"
fi
AC_MSG_RESULT($ENABLE_PC)

AC_SUBST(ENABLE_CXX)
AC_SUBST(ENABLE_STATIC)
AC_SUBST(ENABLE_SHARED)
AC_SUBST(ENABLE_DOC)
AC_SUBST(ENABLE_PC)

# ==============================================================================
#                              Compilers and flags
# ==============================================================================

# Save initial compiler flags:
INITIAL_CFLAGS="$CFLAGS"
INITIAL_CXXFLAGS="$CXXFLAGS"
INITIAL_LDFLAGS="$LDFLAGS"
INITIAL_LDXXFLAGS="$LDXXFLAGS"

# Rename compiler in case $CC=cc:
case $CC in
  cc)
    case $build in
      *-*-freebsd* | *-*-openbsd* | *-*-darwin*)
        CC=clang
        ;;
      *-*-netbsd*)
        CC=gcc
        ;;
      *-*-solaris* | *-*-sunos*)
        CC=suncc
        ;;
    esac
    ;;
esac

case $CXX in
  c++)
    case $build in
      *-*-freebsd* | *-*-openbsd* | *-*-darwin*)
        CXX=clang++
        ;;
      *-*-netbsd*)
        CXX=g++
        ;;
    esac
    ;;
esac

# Language and compiler:
AC_LANG([C])

# Preference of tested compilers:
case $host in
  *-*-aix*)
    PREFERRED_CC="ibm-clang_r ibm-clang gcc xlc_r xlc cc"
    PREFERRED_CXX="ibm-clang++_r g++ c++"
    ;;
  *-*-freebsd* | *-*-openbsd*)
    PREFERRED_CC="clang gcc cc"
    PREFERRED_CXX="clang++ g++ c++"
    ;;
  *)
    PREFERRED_CC="gcc icc clang icx suncc ccomp cc"
    PREFERRED_CXX="g++ icpc clang++ icpx c++"
    ;;
esac

# Find CC:
saved_cflags="$CFLAGS"
saved_ldflags="$LDFLAGS"
AC_PROG_CC([$PREFERRED_CC])
CFLAGS="$saved_cflags"
LDFLAGS="$saved_ldflags"

# These compilers do not fully support C++11.  Disable CXX to avoid mixing
# different C and C++ compilers:
case $CC in
  *xlc* | suncc | ccomp)
    ENABLE_CXX="no"
    ;;
esac

# Find CXX:
if test x"$ENABLE_CXX" = x"yes"; then
  saved_cxxflags="$CXXFLAGS"
  saved_ldxxflags="$LDXXFLAGS"
  AC_PROG_CXX([$PREFERRED_CXX])
  CXXFLAGS="$saved_cxxflags"
  LDXXFLAGS="$saved_ldxxflags"
fi

# Check availability of -O2:
AC_MSG_CHECKING(for -O2)
saved_cflags="$CFLAGS"
saved_ldflags="$LDFLAGS"
CFLAGS="-O2"
LDFLAGS=
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[have_O2=yes],[have_O2=no])
AC_MSG_RESULT($have_O2)
CFLAGS="$saved_cflags"
LDFLAGS="$saved_ldflags"

# Find ar and ranlib:
AC_CHECK_TOOL(AR, ar, ar)
AC_PROG_RANLIB

# Force explicit configuration.  This section must be here because the size
# checks in the next section require the correct CFLAGS.
AC_ARG_VAR(MACHINE, [
force configuration: x64, uint128, ansi64, ppro, ansi32, ansi-legacy, universal])

M64=
M32=
if test -n "$MACHINE"; then
  case $host in
    *-*-aix*)
      case $CC in
        *xlc*)
          M64="-q64"
          M32="-q32"
          ;;
        *gcc*)
          M64="-maix64"
          M32="-maix32"
          ;;
        *)
          M64="-m64"
          M32="-m32"
          ;;
      esac
      ;;
    *)
      M64="-m64"
      M32="-m32"
      ;;
  esac

  case "$MACHINE" in
    x64 | uint128 | ansi64)
      CFLAGS="$CFLAGS $M64"
      CXXFLAGS="$CXXFLAGS $M64"
      LDFLAGS="$LDFLAGS $M64"
      LDXXFLAGS="$LDXXFLAGS $M64"
      ;;
    ppro | ansi32 | ansi-legacy)
      CFLAGS="$CFLAGS $M32"
      CXXFLAGS="$CXXFLAGS $M32"
      LDFLAGS="$LDFLAGS $M32"
      LDXXFLAGS="$LDXXFLAGS $M64"
      ;;
    universal)
      :
      ;;
    *)
      AC_MSG_ERROR([invalid MACHINE variable: $MACHINE])
      ;;
  esac

  AC_MSG_CHECKING(whether the toolchain supports the chosen ABI)
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[]])],
                 [machine_supported=yes],
                 [machine_supported=no],
                 [machine_supported=undefined])
  AC_MSG_RESULT($machine_supported)
  if test "$machine_supported" = no; then
    AC_MSG_ERROR([toolchain cannot handle MACHINE=$MACHINE])
  fi
fi

# Compiler dependent settings:
MPD_PTHREAD=
MPD_WARN=
MPD_WARNXX=
MPD_OPT="-O2"
MPD_PGEN=
MPD_PUSE=
CONFIG_UNIVERSAL_AIX=
FILTER_FOR_STATIC=
case $CC in
  *gcc*)
    CONFIG_UNIVERSAL_AIX=$CONFIG_UNIVERSAL_AIX_UINT128
    MPD_PTHREAD="-pthread"
    MPD_WARN="-Wall -Wextra -Wno-unknown-pragmas -std=c99 -pedantic"
    MPD_WARNXX="-Wall -Wextra -std=c++11 -pedantic"
    MPD_OPT="-DNDEBUG -O2"
    MPD_PGEN="-fprofile-generate -fprofile-values"
    MPD_PUSE="-fprofile-use -freorder-blocks"
    FILTER_FOR_STATIC="-flto% -ffat-lto-objects"
    ;;
  *icc*)
    AR=xiar
    CXX=icpc
    MPD_PTHREAD="-pthread"
    MPD_WARN="-Wall -Wextra -Wno-unknown-pragmas -std=c99 -pedantic -diag-disable=11074,11076"
    MPD_WARNXX="-Wall -Wextra -std=c++11 -pedantic -diag-disable=11074,11076"
    MPD_OPT="-DNDEBUG -O2"
    MPD_PGEN="-wd11505 -prof-gen"
    MPD_PUSE="-wd11505 -prof-use"
    ;;
  *clang* | *icx* | *emcc*)
    CONFIG_UNIVERSAL_AIX=$CONFIG_UNIVERSAL_AIX_UINT128
    MPD_PTHREAD="-pthread"
    MPD_WARN="-Wall -Wextra -Wno-unknown-pragmas -std=c99 -pedantic"
    MPD_WARNXX="-Wall -Wextra -Wexit-time-destructors -std=c++11 -pedantic"
    MPD_OPT="-DNDEBUG -O2"
    ;;
  *xlc*)
    CONFIG_UNIVERSAL_AIX=$CONFIG_UNIVERSAL_AIX_ANSI64
    CONFIGURE_LDFLAGS="-qmkshrobj -bnoentry -bE:.objs/symbols.exp"
    LINK_STATIC="-bstatic"
    LINK_DYNAMIC="-bshared"
    MPD_PTHREAD="-qthreaded -D_THREAD_SAFE"
    MPD_WARN="-qlanglvl=stdc99"
    MPD_OPT="-DNDEBUG -O2 -qalias=ansi -qmaxmem=-1"
    ;;
  *suncc*)
    MPD_WARN="-xc99"
    MPD_OPT="-DNDEBUG -O2"
    ;;
  *ccomp*)
    ENABLE_SHARED=no
    LINK_STATIC="-Wl,-znoexecstack"
    MPD_WARN="-Wall -Wno-unknown-pragmas -std=c99 -fstruct-passing"
    MPD_OPT="-DNDEBUG -O2"
    ;;
  *)
    ;;
esac

AC_ARG_VAR(LDXXFLAGS, [C++ linker flags])

# These variables are set unconditionally because CONFIGURE_LDFLAGS etc.
# require the compiler frontends.  We leave them in the Makefiles in case
# someone needs to edit the Makefiles manually.
LD="$CC"
LDXX="$CXX"

AC_SUBST(CC)
AC_SUBST(LD)
AC_SUBST(CXX)
AC_SUBST(LDXX)
AC_SUBST(FILTER_FOR_STATIC)
AC_SUBST(MPD_PTHREAD)
AC_SUBST(MPD_PGEN)
AC_SUBST(MPD_PUSE)

# ==============================================================================
#                   Headers, types, assembly, install program
# ==============================================================================

# Check for header files:
AC_CHECK_HEADERS(pthread.h)

# Type availability checks:
AC_TYPE_SIZE_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_CHECK_TYPE(__uint128_t, AC_DEFINE(HAVE_UINT128_T, 1,
              [Define if your compiler provides __uint128_t.]),,)

# Sizes of various types:
AC_CHECK_SIZEOF(size_t, 4)
AC_CHECK_SIZEOF(__uint128_t, 16)

# x64 with gcc asm:
AC_MSG_CHECKING(for x64 gcc inline assembler)
AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[
__asm__ __volatile__ ("movq %rcx, %rax");
]])],[have_gcc_asm_for_x64=yes],[have_gcc_asm_for_x64=no])
AC_MSG_RESULT($have_gcc_asm_for_x64)
if test "$have_gcc_asm_for_x64" = yes; then
AC_DEFINE(HAVE_GCC_ASM_FOR_X64, 1,
[Define if we can use x64 gcc inline assembler.])
fi

# x87 with gcc asm:
AC_MSG_CHECKING(for x87 gcc inline assembler)
AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[
  unsigned short cw;
  __asm__ __volatile__ ("fnstcw %0" : "=m" (cw));
  __asm__ __volatile__ ("fldcw %0" : : "m" (cw));
]])],[have_gcc_asm_for_x87=yes],[have_gcc_asm_for_x87=no])
AC_MSG_RESULT($have_gcc_asm_for_x87)
if test "$have_gcc_asm_for_x87" = yes; then
AC_DEFINE(HAVE_GCC_ASM_FOR_X87, 1,
[Define if we can use x87 gcc inline assembler.])
fi

# Install program:
AC_PROG_INSTALL
AC_SUBST(INSTALL)

# ==============================================================================
#                             Detect toolchain bugs
# ==============================================================================

# _FORTIFY_SOURCE wrappers for memmove and bcopy are incorrect:
#    http://sourceware.org/ml/libc-alpha/2010-12/msg00009.html
AC_MSG_CHECKING(for glibc _FORTIFY_SOURCE/memmove bug)
saved_cflags="$CFLAGS"
saved_ldflags="$LDFLAGS"
CFLAGS="-O2 -D_FORTIFY_SOURCE=2"
if test "$have_O2" = no; then
  CFLAGS=
fi
LDFLAGS=
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void foo(void *p, void *q) { memmove(p, q, 19); }
int main() {
  char a[32] = "123456789000000000";
  foo(&a[9], a);
  if (strcmp(a, "123456789123456789000000000") != 0)
    return 1;
  foo(a, &a[9]);
  if (strcmp(a, "123456789000000000") != 0)
    return 1;
  return 0;
}
]])],
[have_glibc_memmove_bug=no],
[have_glibc_memmove_bug=yes],
[have_glibc_memmove_bug=undefined])
CFLAGS="$saved_cflags"
LDFLAGS="$saved_ldflags"
AC_MSG_RESULT($have_glibc_memmove_bug)
if test "$have_glibc_memmove_bug" = yes; then
  AC_DEFINE(HAVE_GLIBC_MEMMOVE_BUG, 1,
  [Define if glibc has incorrect _FORTIFY_SOURCE wrappers
   for memmove and bcopy.])
fi

# ==============================================================================
#                            Optimized configurations
# ==============================================================================

# Auto-detect machine dependent settings:
AIX_AR=
AIX_RANLIB=
EXPORTSYMS=
OBJECT_SUFFIX=
DETECTED_MACHINE=
if test $ac_cv_sizeof_size_t -eq 8; then
  AIX_AR="ar -X64"
  AIX_RANLIB="ranlib -X64"
  EXPORTSYMS="symbols64.exp"
  OBJECT_SUFFIX="4_64.o"
  if test $have_gcc_asm_for_x64 = yes; then
    DETECTED_MACHINE="x64"
  elif test $ac_cv_type___uint128_t = yes; then
    DETECTED_MACHINE="uint128"
  else
    DETECTED_MACHINE="ansi64"
  fi
else
  AIX_AR="ar -X32"
  AIX_RANLIB="ranlib -X32"
  EXPORTSYMS="symbols32.exp"
  OBJECT_SUFFIX="4.o"
  DETECTED_MACHINE="ansi32"
  if test $have_gcc_asm_for_x87 = yes; then
    case $CC in
      *gcc* | *clang*) # icc >= 11.0 works as well
         case $host in
           *-*-darwin*)
             ;;
           *)
             DETECTED_MACHINE="ppro"
             ;;
         esac
         ;;
    esac
  fi
fi

if test -z "$MACHINE"; then
  MACHINE="$DETECTED_MACHINE"
fi

# Set configuration variables:
MPD_ABI=
MPD_PREC=9
case "$MACHINE" in
  x64)
    MPD_HEADER_CONFIG=$CONFIG_64
    MPD_ABI=$M64
    MPD_CONFIG="-DCONFIG_64 -DASM"
    CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $M64"
    CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $M64"
    MPD_PREC=19
    ;;
  uint128)
    MPD_HEADER_CONFIG=$CONFIG_64
    MPD_ABI=$M64
    MPD_CONFIG="-DCONFIG_64 -DANSI -DHAVE_UINT128_T"
    CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $M64"
    CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $M64"
    MPD_PREC=19
    ;;
  ansi64)
    MPD_HEADER_CONFIG=$CONFIG_64
    MPD_ABI=$M64
    MPD_CONFIG="-DCONFIG_64 -DANSI"
    CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $M64"
    CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $M64"
    MPD_PREC=19
    ;;
  ppro)
    MPD_HEADER_CONFIG=$CONFIG_32
    MPD_ABI=$M32
    MPD_CONFIG="-DCONFIG_32 -DPPRO -DASM"
    CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $M32"
    CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $M32"
    # Some versions of gcc miscompile inline asm:
    #    http://gcc.gnu.org/bugzilla/show_bug.cgi?id=46491
    #    http://gcc.gnu.org/ml/gcc/2010-11/msg00366.html
    case $CC in
      *gcc*)
          AC_MSG_CHECKING(for gcc ipa-pure-const bug)
          saved_cflags="$CFLAGS"
          saved_ldflags="$LDFLAGS"
          CFLAGS="-O2"
          LDFLAGS=
          AC_RUN_IFELSE([AC_LANG_SOURCE([[
          __attribute__((noinline)) int
          foo(int *p) {
            int r;
            asm ( "movl \$6, (%1)\n\t"
                  "xorl %0, %0\n\t"
                  : "=r" (r) : "r" (p) : "memory"
            );
            return r;
          }
          int main() {
            int p = 8;
            if ((foo(&p) ? : p) != 6)
              return 1;
            return 0;
          }
          ]])],
          [have_ipa_pure_const_bug=no],
          [have_ipa_pure_const_bug=yes],
          [have_ipa_pure_const_bug=undefined])
          CFLAGS="$saved_cflags"
          LDFLAGS="$saved_ldflags"
          AC_MSG_RESULT($have_ipa_pure_const_bug)
          if test "$have_ipa_pure_const_bug" = yes; then
            MPD_CONFIG="$MPD_CONFIG -fno-ipa-pure-const"
            AC_DEFINE(HAVE_IPA_PURE_CONST_BUG, 1,
                      [Define if gcc has the ipa-pure-const bug.])
          fi
          ;;
    esac
    ;;
  ansi32)
    MPD_HEADER_CONFIG=$CONFIG_32
    MPD_ABI=$M32
    MPD_CONFIG="-DCONFIG_32 -DANSI"
    CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $M32"
    CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $M32"
    ;;
  ansi-legacy)
    MPD_HEADER_CONFIG=$CONFIG_32_LEGACY
    MPD_ABI=$M32
    MPD_CONFIG="-DCONFIG_32 -DANSI -DLEGACY_COMPILER"
    CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $M32"
    CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $M32"
    ;;
  universal)
    MPD_HEADER_CONFIG=$CONFIG_UNIVERSAL
    MPD_CONFIG="-DUNIVERSAL"
    ;;
  *)
    AC_MSG_ERROR([cannot detect MACHINE])
    ;;
esac

# Special cases:
MPD_CXXOPT=
MPD_GNU99=
case $host in
  *-*-aix*)
    AR=$AIX_AR
    RANLIB=$AIX_RANLIB
    MPD_OPT="-D_THREAD_SAFE $MPD_OPT"
    MPD_CXXOPT="-D_THREAD_SAFE"
    case "$MACHINE" in
    universal)
      MPD_HEADER_CONFIG=$CONFIG_UNIVERSAL_AIX
      AR="ar -X32_64"
      RANLIB="ranlib -X32_64"
      ;;
    esac
    ;;
  *-*-netbsd*)
    MPD_OPT="-D_REENTRANT $MPD_OPT"
    MPD_CXXOPT="-D_REENTRANT"
    ;;
  *-*-solaris* | *-*-sunos*)
    MPD_OPT="-D_REENTRANT $MPD_OPT"
    MPD_CXXOPT="-D_REENTRANT"
    case $CC in
      *gcc*)
        MPD_GNU99=-std=gnu99
        ;;
    esac
    ;;
esac

AC_SUBST(AR)
AC_SUBST(RANLIB)
AC_SUBST(EXPORTSYMS)
AC_SUBST(OBJECT_SUFFIX)
AC_SUBST(MPD_HEADER_CONFIG)
AC_SUBST(MPD_GNU99)
AC_SUBST(MPD_PREC)

# ==============================================================================
#                         Substitute remaining variables
# ==============================================================================

if test -z "$INITIAL_CFLAGS"; then
  CONFIGURE_LIBMPDEC_CFLAGS="$MPD_WARN $MPD_CONFIG $MPD_OPT $MPD_ABI"
  CONFIGURE_CFLAGS="$MPD_WARN $MPD_OPT $MPD_ABI"
else
  CONFIGURE_LIBMPDEC_CFLAGS="$MPD_WARN $MPD_CONFIG $MPD_OPT $MPD_ABI $INITIAL_CFLAGS"
  CONFIGURE_CFLAGS="$MPD_WARN $MPD_OPT $MPD_ABI $INITIAL_CFLAGS"
fi

if test "$have_glibc_memmove_bug" = yes; then
  CONFIGURE_LIBMPDEC_CFLAGS="$CONFIGURE_LIBMPDEC_CFLAGS -U_FORTIFY_SOURCE"
  CONFIGURE_CFLAGS="$CONFIGURE_CFLAGS -U_FORTIFY_SOURCE"
fi

if test -z "$INITIAL_CXXFLAGS"; then
  CONFIGURE_CXXFLAGS="$MPD_WARNXX $MPD_CXXOPT -DNDEBUG -O3 $MPD_ABI"
else
  CONFIGURE_CXXFLAGS="$MPD_WARNXX $MPD_CXXOPT -DNDEBUG -O3 $MPD_ABI $INITIAL_CXXFLAGS"
fi

if test -n "$INITIAL_LDFLAGS"; then
  CONFIGURE_LDFLAGS="$CONFIGURE_LDFLAGS $INITIAL_LDFLAGS"
fi

if test -n "$INITIAL_LDXXFLAGS"; then
  CONFIGURE_LDXXFLAGS="$CONFIGURE_LDXXFLAGS $INITIAL_LDXXFLAGS"
fi

AC_SUBST(CONFIGURE_LIBMPDEC_CFLAGS)
AC_SUBST(CONFIGURE_CFLAGS)
AC_SUBST(CONFIGURE_LDFLAGS)
AC_SUBST(CONFIGURE_CXXFLAGS)
AC_SUBST(CONFIGURE_LDXXFLAGS)

# ==============================================================================
#                                  Write output
# ==============================================================================

AC_OUTPUT

GLIBC_MEMMOVE_BUG_WARN="
***************************** WARNING *********************************

Detected glibc _FORTIFY_SOURCE/memmove bug. See:

  http://sourceware.org/ml/libc-alpha/2010-12/msg00009.html

Enabling -U_FORTIFY_SOURCE workaround. If -D_FORTIFY_SOURCE is also
present in the command line, make sure that the order of the two
options is:

  ... -D_FORTIFY_SOURCE=2 ... -U_FORTIFY_SOURCE ...

A better solution is to upgrade glibc or to report the bug to your
OS vendor.

***************************** WARNING *********************************
"

if test "$have_glibc_memmove_bug" = yes; then
  echo "$GLIBC_MEMMOVE_BUG_WARN"
fi
