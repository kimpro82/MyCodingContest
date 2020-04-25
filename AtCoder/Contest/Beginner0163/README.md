## AtCoder Beginner Contest 163
2020-04-19(Sun)  
https://atcoder.jp/contests/abc163

### A - Circle Pond

```python
R = int(input())

print(R * 2 *3.141592)
```
easy, but it seems somewhat ugly to call `Pi` value in Python.


### B - Homework
```python
'''
# Sample Input 1
41 2
5 6
'''
```

#### Trial 1
```python
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
```
It returns Runtime Error

#### Trial 2
```python
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
```
Accepted


### C - management

```python
# N = int(input())
N = 7

# A = list(map(int, input().split()))
A = list(map(int, "1 2 3 4 5 6".split()))

sum = 0
for i in range(0, N) :
    print(i, A.count(i+1))
    # print(A.count(i+1))
```
Failed to solve
