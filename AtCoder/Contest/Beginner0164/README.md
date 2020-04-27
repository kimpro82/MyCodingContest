## AtCoder Beginner Contest 164
2020-04-26(Sun)  
https://atcoder.jp/contests/abc164/


### A - Sheep and Wolves

```python
'''
# Sample Input 1
4 5
'''
```

```python
S, W = list(map(int, "4 5".split()))

if W >= S :
    print("unsafe")
else :
    print("safe")
```


### B - Battle

```python
'''
# Sample Input
10 9 10 10
46 4 40 5
'''
```

```python
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
```


### C - gacha

```python
'''
# Sample Input 1
3
apple
orange
apple
'''
```

#### Trial 1
```python
N = int(input())
# N = 3

items = []

for i in range(0, N) :
    newItem = str(input())
    # newItem = str("apple")
    # print(newItem)
    
    if newItem not in items :
        items.append(newItem)

print(len(items)) # don't forget print()!
```
> C015_scrambled : Time Limit Exceeded

#### Trial 2
```python
N = int(input())
# N = 3

items = set()

for i in range(0, N) :
    items.add(str(input()))
    # items.add(str("apple"))
    # print(newItem)

print(len(items)) # don't forget print()!
```


### D - Multiple of 2019

```python
'''
# Sample Input
1817181712114
14282668646
2119
'''
```

#### Trial 1
```python
S = abs(int(input()))
# S = abs(int(1817181712114))
length = len(str(S))
 
multiple = 0
 
for i in range(0, length-3) :
    for j in range(i+4, length+1) :
        num = str(S)[i:j:1]
        if int(num) <= 200000 and int(num) % 2019 == 0 :
            multiple += 1
 
print(multiple)
```
> C009_scrambled : Time Limit Exceeded

#### Trial 2
```python
S = abs(int(input()))
# S = abs(int(1817181712114))
strS = str(S)
length = len(strS)

multiple = 0

for i in range(0, length-3) :
    for j in range(i+4, length+1) :
        num = strS[i:j:1]
        intNum = int(num)
        if intNum <= 200000 and intNum % 2019 == 0 :
            multiple += 1

print(multiple)
```
> C009_scrambled : Time Limit Exceeded

#### Trial 3
```python
S = abs(int(input()))
# S = abs(int(1817181712114))
strS = str(S)
length = len(strS)

multiple = 0

for i in range(0, length-3) :
    for j in range(i+4, length+1) :
        num = strS[i:j:1]
        intNum = int(num)
        if intNum <= 200000 :
            if intNum % 2019 == 0 :
                multiple += 1

print(multiple)
```
> C009_scrambled : Time Limit Exceeded


### F - I hate Matrix Construction

```python
'''
# Sample Input 1
2
0 1
1 0
1 1
1 0
'''
```

```python
N = int(input())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
U = list(map(int, input().split()))
V = list(map(int, input().split()))
    
N = 2
S = list(map(int, "0 1".split()))
T = list(map(int, "1 0".split()))
U = list(map(int, "1 1".split()))
V = list(map(int, "1 0".split()))
```
failed
