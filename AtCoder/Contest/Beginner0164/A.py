"""
AtCoder Beginner Contest 164
2020-04-26(Sun)
https://atcoder.jp/contests/abc164/
"""

# A - Sheep and Wolves

'''
# Sample Input 1
4 5
'''

S, W = list(map(int, input().split()))
# S, W = list(map(int, "4 5".split()))

if W >= S :
    print("unsafe")
else :
    print("safe")
