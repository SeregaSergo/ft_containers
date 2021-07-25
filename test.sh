#!/bin/bash

make
./test_my
./test_std
diff -d ./output_my.txt ./output_std.txt
diff -y ./output_my.txt ./output_std.txt
