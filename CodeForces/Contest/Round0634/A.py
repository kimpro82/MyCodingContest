"""
Codeforces Round #634 (Div. 3)
2020-04-13 23:35
https://codeforces.com/contest/1335
"""

# A. Candies and Two Sisters

inputdata = input().split()
# inputdata = "6 7 1 2 3 200000000 763243547".split()
# print(inputdata)

t = int(inputdata[0])
# print(n)

for i in range(1, t+1) :

    num = int(inputdata[i])
    # num == odd number
    if num % 2 == 1 :
        print(int((num-1)/2))
    
    # num == even number
    else :
        print(int((num-2)/2))


# A. Candies and Two Sisters - Second Trial

t = int(input())

for i in range(0, t) :

    num = int(input())

    # num == odd number
    if num % 2 == 1 :
        print(int((num-1)/2))

    # num == even number
    else :
        print(int((num-2)/2))
