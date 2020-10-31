"""
AtCoder Regular Contest 107
2020-10-31(Sat)
https://atcoder.jp/contests/arc107/
"""



# A - Simple Math

'''
# Sample Input 1
1 2 3

# Sample Output 1
18

# Sample Input 2 
1000000000 987654321 123456789

# Sample Output 2 
951633476
'''

## trial 1

A, B, C = list(map(int, input().split()))
# A, B, C = list(map(int, "1 2 3".split()))   # test

sum = 0

for a in range(1, A+1) :
    for b in range(1, B+1) :
        for c in range(1, C+1) :
            sum += a*b*c
            print(a, b, c, sum)   # test

output = sum % 998244353
print(output)


## trial 2

A, B, C = list(map(int, input().split()))
# A, B, C = list(map(int, "1000000000 987654321 123456789".split()))   # test

sum = 0

for a in range(1, (A+1)%998244353) :
    for b in range(1, (B+1)%998244353) :
        for c in range(1, (C+1)%998244353) :
            sum += a*b*c
            # print(a, b, c, sum)   # test

print(sum)
