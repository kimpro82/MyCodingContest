#!/bin/bash

read n

let "bag3 = 0"
let "rest = 1"

for ((i = 0; i <= $((n / 3)); i++))
do
    # if [[ $(($((n - i * 3)) % 5)) == 0 ]]; then       # worse readability
    let "criteria = (n - i * 3) % 5"
    if [ $criteria -eq 0 ]; then
        let "bag3 = i"
        let "rest = 0"
        break
    fi

    # test
    # echo ${bag3} $((bag3 * 3)) $((n - bag3 * 3))
done



if [ $rest -eq 0 ]; then
    echo $((bag3 + (n - bag3 * 3) /  5))
else
    echo -1
fi