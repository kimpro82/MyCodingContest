#!/bin/bash

# t test cases
read t

# Initialize file.txt that has 0 bytes
cat /dev/null > file.txt                # /dev/null : null device

# Operation
for ((i = 0; i < t; i++))
do
    read a b
    echo $((a + b)) >> file.txt
done

# Standard output through a file
awk '{ print }' ./file.txt

# read

# 런타임 에러