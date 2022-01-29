#!/bin/bash

read n

# Test : all cases works
# if [ $(($n % 4)) == 0 ] ; then
#     echo "success 1"
# fi
# if [ $(($n%100)) == 0 ] ; then
#     echo "success 2"
# fi
# if [ $(($n % 400)) == 0 ] ; then
#     echo "success 3"
# fi

if [ $(($n % 4)) == 0 ] ; then
    if [ $(($n%100)) != 0 ] || [ $(($n % 400)) == 0 ] ; then    # failed to write 3 conditions in a line
        echo 1
    else
        echo 0
    fi
else
    echo 0
fi

# read