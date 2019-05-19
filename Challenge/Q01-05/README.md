Challenge Tests


## Q1. 문자열 리턴

```Python
class Solution:
    def solution(self, str):
        self.str = str
        return str
```


## Q2. 연산하기

```Python
class Solution:
    def solution(self, a, b):
       self.a = a
       self.b = b
       return a**3 + b**2
```


## Q3. 홀수 짝수 판별

```Python
class Solution:
    def solution(self, a):
        self.a = a
        if a % 2 == 1 :
            return "ODD"
        else :
            return "EVEN"
```


## Q4. 짝수 갯수 구하기  

```Python
class Solution:
    def solution(self, arr):
        self.arr = arr
        n = 0
        for i in list(arr) :
            if i % 2 == 0 :
                n += 1
            else :
                n += 0
        return n
```


## Q5. 13 구하기 

```Python
class Solution:
    def solution(self, a):
        self.a = a
        self.count = 0
        self.mylist = list(range(1,self.a+1))
        
        for i in self.mylist :
            if '13' in str(self.mylist[i-1]) :
                self.count += 1
                
        return self.count
```

### test

```Python
do = Solution()
do.solution(13)
```
> 1

### practice
```Python
a = 13
mylist = list(range(1,a+1))
mylist
mylist[12]
```
> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]  
> 13

```Python
type(a)
```
> int

```Python
'13' in str(a)
'13' in str(mylist[11])
'13' in str(mylist[12])
```
> True  
> False  
> True
