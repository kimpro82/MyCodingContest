#!/bin/bash

read n

let "move = 0"

while [ $n -gt 1 ]
do
    ((move++))
    let "n -= 6 * move"

    # test
    # echo $n $move
done

echo $((move + 1))