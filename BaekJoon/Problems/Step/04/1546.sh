#!/bin/bash

# Input data
read n
read -a arr

# Find the max score
let "max = 0"
for i in ${arr[@]}
do
    if [ $i -gt $max ]; then
        let "max = i"
    fi
done
# echo $max                                     # test

# Operation to fake scores
let "sum = 0"
for ((i = 0; i < n; i++))
do
    let "sum += (arr[i] * 100 * 1000 / max)"    # don't forget "* 1000"
done
# echo $sum                                     # test

# Output
let "average = sum / n"
printf "%.2f\n" $((average))e-3                 # MAGIC!!