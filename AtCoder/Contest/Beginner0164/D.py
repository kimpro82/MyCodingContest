"""
AtCoder Beginner Contest 164
2020-04-26(Sun)
https://atcoder.jp/contests/abc164/
"""


# D - Multiple of 2019

'''
# Sample Input
1817181712114
14282668646
2119
'''

S = abs(int(input()))
# S = abs(int(1817181712114))
length = len(str(S))
 
multiple = 0
 
for i in range(0, length-3) :
    for j in range(i+4, length+1) :
        num = str(S)[i:j:1]
        if int(num) <= 200000 and int(num) % 2019 == 0 :
            multiple += 1
 
print(multiple)

# C009_scrambled : Time Limit Exceeded


# D - Multiple of 2019 / 2nd trial

S = abs(int(input()))
# S = abs(int(1817181712114))
strS = str(S)
length = len(strS)

multiple = 0

for i in range(0, length-3) :
    for j in range(i+4, length+1) :
        num = strS[i:j:1]
        intNum = int(num)
        if intNum <= 200000 and intNum % 2019 == 0 :
            multiple += 1

print(multiple)
        
# C009_scrambled : Time Limit Exceeded


# D - Multiple of 2019 / 3rd trial

S = abs(int(input()))
# S = abs(int(1817181712114))
strS = str(S)
length = len(strS)

multiple = 0

for i in range(0, length-3) :
    for j in range(i+4, length+1) :
        num = strS[i:j:1]
        intNum = int(num)
        if intNum <= 200000 :
            if intNum % 2019 == 0 :
                multiple += 1

print(multiple)

# C009_scrambled : Time Limit Exceeded
