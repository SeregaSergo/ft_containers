#!/bin/bash

[[ ! -d results ]] && mkdir results

make

if [[ ! -f ./tests/program/test_my ]] || [[ ! -f ./tests/program/test_std ]]
then
    echo "Programs 'test_my' or 'test_std' are not found"
    exit
fi

./tests/program/test_my
./tests/program/test_std

# check number of arguments 
if [ $# -ne 1 ]; 
    then echo "please, test one container at a time"
         exit
fi

# deleting "-"
arg=$1
if [ ${arg:0:1} = '-' ]; then
    arg=${arg:1}
fi

# check if argument is correct 
declare -a arr=("vector" "map" "stack" "set")
declare -i correct=0

for i in "${arr[@]}"
do
    if [ $arg = $i ]; then
        correct=1;
        break;
    fi
done

if [ $correct = 0 ]
    then echo "Incorrect argument. Choose one: ['vector', 'map', 'stack', 'set']"
fi

diff -y --width=160 ./results/"$arg"_my.txt ./results/"$arg"_std.txt
diff -d ./results/"$arg"_my.txt ./results/"$arg"_std.txt