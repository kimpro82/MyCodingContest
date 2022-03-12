#!/bin/bash

read a b
let "aLen = ${#a}"
let "bLen = ${#b}"

if [ $aLen -ge $bLen ]; then
    let "maxSize = aLen"
    let "minSize = bLen"
else
    let "maxSize = bLen"
    let "minSize = aLen"
fi

let "buffer = 0"

# test
# echo $maxSize $minSize

# Sum each digit (1) : 0 ~ minSize - 1
for ((i = 0; i < minSize; i++))
do
    let "buffer += ${a:$((aLen-1-i)):1} + ${b:$((bLen-1-i)):1}"     # it works!
    if [ $buffer -lt 10 ]; then
        let "sum[i] = buffer"
        let "buffer = 0"
    else
        let "sum[i] = buffer - 10"
        let "buffer = 1"
    fi

    # test
    # echo $i $buffer ${sum[$i]}
done

# Sum each digit (2) : minSize ~ maxSize - 1
for ((j = minSize; j < maxSize; j++))
do
    if [ $aLen -gt $bLen ]; then
        let "buffer += ${a:$((aLen-1-j)):1}"
    else
        let "buffer += ${b:$((bLen-1-j)):1}"
    fi

    if [ $buffer -lt 10 ]; then
        let "sum[j] = buffer"
        let "buffer = 0"
    else
        let "sum[j] = buffer - 10"
        let "buffer = 1"
    fi

    # test
    # echo $i $buffer ${sum[$i]}
done

# Sum each digit (3) : maxSize
if [ $buffer -eq 1 ]; then
    let "sum[maxSize] = 1"
    let "maxSize++"
fi
# test
# echo $((maxSize-1)) $buffer ${sum[$((maxSize-1))]}

# Output
for ((k = 0; k < maxSize; k++))
do
    echo -n "${sum[$((maxSize-1-k))]}"                              # don't confuse the indexing syntax between array and string!
done
echo


# Timeout