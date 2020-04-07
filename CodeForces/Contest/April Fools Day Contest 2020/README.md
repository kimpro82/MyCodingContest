## April Fools Day Contest 2020
2020.04.01  
https://codeforces.com/contest/1331


### D. Again?

#### first trial

```python
def solution() :

    # anum = 'A278832'
    anum = input()
    num = int(anum[1:])
    
    if num % 2 == 1 :
        return 1
    else :
        return 0

solution()
```

#### second trial

```python
# anum = 'A278832'
anum = input()

def solution(anum=anum) :

    num = int(anum[1:])
    
    if num % 2 == 1 :
        return 1
    else :
        return 0

solution()
```

#### third trial

```python
# anum = 'A278832'
anum = input()
num = int(anum[1:])
    
if num % 2 == 1 :
    print(1)
else :
    print(0)
```

#### Practice

```python
int('278832', 16)
int('089956', 16)
int('089957', 16)
int('144045', 16)
```
> 2590770  
> 563542  
> 563543  
> 1327173

```python
'A278832'[1:]
```
> 278832

```python
int(a[1:])
int(a[1:]) % 2
```


### H. It's showtime

#### Solve

```python
inputnum = 123456
# inputnum = input()

mod = inputnum % 1000
n = int((inputnum - mod)/1000)
doubleFactorial = n

while n > 2 :
    if n >= mod and n % 2 == 0 : # guess something wrong
        doubleFactorial = 0
        break;
    doubleFactorial = (doubleFactorial * (n-2)) % mod
    # print(n, mod, doubleFactorial)
    n = n -2
   
print(doubleFactorial)    
```
> 171

#### Test

```python
inputnum = 6100
```
> 48

```python
inputnum = 9900
```
> 45

```python
inputnum = 100002
```
> 0  

But I recognized belately that the problem requires a specific programming language 'UnknownX', not Python.
