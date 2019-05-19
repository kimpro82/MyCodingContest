# Oncoder Official Coding Test
https://www.oncoder.com/


## 제12회 온코더 공식 코딩테스트
2019.04.13 SAT


### Q3 - My Answer
But it never worked ……

```python
class Solution:
    
    width = []
    height = []
    rectangle = []
    area = []
    exp_area = 0

    #self.rectangle = array[rows, cols]
    
    def solution(self, K, rows, cols):
        self.K = K
        self.rows = rows
        self.cols = cols
        
        self.x_n = range(1,self.rows)
        self.y_n = range(1,self.cols)
        self.exp_area = exp_area
        
        # Get x_1, x_2 and width
        for i in range(1, self.rows+1) :
            for j in range(1, self.rows+1) :
                self.width.append(abs(self.x_n[i]-self.x_n[j]) + 1)
        
        # Get y_1, y_2 and height
        for i in range(1, self.cols+1) :
            for j in range(1, self.cols+1) :
                self.height.append(abs(self.y_n[i]-self.y_n[j]) + 1)
        
        # Multiple all of width[m] and height[n]
        for m in len(self.width) :
            for n in len(self.height) :
                self.area.append(self.width[m] * self.height[n]) 
        
        self.exp_area = sum(self.area)/self.K
        
        return self.exp_area
```

```python
Solution.solution(K=1,rows=2,cols=3)
```
> TypeError: solution() missing 1 required positional argument: 'self'


## Practice Code

```python
K = 1
rows = 2
cols = 3

rectangle = []
points = []

# get rectangle table
for i in range(1,rows+1) :
    for j in range(1,cols+1) :
        rectangle.append([i, j])

# get x1, x2, y1, y2
for i in range(1,rows+1) :
    for j in range(1,rows+1) :
        for k in range(1,cols+1) :
            for l in range(1,cols+1) :
                points.append([i, j, k, l])    
```

```python
points[1][0:1]
```
> [1]

```python
# Scoring in rectangle
for m in len(rectangle) :
    if min(points[m,0:1]> # 미완성
```
