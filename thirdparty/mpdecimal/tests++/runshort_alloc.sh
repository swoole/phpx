#!/bin/sh

SYSTEM=`uname -s`
case $SYSTEM in
    darwin*|Darwin*)
        # malloc() on OS X does not conform to the C standard.
        export MallocLogFile=/dev/null
        export MallocDebugReport=crash
        ;;
    *)
        ;;
esac


# Download or copy the official test cases (text files).
./gettests.sh || exit 1

if [ ! -f ./runtest -a ! -f ./runtest_shared ]; then
    printf "\nERROR: ./runtest and ./runtest_shared not found\n\n\n"; exit 1;
fi

if [ -f ./runtest ]; then
    printf "\n# ========================================================================\n"
    printf "#                        libmpdec++: static library\n"
    printf "# ========================================================================\n\n"

    printf "Running official tests with allocation failures ...\n\n"
    ./runtest official.topTest --thread --alloc || { printf "\nFAIL\n\n\n"; exit 1; }


    printf "Running additional tests with allocation failures ...\n\n"
    ./runtest additional.topTest --thread --alloc || { printf "\nFAIL\n\n\n"; exit 1; }

    printf "Running API tests (single thread) ... \n\n"
    ./apitest || { printf "\nFAIL\n\n\n"; exit 1; }

    printf "Running API tests (threaded) ... \n\n"
    ./apitest --thread || { printf "\nFAIL\n\n\n"; exit 1; }
fi

if [ -f ./runtest_shared ]; then
    printf "\n# ========================================================================\n"
    printf "#                        libmpdec++: shared library\n"
    printf "# ========================================================================\n\n"

    PORTABLE_PWD=`pwd`
    LD_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD/../libmpdec++:$LD_LIBRARY_PATH"
    DYLD_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD/../libmpdec++:$DYLD_LIBRARY_PATH"
    LD_64_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD/../libmpdec++:$LD_64_LIBRARY_PATH"
    LD_32_LIBRARY_PATH="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD/../libmpdec++:$LD_32_LIBRARY_PATH"
    LD_LIBRARY_PATH_64="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD/../libmpdec++:$LD_LIBRARY_PATH_64"
    LD_LIBRARY_PATH_32="$PORTABLE_PWD/../libmpdec:$PORTABLE_PWD/../libmpdec++:$LD_LIBRARY_PATH_32"
    PATH="$LD_LIBRARY_PATH:$PATH"
    export LD_LIBRARY_PATH
    export DYLD_LIBRARY_PATH
    export LD_64_LIBRARY_PATH
    export LD_32_LIBRARY_PATH
    export LD_LIBRARY_PATH_64
    export LD_LIBRARY_PATH_32

    printf "Running official tests with allocation failures ...\n\n"
    ./runtest_shared official.topTest --thread --alloc || { printf "\nFAIL\n\n\n"; exit 1; }

    printf "Running additional tests with allocation failures ...\n\n"
    ./runtest_shared additional.topTest --thread --alloc || { printf "\nFAIL\n\n\n"; exit 1; }

    printf "Running API tests (single thread) ... \n\n"
    ./apitest_shared || { printf "\nFAIL\n\n\n"; exit 1; }

    printf "Running API tests (threaded) ... \n\n"
    ./apitest_shared --thread || { printf "\nFAIL\n\n\n"; exit 1; }
fi
