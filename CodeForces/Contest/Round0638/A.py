"""
Codeforces Round #638 (Div. 2)
2020-05-01(Fri)
"""


# A. Phoenix and Balance

'''
# Example Input
2
2
4

# Example Output
2
6
'''

t = int(input()) # t : the number of test cases
# t = 1

for i in range(0, t) :

    n = int(input())
    # n = int("4")
    coins = []

    for j in range(0, n) :
        coins.append(2 ** (j+1))

    if n == 2 :
        a = coins[0]
        b = coins[n-1]

    else :
        a = sum(coins[0:int(n/2-1)], coins[n-1]) # not include [n/2-1] 
        b = sum(coins[int(n/2-1):n-2]) # include [n/2-1]

    print(coins, a, b, abs(a-b))

