### Codeforces Round #632 (Div. 2)
2020.4.9  
https://codeforces.com/contest/1333/problem/A


#### Input for test

```python
# input for test
input = "2\n3 2\n3 3"
print(input)
```
> 2  
> 3 2  
> 3 3

```python
data = input.split()
print(data)
```
> ['2', '3', '2', '3', '3']


#### Solve

```python
# input for submission
data = input().split()

cases = int(data[0])

# repeat i test cases
for i in range(0, cases) :

    r, c = int(data[i*2+1]), int(data[i*2+2]) # rows, colums

    if r % 2 == 1 :  # 홀수행 : 홀수행 all B & 마지말 홀수행 (c+1)/2칸 B
        for j in range(0, r) :
            # print(i, j, r, c) # check loop
            if c % 2 == 0 :
                if j == 0 :
                    print('B'+'W'*(c-1))
                elif j == 1 : # r>=2
                    if c % 2 == 1 :
                        print('W'+'B'*(c-1))
                    else :
                        print('B'+'W'*(c-1))
                elif j % 2 == 0 :
                    print('B'*c) # 홀수행 : all B
                else :
                    print('W'*c) # 짝수행 : all W
            else :
                if j == r-1 : # r>=2
                    if c % 2 == 1 :
                        print('B'*int(((c+1)/2))+'W'*int(((c-(c+1)/2))))
                    else :
                        print('B'+'W'*(c-1))
                elif j % 2 == 0 :
                    print('B'*c) # 홀수행 : all B
                else :
                    print('W'*c) # 짝수행 : all W

    else : # 짝수행 : 홀수행 all B & 2행 첫칸 B
        for j in range(0, r) :
            # print(i, j, r, c) # check loop
            if j == 1 :
                print('B'+'W'*(c-1))
            elif j % 2 == 0 :
                print('B'*c) # 홀수행 : all B
            else :
                print('W'*c) # 짝수행 : all W
```
> BW  
> BW  
> BB  
> BBB  
> WWW  
> BBW

But this couldn't be submitted because I didn't have registerd the contest. Crazy!
