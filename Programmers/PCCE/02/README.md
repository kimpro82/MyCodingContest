# [프로그래머스 - PCCE 모의고사 2회](../../../README.md#programmers)

2022.12.25 Even Jesus' birthday can't stop my coding!

https://school.programmers.co.kr/learn/courses/15007/


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
num = 20
# 123_string = "123"
string_123 = "123"
true_bool = True

print(num, string_123, true_bool)
```


## [02](#list)

```py
bool1 = 2 < 5
bool2 = True == "True"

if bool1 :
    print("출력되게 하세요.")

if bool2 :
    print("출력되지 않게 하세요.")
```


## [03](#list)

```py
score = int(input())

if score >= 90:
    print("A")
elif score >= 80:
    print("B")
elif score >= 70:
    print("C")
elif score >= 60:
    print("D")
else:
    print("F")
```


## [04](#list)

```py
n = int(input())

factorial = 1
for i in range(2, n + 1):
    factorial *= i

print(factorial)
```


## [05](#list)

```py
def solution(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return "윤년"
            else:
                return "평년"
        else:
            return "윤년"
    else:
        return "평년"
```


## [06](#list)

```py
def solution(n):
    for i in range(n):
        # for j in range(i):
        for j in range(i + 1):
            print('*',end='')
        print()
```


## [07](#list)

```py
def func1(msg):
    return len(msg)

def func2(msg):
    for letter in msg:
        if '0' <= letter <= '9':
            continue
        return False
    return True

def func3(msg):
    for letter in msg:
        if 'a' <= letter <= 'z':
            return True
        if 'A' <= letter <= 'Z':
            return True
    return False

def func4(msg):
    while(" " in msg):
        msg = msg.replace(" ", "")
    return msg

def func5(msg):
    return msg[:3] + "-" + msg[3:7] + "-" + msg[7:]
```
```py
def solution(phone):
    phone = func4(phone)

    if not func2(phone) :
        return "잘못된 입력입니다"

    if func1(phone) != 11:
        return "잘못된 입력입니다"

    phone = func5(phone)

    return phone
```


## [08](#list)

```py
def solution(num_list):
    for n in range(len(num_list)):
        for i in range(len(num_list)-1):
            if num_list[i] > num_list[i+1]:
                num_list[i], num_list[i+1] = num_list[i+1], num_list[i]

    return num_list
```


## [09](#list)

```py
def solution(serial):
    answer = ''
    # serial = str(serial)                                                      # not needed

    # Elements
    sex      = ["male", "female"]
    division = ["operation", "sales", "develop", "finance", "law", "research"]

    if serial[4] != "0":
        team = serial[4:6] + "team"
    else :
        team = serial[5] + "team"

    sum = 0
    for i in serial[0:6]:
        sum += int(i)   
    valid    = ["invalid", "valid"]        

    # Concatenate
    answer += sex[int(serial[0:2])-1] + "/" + \
              division[int(serial[2:4])-10] + "/" + \
              team + "/" + \
              valid[sum % 13 == int(serial[6:])]

    return answer
```


## [10](#list)

```py
# there must be more efficient code than this crazy one ……
# maybe it'll be better to use range() somehow

def solution(n, board, position):

    answer = []

    for a, b in position:

        # Count each cell's neighbors
        sum = 0
        if a > 0 and a < len(board) - 1:
            sum += board[a-1][b]
            sum += board[a+1][b]
            if b > 0 and b < len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
                sum += board[a+1][b-1]
                sum += board[a-1][b+1]
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a-1][b+1]
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
                sum += board[a+1][b-1]
        elif a == 0 and a < len(board) - 1:
            sum += board[a+1][b]
            if b > 0 and b < len(board[0]) - 1:
                sum += board[a][b-1]
                sum += board[a+1][b-1]
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a][b+1]
                sum += board[a+1][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a][b-1]
                sum += board[a+1][b-1]
        elif a > 0 and a == len(board) - 1:
            sum += board[a-1][b]
            if b > 0 and b < len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
                sum += board[a-1][b+1]
                sum += board[a][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a-1][b+1]
                sum += board[a][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a-1][b-1]
                sum += board[a][b-1]
        else:
            if b > 0 and b < len(board) - 1:
                sum += board[a][b-1]
                sum += board[a][b+1]
            elif b == 0 and b < len(board[0]) - 1:
                sum += board[a][b+1]
            elif b == len(board[0]) - 1:
                sum += board[a][b-1]

        # Determine if survive
        if board[a][b] == 1 and (sum <=2 or sum >= 5):
            answer.append(0)
        elif board[a][b] == 0 and sum == 2:
            answer.append(1)
        else:
            answer.append(board[a][b])
    
    return answer
```