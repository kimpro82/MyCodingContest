#!/bin/bash

read a b v

let "day = (v - b) / (a - b) - 1"
let "location = (a - b) * day"

while true
do
    ((day++))
    let "location += a"

    # test
    # echo $day $location $((location - v))

    if [ $location -ge $v ]; then
        break
    else
        let "location -= b"
    fi
done

echo $day