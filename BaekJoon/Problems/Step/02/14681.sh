#!/bin/bash

read x
read y

if [ $x -gt 0 ] && [ $y -gt 0 ] ; then
    echo 1
elif [ $x -lt 0 ] && [ $y -gt 0 ] ; then
    echo 2
elif [ $x -lt 0 ] && [ $y -lt 0 ] ; then
    echo 3
else
    echo 4
fi