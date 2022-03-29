#!/bin/bash

# Input data
read a
read b
read c

# Get the product and its length as a string
let "prod = a * b * c"
let "len = ${#prod}"
# echo $prod $len                               # test

# Initialize arr
for i in {0..9}
do
    let "arr[$i] = 0"
done

:<<"Comment"
    It's not neccesary to initialize an array basically in Bash,
    but empty indices should have their value '0' for solving this problem.
Comment

# Operation to count each digit
for ((i = 0; i < len; i++))
do
    let "arr[${prod:i:1}] += 1"

    # test
    # echo $i ${prod:i:1} ${arr[${prod:i:1}]}
done

# Output
for i in {0..9}
do
    echo ${arr[$i]}
done