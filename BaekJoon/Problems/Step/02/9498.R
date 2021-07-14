a <- scan("stdin")
# a <- 100          # test

if (a >= 90)
{
    cat("A\n")
} else if (a >= 80)
{
    cat("B\n")
} else if (a >= 70)
{
    cat("C\n")
} else if (a >= 60)
{
    cat("D\n")
} else 
{
    cat("F\n")
}