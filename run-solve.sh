#!/bin/bash

FT=$(echo $1 | cut -d. -f2)
if test "$FT" ==  "cpp"; then
    /opt/homebrew/bin/g++-12 -std=c++20 $1;
elif test "$FT" == "c"; then
    clang $1;
elif test "$FT" == "rs"; then
    rustc $1 -o a.out;
fi

if test $? -eq 0; then
    time ./a.out
fi
