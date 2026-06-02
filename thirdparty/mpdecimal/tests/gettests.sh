#!/bin/sh

if [ ! -d testdata ]; then
    mkdir testdata
fi

if [ x"$1" != x"--local" -a ! -f testdata/add.decTest ]; then
    # The official tests are freely downloadable, but copyrighted.
    WGET=`which wget`
    if [ ! -f "$WGET" ]; then
        printf "\n*** gettests.sh: error: could not find wget. In order to run the tests, \n"
        printf "    download http://speleotrove.com/decimal/dectest.zip and extract the \n"
        printf "    archive into tests/testdata.\n\n"
        exit 1
    fi
    printf "\nGetting official tests ... \n\n"
    $WGET -nv http://speleotrove.com/decimal/dectest.zip 2>&1 &&
    cd testdata &&
    unzip -qq ../dectest.zip &&
    cd ../
fi

if [ ! -f testdata/baseconv.decTest ]; then
    cp testdata_dist/* testdata
fi
