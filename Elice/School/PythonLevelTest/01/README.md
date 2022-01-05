## Elice School

# 파이썬 레벨 테스트 > 01 도전! 파이썬 동화 10제
(2022.01.05)  
https://school.elice.io/courses/12005/lectures/100847


## 01. 안녕 토끼!

```python
print("Hello Rabbit!")
```

> Hello Rabbit!


## 02. 카드병정의 장미 세기

```python
# ?를 채워주세요
x = 6
y = 3

# 빈 곳도 채워주세요!
# 더하기 연산
my_sum = x + y
print('my_sum :', my_sum)

# 빼기 연산
my_sub = x - y
print('my_sub :', my_sub)

# 곱하기 연산
my_mul = x * y
print('my_mul :', my_mul)

# 나누기 연산
my_div = x / y
print('my_div :', my_div)
```

> my_sum : 9  
> my_sub : 3  
> my_mul : 18  
> my_div : 2.0


## 03. 거꾸로 숫자 세기

```python
count = 10

for i in range(0, 10) :
    print(count)
    count -= 1
```

> 10  
> 9  
> ……  
> 1


## 04. 개굴개굴 개구리

```python
input = input()

for letter in input :
    if letter != ' ' :
        print("개굴", end = '')
    else :
        print(' ', end = '')
print()
```

> 안녕 나는 엘리스야

> 개굴개굴 개굴개굴 개굴개굴개굴개굴


## 05. 구름다리를 건너는 토끼

```python
def crossBridge(steps):
    cnt = 0
    current = 0
    n = len(steps)
    while (current < n) :
        current += steps[current]
        cnt += 1

        # test
        # print(cnt, current)

    return cnt

print(crossBridge([1, 1, 2, 3, 5]))
```

> 4


## 06. 개구리 왕자 이름 찾기

```python
def isPrince(frogList):
    for item in frogList :
        if item[0] == 'F' :
            return item

print(isPrince(['Alice', 'Bob', 'Frog']))
```

> Frog


## 07. 토끼와 거북이의 달리기 경주

```python
N, M = map(int, input().split(' '))

rabbit = N
turtle = M

while (rabbit != turtle) :
    if (rabbit > turtle) :
        turtle += M
    elif (rabbit < turtle) :
        rabbit += N

print(rabbit)
```

> 3 5

> 15


## 08. 엘리스와 별 헤는 밤

```python
input = int(input())

distance1 = input * ' '
if input % 2 == 1 :
    distance2 = input * ' '
else :
    distance2 = (input - 1) * ' '
    
print('*', distance1, '*', distance1, '*', sep = '')
print((int(input / 2) + 1) * ' ', '*', distance2, '*', sep = '')
```

> 3

> \*&nbsp;&nbsp;&nbsp;\*&nbsp;&nbsp;&nbsp;\*  
> &nbsp;&nbsp;\*&nbsp;&nbsp;&nbsp;\*


## 09. 엘리스와 이상한 상자

```python
class maxMachine :
    def __init__(self) :
        self.numbers = []

    def addNumber(self, n) :
        self.numbers.append(n)

    def removeNumber(self, n) :
        if n in self.numbers :
            self.numbers.remove(n)

    def getMax(self) :
        return max(self.numbers)
```

```python
def main():

    myMachine = maxMachine()

    '''
    테스트를 하고싶으면, 아래 부분을 수정합니다.
    '''

    myMachine.addNumber(2)
    myMachine.addNumber(5)
    myMachine.addNumber(3)
    myMachine.addNumber(4)

    print(myMachine.getMax())

    myMachine.removeNumber(5)

    print(myMachine.getMax())

    myMachine.removeNumber(1)

    print(myMachine.getMax())

if __name__ == "__main__":
    main()
```

> 5  
> 4  
> 4


## 10. 엘리스와 딱지접기

```python
class Rectangle:
    '''1. Rectangle 클래스를 완성해봅시다.'''
    def __init__ (self, width, height) :
        self.width = width
        self.height = height
    def area(self) :
        return self.width * self.height
```

```python
class Square:
    """2. Square 클래스를 정의하고, 완성해봅시다."""
    def __init__ (self, width) :
        self.width = width
    def area(self) :
        return self.width ** 2
```

```python
elice = Rectangle(10, 20)
print(elice.area())

bob = Square(10)
print(bob.area())
```

> 200  
> 100