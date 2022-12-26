## Elice School

# 파이썬 레벨 테스트 > 03 도전! 파이썬 생활코딩 10제
(2022.01.07)  
https://school.elice.io/courses/12005/lectures/100849


## 01. 수와 계산

```python
import math

a = 3.2
b = 4.7
c = 2
d = 10

#?를 채워주세요
print (math.floor(a))
print (math.ceil(b))
print (math.pow(c, d))

#괄호 안에 적당한 상수를 넣어주세요.
print (math.pi)
```

> 3  
> 5  
> 1024.0  
> 3.141592653589793


## 02. 문자와 데이터 타입

```python
#정수 타입
integer1 = 10
integer2 = 5

#실수 타입
float1 = 9.5
float2 = 5.5

#문자열 타입
string1 = "10"
string2 = "5"

#?를 채워 봅시다
print ( integer1 + integer2 )
print ( float1 + float2 )
print ( string1 + string2 )
```

> 15  
> 15.0  
> 105


## 03. 변수

```python
donation = 200
student = 10
sponsor = 100


print ((donation * student) / sponsor)

#다음 줄에 학생 수와 스폰서 수를 더해 출력해 봅시다
print(student + sponsor)
```

> 20.0  
> 110


## 04. 비교와 불리언

```python
print ( True )
print ( False )

a = 1
b = 1

print (a == b)
print ( a != b )
print ( 1 == 2 )

#?를 < 또는 > 또는 <=으로 채워보아요
print(1 < 2)
print(3 > 2)
print(5 <= 5)
```

> True  
> False  
> True  
> False  
> False  
> True  
> True  
> True


## 05. 조건문

```python
a = 11
b = 11
if a == b :
    print( "Hello!" )

#올바른 결과가 출력되도록 ?를 채워봅시다.
c = 10
d = 11

if a != b :
    print("Turtle!")
elif c < d :
    print("Rabbit!")
```

> Hello!  
> Rabbit!


## 06. 입력과 출력

```python
in_str = input ( "" )

ID_elice = "elice"
ID_rabbit = "rabbit"

if ID_elice == in_str:
    print ( "Hello, Elice!" )
elif ID_rabbit == in_str: #입력에 따라 알맞은 출력을 하도록 조건을 수정해 봅시다.
    print ( "Hello, Rabbit!" )
else :
    print ( "Who are you?" )
```

> elice

> Hello, Elice!


## 07. 논리 연산

```python
a = True
b = False


print(a and b)

#??에 적당한 연산자를 채워봅시다
if a or b :
    print(True)
else:
    print(False)
    
#올바른 값이 출력되도록 적당한 변수를 채워봅시다.
print(not a)
```

> False  
> True  
> False


## 08. 반복문

```python
#for문 사용
for i in range(0, 5):
    print(i)

print('-----')


#while문 사용
i = 0
while i < 5:
    print(i*2)
    i = i + 1

print('-----')


#for문을 사용해 문제를 풀어봅시다
for i in range(5, 10):
    print(i)

print('-----')


#while문을 사용해 문제를 풀어봅시다
i = 0
while i < 10:
    print(i)
    i = i + 3
```

> 0  
> 1  
> 2  
> 3  
> 4  
> \-----  
> ……  
> 9


## 09. 함수

```python
def make_string(str, num):
    return str*num

#아래 함수 호출하는 부분을 보고 함수의 내용을 채워 봅시다
def make_5string(str):
    return str*5


print(make_string('b', 3))
print(make_5string('a'))
```

> bbb  
> aaaaa


## 10. 상속

```python
class Class1(object):
    def method1(self):
        return 'm1'


#빈칸을 잘 채워 넣어 뒤의 print문이 잘 실행되도록 해 봅시다.
class Class2(Class1):
    def method2(self):
        return 'm2'


c1 = Class1()
print(c1.method1())

c2 = Class2()
print(c2.method1())
print(c2.method2())
```

> m1  
> m1  
> m2