read a
read b
# guaranteed that 100 <= a, b  <= 999

let "sum = 0"
for i in {2..0..-1}
do
    let "prod = $a * ${b:i:1}"          # ${b : i : 1} doesn't work
    echo $prod
    let "sum += $prod * (10 ** (2 - $i))"
done

echo $sum

# read