"""
AtCoder Beginner Contest 164
2020-04-26(Sun)
https://atcoder.jp/contests/abc164/
"""


# B - Battle

'''
# Sample Input
10 9 10 10
46 4 40 5
'''

# A, B : the health and strength of Takahashi's monster
# C, D : those of Aoki's monster

A, B, C, D = list(map(int, input().split()))
# A, B, C, D = list(map(int, "46 4 40 5".split()))

while True :

    # Takahashi's trun
    C -= B
    if C <= 0 :
        print("Yes")
        break

    # Aoki's trun
    A -= D
    if A <= 0 :
        print("No")
        break
