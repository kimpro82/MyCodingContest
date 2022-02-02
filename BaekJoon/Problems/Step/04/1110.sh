#!/bin/bash


read n

let "ab = n"
let "t = 0"

while true
do
    let "a = ab / 10"
    let "b = ab % 10"
    let "ab = a + b"

    if [ $ab -lt 10 ]; then
        let "ab += b * 10"
    else
        let "ab = b * 10 + ab % 10"
    fi

    let "t += 1"

    # test
    # echo "t: $t, a: $a, b: $b, ab: $ab"

    if [ $ab -eq $n ]; then
        break
    fi
done

echo $t