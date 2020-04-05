"""
Qualification Round 2020 - Code Jam 2020
2020.4.4 SAT
"""

# Vestigium (7pts)



# get input data (for test)

# testcases = input()
import numpy as np

input1 = 3 # testcases
input2 = [2, 2, 3] # each case's size
input3 = [
            [[1, 2], [3, 4]],
            [[1, 1], [2, 2]],
            [[1, 1, 3], [4, 5, 3], [7, 7, 3]]
            ]

testcases = input1
matrix = []

for m in range(0, testcases) :
    N = input2[m]
    matrix_m = []

    for n in range(0, N) :
        matrix_m.append(input3[m][n])
    matrix.append(np.array(matrix_m))
    print(matrix[m])

matrix = np.array(matrix)
print(matrix)


# output

k = []
r = []
c = []

for o in range(0, testcases):
    k.append(np.trace(matrix[o]))

    r_cnt = 0
    for p in range(0, len(matrix[o])):
        # print(o, p, matrix[o][p])
        if len(matrix[o][p]) != len(np.unique(matrix[o][p])) :
            r_cnt += 1
    # print(o, p, r_cnt)
    r.append(r_cnt)
    
    c_cnt = 0
    for q in range(0, len(matrix[o])):
        # print(o, p, matrix[o][:, q])
        if len(matrix[o][:, q]) != len(np.unique(matrix[o][:, q])) :
            c_cnt += 1
    # print(o, q, c_cnt)
    c.append(c_cnt)


for s in range(0, testcases) :
    print("Case #" + str(s+1) + ": "
          + str(k[s]) + " " + str(r[s]) + " " + str(c[s]))



# submit

import numpy as np

# input
testcases = input()
matrix = []

for m in range(0, testcases) :
    N = input()
    matrix_m = []
    for n in range(0, N):
        matrix_m.append(input())
    matrix.append(np.array(matrix_m))
    print(matrix[m])

matrix = np.array(matrix)

k = []
r = []
c = []

# calculate k, r, c
for o in range(0, testcases):
    k.append(np.trace(matrix[o]))

    r_cnt = 0
    for p in range(0, len(matrix[o])):
        # print(o, p, matrix[o][p])
        if len(matrix[o][p]) != len(np.unique(matrix[o][p])) :
            r_cnt += 1
    # print(o, p, r_cnt)
    r.append(r_cnt)
    
    c_cnt = 0
    for q in range(0, len(matrix[o])):
        # print(o, p, matrix[o][:, q])
        if len(matrix[o][:, q]) != len(np.unique(matrix[o][:, q])) :
            c_cnt += 1
    # print(o, q, c_cnt)
    c.append(c_cnt)

# final output
for s in range(0, testcases) :
    print("Case #{}: {} {} {}".format(s+1, k[s], r[s], c[s]))



# second trial (incomplete)
   
t = int(input()) # read a line with a single integer
for i in range(1, t + 1):
    for s in input().split(" ") :
        print(t, i, s)

import numpy as np

testcases = int(input())
matrix = []

for m in range(0, testcases) :
    N = input()
    matrix_m = []
    for n in range(0, N):
        matrix_m.append(list(input().split(" ")))
    matrix.append(matrix_m)
    print(matrix[m])

matrix = np.array(matrix)



# practice
len(testcases)
list(range(1, testcases+1))

matrix
matrix[0]
matrix[0][0]
matrix[0][0][0]
matrix[2][:, 2]

case = int(input()) # number of test cases
t = case
data = []

while t < 0 :
    data.append(input())
    if len(data) == 1 :
        t -= 1

print(data)
