# Oncoder Official Coding Test
https://www.oncoder.com/

## 제14회 온코더 공식 코딩테스트
2019.07.13 SAT

### Q2 - My Answer
This is my first working code among all the trial in the test!  
But I coudn't submit it in time ……

#### Trial 1
```python
# given variable
low = 10
high = 20
```

```python
# make list as integer
list_int = list(range(low,high+1))
list_int
list_int[1]
```
> [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]  
> 11

```python
# convert elements of the list from integer to string
list_str = list(map(str, list_int))
list_str
list_str[1]
```
> ['10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20']  
> '11'

```python
# count the number of elements including a specific text from list
list_str[1].count('8')
list_str[8]
list_str[8].count('8')
```
> 0  
> '18'  
> 1

```python
# append method test
list_count = []
list_count.append(list_str[0].count('8'))
list_count.append(list_str[1].count('8'))
list_count.append(list_str[2].count('8'))
list_count
```
> [0, 0, 0]

```python
# for문 test
for i in list_int :
    print(i)
```
> 10
11
12
13
14
15
16
17
18
19
20

```python
len(list_int)
range(0,len(list_int))
```

> 11  
> range(0, 11)

```python
for i in range(0,len(list_int)) :
    print(i)
```
> 0
1
2
3
4
5
6
7
8
9
10

```python
# for문
list_count = []

for i in range(0,len(list_str)) :
    list_count.append(list_str[i].count('8'))
    print(list_count)
```
> [0]  
> [0, 0]  
> [0, 0, 0]  
> [0, 0, 0, 0]  
> [0, 0, 0, 0, 0]  
> [0, 0, 0, 0, 0, 0]  
> [0, 0, 0, 0, 0, 0, 0]  
> [0, 0, 0, 0, 0, 0, 0, 0]  
> [0, 0, 0, 0, 0, 0, 0, 0, 1]  
> [0, 0, 0, 0, 0, 0, 0, 0, 1, 0]  
> [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0]

```python
min(list_count)
```
> 0

```python
# list에서 최소값 구하기
min(list_int)
min(list_str)
```
> 10  
> '10'

```python
# 완성 : befor class
low = 8808
high = 8880

list_int = list(range(low,high+1))
list_str = list(map(str, list_int))

list_count = []

for i in range(0,len(list_str)) :
    list_count.append(list_str[i].count('8'))

min(list_count)
```
> 2

```python
for i in range(0,len(list_int)) :
    list_count.append(list_int[i].count('8'))

min(list_count)
```
> AttributeError: 'int' object has no attribute 'count'

```python
# 완성 : class
class Solution:
    def solution(self, low, high):
        self.low = low
        self.high = high
        self.list_count = []
        
        self.list_int = list(range(self.low,self.high+1))
        self.list_str = list(map(str, self.list_int))

        for i in range(0,len(self.list_str)) :
            self.list_count.append(self.list_str[i].count('8'))
            if self.list_count[i] == 0 :
                break

        return min(self.list_count)
```

```python
# test
test = Solution()
test.solution(1,10)
test.solution(88,88)
test.solution(800,899)
test.solution(8808,8880)
```
> 0  
> 2  
> 1  
> 2

But when I clicked the submission button, it responsed failure.  
I guess it will not answer wrong return value, but seems to be needed over the given time and memory.  
So I tried second by a brand new approach like the below.

#### Trial 2

```python
low = 88888
high = 88889

str_low = str(low)
str_high = str(high)

len_low = len(str_low)
len_high = len(str_high)
```

```python
# loop test
range(0,len_low)
for i in range(0,len_low) :
    print(i)
```
> 0
1
2
3
4

```python
## trial 2 완성 : before class
count8 = 0

if len_low != len_high :
    pass
else :
    for i in range(0,len_low) :
        print("i :", i)
        if str_low[i]=="8" and str_high[i]=="8" :
            count8 += 1
            print("count :", count8)
        else :
            break
```
> 
i : 0  
count : 1  
i : 1  
count : 2  
i : 2  
count : 3  
i : 3  
count : 4  
i : 4  
count : 5  
i : 5  

```python
print(count8)
```
> 5

```python
## trial 2 완성 : class
class Solution:
    def solution(self, low, high):
        self.low = low
        self.high = high
        self.count8 = 0
        
        # low, high를 int에서 str로 변환
        self.str_low = str(self.low)
        self.str_high = str(self.high)

        # str로 변환된 low, high의 자릿수 세기
        self.len_low = len(self.str_low)
        self.len_high = len(self.str_high)

        if self.len_low != self.len_high : # 자릿수가 다르다면 → 0
            pass
        else : # 자릿수가 같을 경우
            for i in range(0,self.len_low) :
                if self.str_low[i]=="8" and self.str_high[i]=="8" :
                    self.count8 += 1
                    # 앞에서부터 같은 자릿수의 숫자가 모두 8이라면 +1
                elif self.str_low[i]==self.str_high[i]:
                    continue
                    # 같은 자릿수의 숫자가 8은 아니지만 같다면 다음 자릿수로 넘어간다
                else :
                    break
                    # 같은 자릿수의 숫자가 서로 다르다면 종료한다

        return self.count8
```

```python
# test
test2 = Solution()
test2.solution(1,10)
test2.solution(88,88)
test2.solution(800,899)
test2.solution(8808,8880)
test2.solution(88880,88888)
test2.solution(888788,888788)
```
> 0  
> 2  
> 1  
> 2  
> 4  
> 5
The submission was late, but I've got correct answer code for the first time.  
Don't give it up and challenge the next test!
