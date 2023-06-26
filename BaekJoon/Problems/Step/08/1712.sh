#!/bin/bash

read a b c

let "margin = c - b"

if [ $margin -gt 0 ]; then
    echo $((a / margin + 1))
else
    echo -1
fi