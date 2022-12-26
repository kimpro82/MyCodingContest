#!/bin/bash

read n
read num

let "sum = 0"

for ((i = 0; i < n; i++))
do
    let "sum += ${num:i:1}"

    # test : ok
    # echo ${num:i:1}
done

echo $sum