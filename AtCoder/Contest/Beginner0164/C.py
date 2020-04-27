"""
AtCoder Beginner Contest 164
2020-04-26(Sun)
https://atcoder.jp/contests/abc164/
"""


# C - gacha

'''
# Sample Input 1
3
apple
orange
apple
'''

N = int(input())
# N = 3

items = []

for i in range(0, N) :
    newItem = str(input())
    # newItem = str("apple")
    # print(newItem)
    
    if newItem not in items :
        items.append(newItem)

print(len(items)) # don't forget print()!

# C015_scrambled : Time Limit Exceeded


# C - gacha / 2nd trial

N = int(input())
# N = 3

items = set()

for i in range(0, N) :
    items.add(str(input()))
    # items.add(str("apple"))
    # print(newItem)

print(len(items)) # don't forget print()!
