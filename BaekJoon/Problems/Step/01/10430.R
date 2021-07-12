num <- scan("stdin")                # recieve num[1], num[2], …… as numeric
# num <- c(5, 8, 4)                 # test

a <- num[1]
b <- num[2]
c <- num[3]

cat((a + b) %% c, "\n")
cat(((a %% c) + (b %% c)) %% c, "\n")
cat((a * b) %% c, "\n")
cat(((a %% c) * (b %% c)) %% c, "\n")