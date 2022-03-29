#!/bin/bash

read n

for i in {1..9}
do
    echo $n "*" $i "=" $((n * i))
done

# read