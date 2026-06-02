#!/bin/sh

PORTABLE_PWD=`pwd`

LD_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD:$LD_LIBRARY_PATH"
DYLD_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD:$DYLD_LIBRARY_PATH"
LD_64_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD:$LD_64_LIBRARY_PATH"
LD_32_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD:$LD_32_LIBRARY_PATH"
LD_LIBRARY_PATH_64="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD:$LD_LIBRARY_PATH_64"
LD_LIBRARY_PATH_32="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD:$LD_LIBRARY_PATH_32"
PATH="$LD_LIBRARY_PATH:$PATH"
export LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH
export LD_64_LIBRARY_PATH
export LD_32_LIBRARY_PATH
export LD_LIBRARY_PATH_64
export LD_LIBRARY_PATH_32

MPD_PREC="$1"
MPD_DPREC=`expr "$MPD_PREC" \* 2`

if [ ! -f ./bench_full -a ! -f ./bench_shared ]; then
    printf "\n./train.sh: error: no training files found\n\n"
    exit 1
fi

if [ -f ./bench_full ]; then
    ./bench_full "$MPD_PREC" 1000 > /dev/null 2>&1
    ./bench_full "$MPD_DPREC" 1000 > /dev/null 2>&1
fi

if [ -f ./bench_shared ]; then
    ./bench_shared "$MPD_PREC" 1000000 > /dev/null 2>&1
    ./bench_shared "$MPD_DPREC" 1000000 > /dev/null 2>&1
fi
