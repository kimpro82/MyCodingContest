"""
April Fools Day Contest 2020
2020.04.01
"""


# H. It's showtime
   
inputnum = 123456
# inputnum = input()

mod = inputnum % 1000
n = int((inputnum - mod)/1000)
doubleFactorial = n

while n > 2 :
    if n >= mod and n % 2 == 0 : # guess something wrong
        doubleFactorial = 0
        break;
    doubleFactorial = (doubleFactorial * (n-2)) % mod
    # print(n, mod, doubleFactorial)
    n = n -2
   
print(doubleFactorial)    


# inputnum = 6100
# output = 48

# inputnum = 9900
# output = 45

# inputnum = 100002
# output = 0

# inputnum = 123456
# output = 171
