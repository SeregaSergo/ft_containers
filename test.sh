#!/bin/bash

make
./test_my
./test_std
diff -d ./tests/output_my.txt ./tests/output_std.txt
diff -y ./tests/output_my.txt ./tests/output_std.txt
