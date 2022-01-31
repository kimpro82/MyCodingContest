#!/bin/bash

read t

for ((i = 0; i < t; i++))
do
    read a b
    echo $((a + b))
done

# read

# 시간 초과