#!/bin/bash

# Input string
read s
let "len = ${#s}"

# Initialize arr
for i in {0..25}
do
    let "arr[$i] = -1"
    # echo ${arr[$i]}                       # test : ok
done

# Count each alphabet
for ((i = 0; i < len; i++))
do
    c=$(printf "%d" "'${s:i:1}'")           # I don't want to lose my precious 'let' but ……
    if [ ${arr[$((c-97))]} -lt 0 ]; then
        let "arr[$((c-97))] = $i"
    fi
done

# Output
for i in {0..25}
do
    echo -n "${arr[$i]} "                   # -n : without line replacement
done
echo