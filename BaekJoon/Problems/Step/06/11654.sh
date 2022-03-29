#!/bin/bash

read char                   # ex) a

# printf "%d\n" $char       # printf: a: invalid number
# printf "%d\n" "$char"     # printf: a: invalid number; it doesn't matter if use "" or not
# printf "%d\n" '$char'     # printf: $char: invalid number; regard $char itself as a string

printf "%d\n" "'$char'"     # 97; regard a as a string
# printf "%d\n" "'$char"    # 97; the closing quotes(') may be omitted