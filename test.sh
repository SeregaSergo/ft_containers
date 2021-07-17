#!/bin/bash

echo "Building project\n"
make
./test_my
./test_std
diff ./tests/output_my.txt ./tests/output_std.txt
diff -y ./tests/output_my.txt ./tests/output_std.txt