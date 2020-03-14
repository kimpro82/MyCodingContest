### Codeforces Round #628 (Div. 2)
2020-03-14 17:35:00  
https://codeforces.com/contest/1325/problem/A

```python
def gcd(a, b):
    mod = a%b
    while mod > 0:
        a = b
        b = mod
        mod = a%b
    return b
```

```python
def lcm(a, b):
    return a*b//gcd(a,b)
```

```python
def solution(x) :
    for i in range(1, x-1) :
        y = x - i
        for a in range(1, y) :
            for b in range(1, y) :
                gcd_value = gcd(a, b)
                lcm_value = lcm(a, b)
                sum = gcd_value + lcm_value     
                # print(x, a, b, gcd_value, lcm_value, sum)
                if sum == x :
                    # print("finish")
                    break
            if sum == x :
                break
        if sum == x :
            break
    if sum != x :
        return 0
    return a, b # "It's guaranteed that the solution always exists."
```

#### Solve

```python
solution(14)
```
> (2, 12)

```python
solution(10)
```
> (2, 8)

```python
solution(2)
```
> UnboundLocalError: local variable 'sum' referenced before assignment
