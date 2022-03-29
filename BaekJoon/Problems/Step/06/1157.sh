#!/bin/bash

# Read a string and get its length
read s
let "len = ${#s}"

# Change all letters to uppercase
S=${s^^}                                # ^^ : uppercase, ,, : lowercase
# let "S = ${s^^}"                      # doesn't work

# Initialize arr
for i in {0..25}
do
    let "arr[$i] = 0"
done

# Count each alphabet
for ((i = 0; i < len; i++))
do
    c=$(printf "%d" "'${S:$i:1}'")
    let "arr[$((c-65))] += 1"

    # test : ok
    # echo $i ${S:$i:1} $(($c-65)) ${arr[$(($c-65))]}
done

# Find the max value
let "max = 0"
for i in {0..25}
do
    let "num = ${arr[$i]}"
    if [ $num -gt $max ]; then
        let "max = $num"
        let "maxIndex = $i"
    fi
done

# Determine if the max value is plural
let "isPlural = 0"
for i in {0..25}
do
    if [ ${arr[$i]} -eq $max ]; then
        ((isPlural++))
        if [ $isPlural -gt 1 ]; then
            break
        fi
    fi

    # test : ok
    # echo $i ${arr[$i]} $isPlural
done

# test : ok
# echo $maxIndex $max $isPlural

# Output
if [ $isPlural -gt 1 ]; then
    echo '?'
else
    printf $(printf '\%o' "$(($maxIndex + 65))")    # crazy; bash requires only \octal(\%o), not \decimal(\%d)
fi


# 시간 초과 : The maximum length of the word is 1,000,000