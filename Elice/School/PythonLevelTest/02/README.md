## Elice School

# 파이썬 레벨 테스트 > 02 도전! 파이썬 동화 10제 2
(2022.01.05)  
https://school.elice.io/courses/12005/lectures/100848


## 01. 약수 구하기

```python
n = int(input())

divisor = []
for i in range(1, n + 1) :
    if n % i == 0 :
        divisor.append(i)

print(divisor)
```

> 12

> [1, 2, 3, 4, 6, 12]


## 02. In the Middle

```python
prices = []
for i in range(3) :
    prices.append(int(input()))

prices.sort()
print(prices[1])
```

> 1  
> 3  
> 2

> 2


## 03. 소수 판별하기

```python
import math

n = int(input())

if n == 1 :
    prime = False
elif n <= 3 :
    prime = True
else :
    prime = True
    for i in range(2, int(math.sqrt(n)) + 1) :

        # test
        # print(n, int(math.sqrt(n)) + 1, i, n % i, prime)

        if n % i == 0 :
            prime = False
            break

if prime == True :
    print("소수입니다.")
else :
    print("소수가 아닙니다.")      # I missed a period …… crazy
```

> 7

> 소수입니다.


## 04. 구구단

```python
N = int(input())

for i in range(1, 10) :
    print(N * i)
```

> 2

> 2  
> 4  
> ……  
> 18


## 05. 절댓값

```python
n = int(input())

print(abs(n))
```

> -7

> 7


## 06. 유일한 수

```python
values = [int(v) for v in input().split()]

for item in values :
    if values.count(item) % 2 == 1 :
        print(item)
        break
```

> 1 1 2 3 3 4 4 5 5

> 2


## 07. 말 더듬는 도도새

```python
s = input()

length = len(s)
for i in range(1, length + 1) :
    print(s[:i])
```

> ABC

> A  
> AB  
> ABC


## 08. 평균과 평균보다 큰 수

```python
values = [int(v) for v in input().split()]

length = len(values)
mean = sum(values) / length
print(mean)

for item in values :
    if item > mean :
        print(item)
```

> 1 2 3 4 5 6 7 8 9 10

> 5.5  
> 6  
> 7  
> 8  
> 9  
> 10


## 09. 약수의 합 구하기

```python
N = int(input())

sum = 0
for n in range(1, N + 1) :
    if N % n == 0 :
        sum += n

print(sum)
```

> 12

> 28


## 10. 접미사 배열

```python
s = input()

length = len(s)
suffix = []
for i in range(length) :
    suffix.append(s[i:])

suffix.sort()
for j in suffix :
    print(j)
```

> elice

> ce  
> e  
> elice  
> ice  
> lice