#!/bin/bash

read n

# Set min, max
let "min = 10 ** 6"
let "max = 0"

# Read data as an array
read -a arr

# Find the min and max values
for i in ${arr[@]}
do
    if [ $i -lt $min ]; then
        let "min = i"
    fi

    if [ $i -gt $max ]; then
        let "max = i"
    fi
done

# Output
echo $min $max


# 메모리 초과???