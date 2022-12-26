read a b

# printf "%.9f\n", $a / $b                      # doesn't work
# echo $a $b | awk '{printf "%.9f\n", $1 / $2}' # not adopted at BOJ
# printf "%.9f\n" $(((a * 10**9 / b) / 10**9))  # 1 / 3 = 0.000000000
# printf "%.9f\n" $((a * e+9 / b))e-9           # e-9 works but e+9 doesn't work
printf "%.9f\n" $((a * 10**9 / b))e-9

# read