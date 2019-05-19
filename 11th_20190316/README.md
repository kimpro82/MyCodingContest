# Oncoder Official Coding Test
https://www.oncoder.com/


## 제11회 온코더 공식 코딩테스트
2019.03.16 SAT


### Q3 - My Answer

Suddenly I realized that I misunderstanded the question, but it was too late.

This code is based on my wrong understanding, not exam writers' real purpose.


#### Before making a class, at a temporary function level, it works.

```python
# a given sample lists of coordinate and velocity
start = ["0 0 2","5 0 1"] # X Y V
finish = ["5 12","10 12"] # X Y
```

##### Part.1 - Preprocessing

```python
start2 = []
finish2 = []

for i in range(len(start)) :
    start2.append(start[i].split(' '))
    finish2.append(finish[i].split(' '))
    
    j = len(start) + 1
    for j in range(j) :
        start2[i][j] = int(start2[i][j])
        
    k = len(start)
    for j in range(j) :
        finish2[i][j] = int(finish2[i][j])
```

```python
print(start2)
```
> [[0, 0, 2], [5, 0, 1]]
```python
print(finish2)
```
> [[5, 12], [10, 12]]

##### Part.2 - Calculating the each unit's moving distance and its demanded time

```python
import math

distance = []
demanded_time = []

l = len(start2)
for l in range(l) :
    # 이동 거리 : 피타고라스의 정리("c^2 = a^2 + b^2") 활용
    distance.append(math.sqrt((finish2[l][0] - start2[l][0])**2 + (finish2[l][1] - start2[l][1])**2))
    demanded_time.append(distance[l]/start2[l][2])
```

```python
print(distance)
```
> [13.0, 13.0]
```python
print(demanded_time)
```
> [6.5, 13.0]
```python
print(min(demanded_time))
```
> 6.5

Actually, the result from Pythagorean theorem is also crazy(I hate math!).

Anyway, it works despite of wrong return. But, ……


#### My Final Answer

```python
# a given sample lists of coordinate and velocity
start = ["0 0 2","5 0 1"] # X Y V
finish = ["5 12","10 12"] # X Y

import math

start2 = []
finish2 = []

distance = []
demanded_time = []

class Solution:
    def solution(self, start, finish) :
        
        # "X Y V" "X Y" 꼴의 start, finish를 거리 연산이 가능한 "X, Y, V", "X, Y" 꼴로 변형
        self.start2 = start2
        self.finish2 = start2
        
        for i in range(len(self.start)) :
            self.start2.append(self.start[i].split(' '))
            self.finish2.append(self.finish[i].split(' '))
            
        j = len(self.start) + 1
        for j in range(j) :
            self.start2[i][j] = int(self.start2[i][j])
            
        k = len(self.start)
        for k in range(k) :
            self.finish2[i][k] = int(self.finish2[i][k])
                
        
        # 각 유닛의 이동 거리 및 도달 시간 계산
        self.distance = distance
        self.demanded_time = demanded_time
        
        l = len(self.start2)
        for l in range(l) :
            # 이동 거리 : 피타고라스의 정리("c^2 = a^2 + b^2") 활용
            self.distance.append(math.sqrt((self.finish2[l][0] - self.start2[l][0])**2 + (self.finish2[l][1] - self.start2[l][1])**2))
            self.demanded_time.append(self.distance[l]/self.start2[l][2])

        print(min(self.demanded_time))

# In the test, I don't need to make an instance for myself.
a = Solution()
a(["0 0 2","5 0 1"],["5 12","10 12"])
```

I think I converted well from functions to class, but why doesn't it work?

Maybe I don't understand the notion of class enough, yet.
