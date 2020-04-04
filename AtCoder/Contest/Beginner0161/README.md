## AtCoder Beginner Contest 161
2020.4.4 Sat  
https://atcoder.jp/contests/abc161

### A. ABC Swap

#### Test
```python
data = "1 2 3".split()
order = [2, 0, 1]
shuffle = []

for i in order :
    shuffle.append(data[i])

output = " ".join(shuffle)
print(output)
```
> 3 1 2

#### Submit
```python
data = input().split()
# data = "1 2 3".split()
order = [2, 0, 1]
shuffle = []

for i in order :
    shuffle.append(data[i])

output = " ".join(shuffle)
print(output)
```

#### Practice
```python
input = "X Y Z".split()
print(input)
```
> ['X', 'Y', 'Z']
