## Google Code Jam 2020 - Qualification Round
2020.4.4 SAT  
https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27


### Vestigium (7pts)


#### Get input data (for test)

```python
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
```
> [[1 2]  
>  [3 4]]  
> [[1 1]  
>  [2 2]]  
> [[1 1 3]  
>  [4 5 3]  
> [7 7 3]]

```python
matrix = np.array(matrix)
print(matrix)
```
> [array([[1, 2], [3, 4]])  
>  array([[1, 1], [2, 2]])  
>  array([[1, 1, 3], [4, 5, 3], [7, 7, 3]])] 


#### Output

```python
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
```

```python
for s in range(0, testcases) :
    print("Case #" + str(s+1) + ": "
          + str(k[s]) + " " + str(r[s]) + " " + str(c[s]))
```
> Case #1: 5 0 0  
> Case #2: 3 2 0  
> Case #3: 9 2 1


#### Submit

```python
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
```
> Sample Failed: RE


#### Second trial (incomplete)

```python
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
```

#### Practice

```python
len(testcases)
list(range(1, testcases+1))
```
> [1, 2, 3]

```python
matrix[0]
matrix[0][0]
matrix[0][0][0]
matrix[2][:, 2]
```
> array([[1, 2], [3, 4]])  
> array([1, 2])  
> 1
> array([3, 3, 3])

```python
case = int(input()) # number of test cases
t = case
data = []
```

```python
while t < 0 :
    data.append(input())
    if len(data) == 1 :
        t -= 1

print(data)
```
