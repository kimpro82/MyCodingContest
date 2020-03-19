# Codeforces Round #628 (Div. 2)
# 2020-03-14 17:35:00

# A. EhAb AnD gCd
# https://codeforces.com/contest/1325/problem/A

def gcd(a, b):
    mod = a%b
    while mod > 0:
        a = b
        b = mod
        mod = a%b
    return b

def lcm(a, b):
    return a*b//gcd(a,b)

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


solution(14)
solution(10)
solution(2)
