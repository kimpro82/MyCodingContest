#!/bin/bash

# Input data
for i in {0..9}         # the size 10 is fixed
do
    read n
    let "modulo = n % 42"
    let "arr[$modulo]++"
done

:<<"Comment"
    The array in bash doesn't need to have strictly continuous indices.
    So we can use array like <set> by this feature 
Comment

# Output
echo ${#arr[@]}