#!/bin/bash

# Input
read a b

# Reverse digits of a and b
for i in {2..0..-1}
do
    a2+="${a:i:1}"
    b2+="${b:i:1}"
done

# Output
if [ $a2 -gt $b2 ]; then
    echo $a2
else
    echo $b2
fi