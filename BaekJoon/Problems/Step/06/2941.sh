#!/bin/bash

# Input
read s
let "len = ${#s}"

# Make an array of specific Croatian alphabets
specific1=("c=" "c-" "d-" "lj" "nj" "s=" "z=")
specific2="dz="

# Count if the string includes specific letters
let "count = 0"
# 1) two letters : specific[0, 6]
for ((i = 0; i < ((len - 1)); i++))
do
    for j in {0..6}
    do
        if [[ ${specific1[j]} =~ ${s:i:2} ]]; then
            ((count++))
        fi

        # test : ok
        # echo $i ${s:i:2} ${specific1[j]} $count
    done
done
# 2) three letters : specific[7]
for ((i = 0; i < ((len - 2)); i++))
do
    if [[ $specific2 == ${s:i:3} ]]; then
        ((count++))                                # don't add 2; to avoid double count 'z=' and 'dz='
    fi

    # test : ok
    # echo $i ${s:i:3} $specific2 $count
done

# Output
echo $((len - count))