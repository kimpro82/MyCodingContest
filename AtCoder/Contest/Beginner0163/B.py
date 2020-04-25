"""
AtCoder Beginner Contest 163
2020-04-19(Sun)
"""


# B - Homework
'''
# Sample Input 1
41 2
5 6
'''

data = list(map(int, input().split()))
# data = list(map(int, "41 2 5 6".split()))

N = data[0] # days of summer vacation
M = data[1] # summer assignments

A = 0 # days to do the i-th assignment.

for i in range(2, M+2) :
    # print(data[i])
    A += data[i]

if A <= N :
    print(N-A)
else :
    print(-1)


# B - Homework - Second Trial
    
data = list(map(int, input().split()))
# data = list(map(int, "41 2".split()))

N = data[0] # days of summer vacation
M = data[1] # summer assignments

A = 0 # days to do the i-th assignment.

assignments = list(map(int, input().split()))
# assignments = list(map(int, "5 6".split()))

if sum(assignments) <= N :
    print(N-sum(assignments))
else :
    print(-1)
