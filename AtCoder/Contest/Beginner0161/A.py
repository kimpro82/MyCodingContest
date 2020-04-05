"""
AtCoder Beginner Contest 161
2020.4.4 Sat
"""

# A. ABC Swap

data = input().split()
# data = "1 2 3".split()
order = [2, 0, 1]
shuffle = []

for i in order :
    shuffle.append(data[i]+' ')

output = " ".join(shuffle)
print(output)


# practice
input = "X Y Z".split()
print(input)
