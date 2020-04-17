"""
Codeforces Round #635 (Div. 2)
Apr/15/2020 23:35 (UTC+9)
"""


# B. Kana and Dragon Quest game

# Example input
'''
7
100 3 4
189 3 4
64 2 3
63 2 3
30 27 7
10 9 1
69117 21 2
'''

import math

t = int(input())
# t = 1

for i in range(0, t) :

    # convert all string to integer in list
    num = input().split()
    # num = "100 3 4".split()
    num = [int(j) for j in num]

    hp = num[0] # dragon's hit point
    n = num[1] # Void Absorption
    m = num[2] # Lightning Strike

    beforedie = m * 10

    # case : don't need to cast Lightning Strike
    if hp <= beforedie : 
        print("YES")
        continue

    # cast Void Absorption
    for k in range(0, n) :
        hp = math.floor(hp/2) + 10
        # print(j, hp, hp2)

        # check if hp become enough to kill by Lightning Strike
        if hp <= beforedie : # not =< but <=
            print("YES")
            break
    else :
        print("NO")
