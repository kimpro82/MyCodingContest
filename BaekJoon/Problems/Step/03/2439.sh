#!/bin/bash

read n

for ((i = 1; i <= n; i++))
do
    for ((j = 0; j < n; j++))
    do
        if [ $j -lt $((n - i)) ]; then
            echo -n ' '
        else
            echo -n '*'
        fi
    done

    echo ''
done

# read