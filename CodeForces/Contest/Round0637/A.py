"""
Codeforces Round #637 (Div. 2)
2020-04-23(Thu)
"""


# A. Nastya and Rice

'''
# Example Input
5
7 20 3 101 18
11 11 10 234 2
8 9 7 250 122
19 41 21 321 10
3 10 8 6 1
'''

t = int(input()) # t : the number of test cases
# t = 1

for i in range(0, t) :
    n, a, b, c, d = list(map(int, input().split()))
    # n, a, b, c, d = list(map(int, "7 20 3 101 18".split()))

    if n*(a-b) > c+d :
        print("No")
    elif n*(a+b) < c-d :
        print("No")
    else :
        print("YES")
