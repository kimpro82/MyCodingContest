#!/bin/bash

read t

for ((i = 0; i < t; i++))
do
    # Read each data
    read r s
    let "len = ${#s}"

    # Repeat each char r times
    for ((j = 0; j < len; j++))
    do
        for ((k = 0; k < r; k++))
        do
            echo -n "${s:j:1}"
        done
    done
    echo
done