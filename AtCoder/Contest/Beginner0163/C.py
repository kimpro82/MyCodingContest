"""
AtCoder Beginner Contest 163
2020-04-19(Sun)
"""


# C - management

# N = int(input())
N = 7

# A = list(map(int, input().split()))
A = list(map(int, "1 2 3 4 5 6".split()))

sum = 0
for i in range(0, N) :
    print(i, A.count(i+1))
    # print(A.count(i+1))
