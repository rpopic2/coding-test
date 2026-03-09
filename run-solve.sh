#!/bin/bash

FT=$(echo $1 | cut -d. -f2)
if test "$FT" ==  "cpp"; then
    clang++ -std=c++20 $1;
elif test "$FT" == "c"; then
    clang $1;
elif test "$FT" == "rs"; then
    rustc $1 -o a.out;
fi
if test $? -eq 0; then
    echo "compilation succcessful"
    time ./a.out
fi
