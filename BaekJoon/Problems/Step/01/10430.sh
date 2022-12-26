read A B C

echo $(((A + B) % C))
echo $((((A % C) + (B % C)) % C))
echo $(((A * B) % C))
echo $((((A % C) * (B % C)) % C))

# read