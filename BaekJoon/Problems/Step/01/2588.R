num <- scan("stdin")                            # recieve num[1], num[2], …… as numeric
# num <- c(472, 385)                            # test

a <- num[1]
b <- num[2]

sum = 0
for (i in 1:3)
{
    # cat(floor((b %% 10^i) / 10^(i-1)), "\n")  # test
    ans = a * floor((b %% 10^i) / 10^(i-1))
    cat(ans, "\n")
    sum = sum + ans * 10^(i - 1) 
}

cat(sum, "\n")