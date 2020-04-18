"""
Codeforces Round #635 (Div. 2)
Apr/15/2020 23:35 (UTC+9)
"""

# A. Ichihime and Triangle - First Trial

# Example input
'''
4
1 3 5 7
1 5 5 7
100000 200000 300000 400000
1 1 977539810 977539810
'''

t = int(input())
# t = 1

for i in range(0, t) :

    # convert all string to integer in list
    num = input().split()
    # num = "1 3 5 7".split()
    num = [int(j) for j in num] 
    # print(num)

    # get x, y, z
    for x in range(num[0], num[1]+1) :
        for y in range(num[1], num[2]+1) :
            for z in range(num[2], num[3]+1) :

                # check if x, y, z can make a triangle
                if x + y > z :
                    break

    print(x, y, z)


# A. Ichihime and Triangle - Second Trial

t = int(input())
# t = 1

for i in range(0, t) :

    # convert all string to integer in list
    # num = input().split()
    num = "1 1 977539810 977539810".split()
    num = [int(j) for j in num] 
    # print(num)

    # get x, y, z
    x = num[1]
    for y in range(num[1], num[2]+1) :
        z = num[2]

        # check if x, y, z can make a triangle
        if x + y > z :
            break

    print(x, y, z)

# Time limit exceeded on pretest 1 : "1 1 977539810 977539810"


# A. Ichihime and Triangle - Third Trial

t = int(input())
# t = 1

for i in range(0, t) :

    # convert all string to integer in list
    # num = input().split()
    num = "1 1 977539810 977539810".split()
    num = [int(j) for j in num] 
    # print(num)

    # get x, y, z
    x = num[1]
    z = num[2]
    y = max(z-x+1, num[1])

    print(x, y, z)
