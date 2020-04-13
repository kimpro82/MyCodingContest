"""
Codeforces Round #634 (Div. 3)
2020-04-13 23:35
https://codeforces.com/contest/1335
"""

# B. Construct the String

'''
# can't use string module
import string
letters = list(string.ascii_lowercase)
print(letters)
'''

t = int(input())
# t = 4
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
           'u', 'v', 'w', 'x', 'y', 'z']

for i in range(0, t) :

    n, a, b = list(map(int, input().split()))
    # n, a, b = list(map(int, "5 2 2".split()))

    left = ""

    for j in range(0, b) :
        left += letters[j]

    middle = letters[b-1] * (a-b)

    right = ""
    for k in range(0, n-a) :
        right += left[k % b]

    print(left + middle + right)
