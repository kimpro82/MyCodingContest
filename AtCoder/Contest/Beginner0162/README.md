## AtCoder Beginner Contest 162
2020.4.12 21:00
https://atcoder.jp/contests/abc162

### A - Lucky 7

#### Test
```python
# N = list(input())
N = list(str(117))
print(N)

if '7' in N :
    print("Yes")
else :
    print("No")
```
> Yes

#### Submit
```python
N = list(input())
# N = list(str(117))
# print(N)

if '7' in N :
    print("Yes")
else :
    print("No")
```


### B - FizzBuzz Sum

#### Test
```python
N = 15
sum = 0

for i in range(1, N+1) :
    if i % 5 == 0 or i % 3 == 0 :
        continue # it doesn't need to return "Fizz", "Buzz" or "FizzBuzz".
    else :
        sum += i
    # print(i, sum)

print(sum)
```
> 60

#### Submit
```python
N = int(input())
# N = 15
# sum = 0

for i in range(1, N+1) :
    if i % 5 == 0 or i % 3 == 0 :
        continue # it doesn't need to return "Fizz", "Buzz" or "FizzBuzz".
    else :
        sum += i
    # print(i, sum)

print(sum)
```
But it returns Runtime Error.

### C - Sum of gcd of Tuples (Easy)

#### Test
```python
# a = int(input(K))
K = int(3)
a, b, c = 0, 0, 0

for a in range(1, K+1) :
    for b in range(1, K+1) :
        for c in range(1, K+1) :

            while(b) : 
                a, b = b, a % b 
            while(c) :
                b, c = c, b % c

            c += c
            # print(a, b, c)

print(c) # doesn't work well
```
