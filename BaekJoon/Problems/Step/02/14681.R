data <- scan("stdin")
# data <- c(12, 5)          # test

x <- data[1]
y <- data[2]

if (x > 0 && y > 0)
{
    cat("1\n")
} else if (x < 0 && y > 0)
{
    cat("2\n")
} else if (x < 0 && y < 0)
{
    cat("3\n")
} else 
{
    cat("4\n")
}