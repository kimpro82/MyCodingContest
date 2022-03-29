#!/bin/bash

read n
let "sum = 0"

for ((i = 1; i <= n; i++))
do
    let "sum += i"
done

echo $sum

# read