#!/bin/bash

read x

let "zigzag = 0"
let "sum = 0"

while [ $x -gt $sum ]
do
    ((zigzag++))
    let "sum += zigzag"

    # test
    # echo $x $zigzag $sum
done

let "numerator = 0"
let "denominator = 0"

if [[ $((zigzag % 2)) == 0 ]]; then
    let "denominator = sum - x + 1"
    let "numerator = zigzag - denominator + 1"
else
    let "numerator = sum - x + 1"
    let "denominator = zigzag - numerator + 1"
fi

echo ${numerator}/${denominator}