#!/bin/sh
echo $1
g++ -o $1.out $1 && ./$1.out
rm $1.out