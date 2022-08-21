#!/bin/bash

read t

# Operation to grade and output
for ((i = 0; i < t; i++))
do
    read ox

    let "len = ${#ox}"
    let "score = 0"
    let "combo = 0"

    for ((j = 0; j < len; j++))
    do
        if [ "${ox:j:1}" = "O" ]; then
            let "combo += 1"
            let "score += combo"
        else
            let "combo = 0"
        fi

        # test
        # echo $i $j ${ox:j:1} $combo $score
    done

    echo $score
done