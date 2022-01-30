#!/bin/bash

# test
# echo [ 3 -gt 2 ]                      # doesn't work
# echo [ 3 -lt 2 ]                      # doesn't work
# echo $((3 > 2))                       # 1
# echo $((3 < 2))                       # 0

read n

# if $(($n >= 90)) ; then echo 'A'      # doesn't work
if [ $n -ge 90 ] ; then echo 'A'
elif [ $n -ge 80 ] ; then echo 'B'
elif [ $n -ge 70 ] ; then echo 'C'
elif [ $n -ge 60 ] ; then echo 'D'
else echo 'F'
fi

# read