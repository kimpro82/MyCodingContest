#!/bin/bash

read t

for ((i = 0; i < t; i++))
do
    read h w n

    let "room = (n - 1) / h + 1"
    let "floor = n % h"

    if [ $floor -eq 0 ]; then
        let "floor = h"
    fi

    if [ $room -lt 10 ]; then
        echo ${floor}0${room}
    else
        echo ${floor}${room}
    fi
done