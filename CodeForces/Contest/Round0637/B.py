"""
Codeforces Round #637 (Div. 2)
2020-04-23(Thu)
"""


# B. Nastya and Door
        
'''
# Example Input
5
8 6
1 2 4 1 2 4 1 2
5 3
3 2 3 2 1
10 4
4 3 4 3 2 3 2 1 0 1
15 7
3 7 4 8 2 3 4 5 21 2 3 4 2 1 3
7 5
1 2 3 4 5 6 1
'''

t = int(input()) # t : the number of test cases
# t = 1

for i in range(0, t) :

    # n : the number of mountains
    # k : the length of the door
    # a : the heights of mountains
    
    n, k = list(map(int, input().split()))
    # n, k = list(map(int, "10 4".split()))
    a = list(map(int, input().split()))
    # a = list(map(int, "4 3 4 3 2 3 2 1 0 1".split()))
    
    p = [] # p : peak
    for j in range(0, n-k+1) : # shift j times
        p.append(0)
        for m in range(1, k-1) :
            # print(j+m-1, j+m, j+m+1)
            if a[j+m] > a[j+m-1] and a[j+m] > a[j+m+1] :
                p[j] += 1


    split = max(p) + 1
    leftindex = p.index(max(p)) + 1
    
    print(split, leftindex) # not a[leftindex]
