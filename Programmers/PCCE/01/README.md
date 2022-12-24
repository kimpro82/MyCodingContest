# [프로그래머스 - PCCE 모의고사 1회](../../../README.md#programmers)

2022.12.24 (It is a good day to code ……)

https://school.programmers.co.kr/learn/courses/15006/


## \<List>

- [01](#01)
- [02](#02)
- [03](#03)
- [04](#04)
- [05](#05)
- [06](#06)
- [07](#07)
- [08](#08)
- [09](#09)
- [10](#10)


## [01](#list)

```py
num1 = 100
# num2 = "200"
num2 = 200

# 출력 코드
print(num1 + num2)
```


## [02](#list)

```py
# 입력을 받는 코드입니다. 수정하지 말아주세요.
num = int(input())

if num > 0 :
    print("양수입니다")
elif num == 0 :
    print("0입니다")
else :
    print("음수입니다")
```


## [03](#list)

```py
answer = 0

for num in range(10, 101, 2):
    answer += num

print(answer)
```


## [04](#list)

```py
num1 = 1000 % 300
if num1 == 100 :
    answer1 = True
else:
    answer1 = False

num2 = 500 // 200
if num2 == 2 :
    answer2 = True
else:
    answer2 = False

str1 = "Hello" + "Python"
if str1 == "HelloPython" :
    answer3 = True
else:
    answer3 = False

str2 = "Hi" * 3
if str2 == "HiHiHi" :
    answer4 = True
else:
    answer4 = False
```


## [05](#list)

```py
def func1(a):
    return a * a

def func2(a):
    if a < 0 :
        return -1 * a
    return a

def func3(a, b):
    return a - b

def func4(a, b):
    if b > 0:
        return a % b
    return a % (-1 * b)
```
```py
num1 = int(input())
num2 = int(input())

answer_mod = func4(num1, num2)
answer_pow = func1(num1)
answer_abs = func2(num2)

print("num1을 num2의 절댓값으로 나눈 나머지는", answer_mod, "입니다")
print("num1의 제곱 값은", answer_pow, "입니다")
print("num2의 절댓값은", answer_abs, "입니다")
```


## [06](#list)

```py
num_list = [1, 3, 5, 2, 12]

for i in range(len(num_list)):
    # for j in range(i):
    for j in range(num_list[i]):
        print(num_list[i], end=' ')
    print()
```


## [07](#list)

```py
num_list = [9, 2, 3, 1, 6, 8, 0, 8, 9, 2, 1, 7, 7, 3, 5]

count_list = [0] * 10

for i in range(len(num_list)):
    # count_list[i] += i
    count_list[num_list[i]] += 1

# 출력 코드
print(count_list)
```


## [08](#list)

```py
def solution(num_list):
    count_even = 0
    answer = []
    
    for num in num_list:
        if num % 2 == 0:
            answer.append("even")
            count_even += 1
            
            # if count_even > 3:
            if count_even >= 3:
                break
        else:
            answer.append("odd")
    
    return answer
```


## [09](#list)

```py
def solution(num_list):
    answer = []
    for i in num_list:
        temp = True
        for j in range(2, int(i/2) + 1):
            if i % j == 0:
                temp = False
                break
        answer.append(temp)
    return answer
```


## [10](#list)

```py
def solution(text, anagram, sw):
    answer = ''
    temp = [[]] * len(text)                     # no [] but [[]]
    if sw == True:
        for i in range(len(text)):
            temp[anagram[i]] = text[i]
        for i in temp:
            answer += i
    else:
        for i in range(len(text)):
            answer += text[anagram[i]]
    return answer
```