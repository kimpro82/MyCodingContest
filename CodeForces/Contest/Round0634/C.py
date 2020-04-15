"""
Codeforces Round #634 (Div. 3)
2020-04-13 23:35
https://codeforces.com/contest/1335
"""


# C. Two Teams Composing

from statistics import mode

t = int(input())
t = 4

for i in range(0, t) :
    # n = int(input())
    n = int(7)
    # a = list(map(int, input().split()))
    a = list(map(int, "4 2 4 1 4 3 4".split()))

    if n % 2 == 1 :
        maxsize = int((n-1)/2)
    else :
        maxsize = int(n/2)

    for j in range(0, maxsize) :
        # print(maxsize-j)
        teamsize = maxsize - j
        
        sameskills = a.count(mode(a)) # number of the mode
        uniqueskills = len(set(a)) # number of unique skills
        
        if sameskills >= teamsize and uniqueskills >= teamsize :
            break

    print(teamsize)
    
# doesn't work when there's no mode(a)
