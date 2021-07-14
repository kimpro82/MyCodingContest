data <- scan("stdin")
# data <- c(10, 10)          # test

a <- data[1]
b <- data[2]

if (b < 45)
{
    a = a - 1
    b = b + 60
}
if (a < 0)
{
    a = a + 24
}

cat(a, b - 45, "\n")