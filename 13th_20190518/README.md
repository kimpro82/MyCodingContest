# Oncoder Official Coding Test
https://www.oncoder.com/

## 제13회 온코더 공식 코딩테스트
2019.05.18 SAT

### Q3 - My Answer
Of course(?), it never worked ……

```python
# 순열 생성을 위한 라이브러리 불러오기
import itertools

class Solution:

    def solution(self, N, left, right):
        self.N = N
        self.left = left
        self.right = right

        # 1~N까지의 원소를 갖는 순열 생성
        self.mylist = list(range(1,self.N+1))
        mypermutation =  list(itertools.permutations(self.mylist))

        highest = 0
        left_count = 1
        right_count = 1
        self.answer = 0
        for i in list(range(0,len(mypermutation))) :

            # left
            for j in list(range(0,len(mypermutation[i]))) :


                if highest < mypermutation[i][j] :
                    left_count += 1
                    highest = max(highest, mypermutation[i][j])
                    
            # right
            for j in list(range(0,len(mypermutation[i]))) :

                    if highest < mypermutation[i][-j-1] :
                        right_count += 1
                        highest = max(highest, mypermutation[i][-j-1])

            if self.left==left_count and self.right==right_count:
                self.answer += 1

        return print(self.answer)
```

```python
do = Solution()
do.solution(3,2,1)
```
> 0

I'm so sad


### Practice Code

```python
testlist = [1,2,3]
testper =  list(itertools.permutations(testlist))
testper
```
> [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]

```python
testper[0]
testper[0][1]
```
> (1, 2, 3)  
> 2

```python
len(testper)
range(0,len(testper))
list(range(0,len(testper)))
```
> 6  
> range(0, 6)  
> [0, 1, 2, 3, 4, 5]

```python
for i in list(range(0,len(testper))) :
    print(testper[i])
```
> (1, 2, 3)  
  (1, 3, 2)  
  (2, 1, 3)  
  (2, 3, 1)  
  (3, 1, 2)  
  (3, 2, 1)
  
```python
for j in list(range(0,len(testper[0]))) :
    print(testper[0][j])
```
> 1  
  2  
  3

```python
for i in list(range(0,len(testper))) :
    print(testper[-i-1])
```
> (3, 2, 1)  
  (3, 1, 2)  
  (2, 3, 1)  
  (2, 1, 3)  
  (1, 3, 2)  
  (1, 2, 3)

```python
for j in list(range(0,len(testper[0]))) :
    print(testper[0][-j-1])
```
> 3  
  2  
  1

```python    
1==2 and 2==2
1==2 or 2==2
```
> False  
> True
