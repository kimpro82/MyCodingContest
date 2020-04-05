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
