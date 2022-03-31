#!/bin/bash

read n x
read list

for num in $list
do
    if [ $num -lt $x ]; then
        echo -n "$num "
    fi
done

echo ' '

# read