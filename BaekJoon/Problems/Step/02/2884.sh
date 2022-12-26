#!/bin/bash

read h m

if [ $m -lt 45 ] ; then
    let "h -= 1"
    let "m += 60"
fi

if [ $h -lt 0 ] ; then
    let "h += 24"
fi

echo $h $(($m - 45))