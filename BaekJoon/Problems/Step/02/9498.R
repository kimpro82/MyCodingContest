score <- scan("stdin")
# score <- 100          # test

if (score >= 90)
{
    cat("A")
} else if (score >= 80)
{
    cat("B")
} else if (score >= 70)
{
    cat("C")
} else if (score >= 60)
{
    cat("D")
} else 
{
    cat("F")
}