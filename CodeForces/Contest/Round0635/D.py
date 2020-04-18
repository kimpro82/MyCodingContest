"""
Codeforces Round #635 (Div. 2)
Apr/15/2020 23:35 (UTC+9)
"""


# D. Xenia and Colorful Gems

# Example input
'''
5
2 2 3
7 8
6 3
3 1 4
1 1 1
1
1
1000000000
2 2 2
1 2
5 4
6 7
2 2 2
1 2
3 4
6 7
3 4 1
3 2 1
7 3 3 4
6
'''


# t = int(input())
t = 1

for i in range(0, t) :

    # num = input().split() # don't need
    num = "2 2 3".split()

#    r = list(map(int, input().split()))
#    g = list(map(int, input().split()))
#    b = list(map(int, input().split()))

    r = list(map(int, "7 8".split()))
    g = list(map(int, "6 3".split()))
    b = list(map(int, "3 1 4".split()))

    balance = []
    
    for k in range(0,len(r)) :
        for l in range(0,len(g)) :
            for m in range(0,len(b)) :

                if k == 0 and l == 0 and m == 0 :                 
                    balance = (r[k] - g[l])**2 + (g[l]-b[m])**2 + (b[m]-r[k])**2
                else :
                    balance = min(balance, (r[k] - g[l])**2 + (g[l]-b[m])**2 + (b[m]-r[k])**2)

    print(balance)
