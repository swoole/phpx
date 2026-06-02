#!/bin/sh

cd ../tests && ./gettests.sh "$1" || exit 1
cd ../tests++ && cp -Rp ../tests/testdata . || exit 1

