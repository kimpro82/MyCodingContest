#!/bin/bash

read t

for ((i = 1; i <= t; i++))
do
    read a b
    echo "Case #$i: $a + $b = $((a + b))"
done

# read