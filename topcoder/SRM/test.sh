#!/bin/sh
echo $1
g++-5 -O2 -Wall -std=c++11 -o $1.out $1 && ./$1.out
rm $1.out
