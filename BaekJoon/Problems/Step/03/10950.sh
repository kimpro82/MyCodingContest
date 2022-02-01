#!/bin/bash

read t

for ((i = 0; i < t; i++))
# for i in {1..$t}          # something wrong
do
    read a b
    echo $((a + b))
done

# read