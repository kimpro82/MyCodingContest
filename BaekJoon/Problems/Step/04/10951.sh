#!/bin/bash


while true
do
    read a b

    if [ $a -ne $? ] ; then     # it works but return this message > [: -ne: unary operator expected
        let "sum = a + b"
        echo $sum
    else
        break
    fi
done