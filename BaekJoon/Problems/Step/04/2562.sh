#!/bin/bash

# Set max
let "max = 0"

# Read data as an array
for i in {0..8}                             # Its length is fixed as 9.
do
    read temp
    let "arr[i] = temp"
done

:<<'Comment'
    It's not necessary to use an array,
    but this is the chapter to learn array
Comment

# Find the max value
for i in {0..8} 
do
    if [ ${arr[$i]} -gt $max ]; then
        let "max = arr[i]"
        let "order = i + 1"
    fi

    # test
    # echo $i ${arr[$i]} $max $order
done

# Output
echo -e "${max}\n${order}"