### Codeforces Round #634 (Div. 3)
2020-04-13 23:35  
https://codeforces.com/contest/1335


#### A. Candies and Two Sisters - First Trial

```python
# inputdata = input().split()
inputdata = "6 7 1 2 3 200000000 763243547".split()
print(inputdata)
```
> ['6', '7', '1', '2', '3', '200000000', '763243547']  

```python
t = int(inputdata[0])
# print(n)

for i in range(1, t+1) :

    num = int(inputdata[i])

    # num == odd number
    if num % 2 == 1 :
        print(int((num-1)/2))
    
    # num == even number
    else :
        print(int((num-2)/2))
```
> 3  
> 0  
> 0  
> 1  
> 99999999  
> 381621773

#### A. Candies and Two Sisters - Second Trial

```python
t = int(input())

for i in range(0, t) :

    num = int(input())

    # num == odd number
    if num % 2 == 1 :
        print(int((num-1)/2))

    # num == even number
    else :
        print(int((num-2)/2))
```
Accepted


#### B. Construct the String

```python
'''
# can't use string module
import string
letters = list(string.ascii_lowercase)
print(letters)
'''

t = int(input())
# t = 4
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
           'u', 'v', 'w', 'x', 'y', 'z']

for i in range(0, t) :

    n, a, b = list(map(int, input().split()))
    # n, a, b = list(map(int, "5 2 2".split()))

    left = ""
    for j in range(0, b) :
        left += letters[j]

    middle = letters[b-1] * (a-b)

    right = ""
    for k in range(0, n-a) :
        right += left[k % b]

    print(left + middle + right)
```
Accepted


#### C. Two Teams Composing

```python
from statistics import mode

t = int(input())
t = 4

for i in range(0, t) :
    # n = int(input())
    n = int(7)
    # a = list(map(int, input().split()))
    a = list(map(int, "4 2 4 1 4 3 4".split()))

    if n % 2 == 1 :
        maxsize = int((n-1)/2)
    else :
        maxsize = int(n/2)

    for j in range(0, maxsize) :
        # print(maxsize-j)
        teamsize = maxsize - j
        
        sameskills = a.count(mode(a)) # number of the mode
        uniqueskills = len(set(a)) # number of unique skills
        
        if sameskills >= teamsize and uniqueskills >= teamsize :
            break

    print(teamsize)
```
doesn't work when there's no mode(a)
