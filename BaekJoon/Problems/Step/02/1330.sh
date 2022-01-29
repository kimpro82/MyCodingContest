#!/bin/bash

read a b

if [ $a -gt $b ] ; then echo ">"        # gt : >, ge : >=
elif [ $a -lt $b ] ; then echo "<"      # lt : <, le : <=
else echo "=="
fi                                      # fi : (maybe) finish if …… or simply reversed "if"?

# read