#!/bin/bash

read n

let "count = 0"
for ((i = 0; i < n; i++))
do
    # Input
    read s
    let "len = ${#s}"

    # Initialize arr for counting each alphabet
    for j in {0..25}
    do
        let "alphabet[$j] = 0"
    done

    # Find if there are seperated same idxs
    let "isSeperated = 0"
    for ((k = 0; k < len; k++))
    do
        idx=$(($(printf "%d" "'${s:k:1}'")-97))

        if [[ ${alphabet[$idx]} == 0 ]]; then
            ((alphabet[idx]++))
        elif [[ ${s:k:1} != ${s:$((k-1)):1} ]]; then    # not $s[$k] !!!
            ((isSeperated++))
            break
        fi

        # test : ok
        # echo $i $s $k ${s:k:1} $idx ${alphabet[$idx]} $isSeperated
    done

    # Count
    if [[ $isSeperated == 0 ]]; then
        ((count++))
    fi

    # test : ok
    # echo "isSeperated : ${isSeperated}, count : ${count}"
done

# Output
echo $count


# 런타임 에러?