# data <- scan("stdin")
data <- c(1,2)

a <- data[1]
b <- data[2]

if (a > b)
{
    cat(">")
} else if (a < b)
{
    cat("<")
} else 
{
    cat("==")
}