#!/bin/bash

read c

# Operation to grade and output
for ((i = 0; i < c; i++))
do
    # Read an array
    read -a arr

    let "len = arr[0]"
    let "sum = 0"

    # Get the array's sum and average
    for ((j = 1; j < len + 1; j++))
    do
        let "sum += ${arr[j]}"
    done
    let "average = sum * 10 / len"                      # don't forget sum * 10

    # test
    # echo $i $sum $len $average

    # Count freshmen over the average score
    let "count = 0"
    for ((j = 1; j < len + 1; j++))
    do
        let "score = ${arr[j]} * 10"
        if [ $score -gt $average ]; then
            let "count += 1"
        fi
    done

    # Output
    printf "%.3f%%\n" $((count * 10 ** 8 / len))e-6
    # * 10 ** 6 & e-4 : fail (maybe concerned with rounding ……)
done