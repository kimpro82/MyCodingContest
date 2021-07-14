year <- scan("stdin")
# year <- 2000          # test

if (year %% 4 == 0 && (year %% 100 != 0 || year %% 400 == 0))   # not %
{
    cat(1)
} else
{
    cat(0)
}