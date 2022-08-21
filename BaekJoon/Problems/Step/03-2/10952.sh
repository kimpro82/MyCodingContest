#!/bin/bash


while true
do
    read a b
    let "sum = a + b"

    if [ $sum -gt 0 ] ; then
        echo $sum
    else
        break
    fi
done