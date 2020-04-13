"""
AtCoder Beginner Contest 162
2020.4.12 21:00
"""

# C - Sum of gcd of Tuples (Easy)

# a = int(input(K))
K = int(3)
a, b, c = 0, 0, 0

for a in range(1, K+1) :
    for b in range(1, K+1) :
        for c in range(1, K+1) :

            while(b) : 
                a, b = b, a % b 
            while(c) :
                b, c = c, b % c

            c += c
            # print(a, b, c)

print(c) # does't work well
