#!/bin/bash

mkdir results
make
./tests/program/test_my
./tests/program/test_std
diff -d ./results/output_my.txt ./results/output_std.txt
diff -y --width=160 ./results/output_my.txt ./results/output_std.txt
