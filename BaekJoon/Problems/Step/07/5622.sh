#!/bin/bash

# Input
read s
let "len = ${#s}"

# Count time to turn the dial
let "sum = 0"
for ((i = 0; i < len; i++))
do
    letter=$(printf "%d" "'${s:i:1}'")
    if [ $letter -le $(printf "%d" "'R'") ]; then
        let "sum += $(($(($letter - 65)) / 3 + 2 + 1))"
    elif [ $letter -le $(printf "%d" "'X'") ]; then
        let "sum += $(($(($letter - 65 - 1)) / 3 + 2 + 1))"
    else
        let "sum += $(($(($letter - 65 - 2)) / 3 + 2 + 1))"
    fi
done

echo $sum