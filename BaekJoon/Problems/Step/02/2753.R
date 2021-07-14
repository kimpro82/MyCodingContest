n <- scan("stdin")
# n <- 2000                                             # test

if (n %% 4 == 0 && (n %% 100 != 0 || n %% 400 == 0))    # not %
{
    cat("1\n")
} else
{
    cat("0\n")
}