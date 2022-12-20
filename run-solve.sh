#!/bin/bash

FT=$(echo $1 | cut -d. -f2)
if test "$FT" ==  "cpp"; then
    clang++ -Wall -std=c++17 $1;
elif test "$FT" == "c"; then
    clang $1;
fi

if test $? -eq 0; then
    time ./a.out
fi
