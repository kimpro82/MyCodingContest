#!/bin/bash

# ulimit -q 64
# -d : The maximum size of a process’s data segment (kbytes)
# -p : The pipe buffer size
# Error message > ulimit: pipe size: cannot modify limit: Invalid argument
# -q : The maximum number of bytes in POSIX message queues
# Error message > -q: invalid option

read n

# Set min, max
let "min = 10 ** 6"
let "max = -(10 ** 6)"

# Read data as an array
read -a arr

# Find the min and max values
for i in ${arr[@]}
do
    if [ $i -lt $min ]; then
        let "min = i"
    fi

    if [ $i -gt $max ]; then
        let "max = i"
    fi
done

# Output
echo $min $max


# 메모리 초과???