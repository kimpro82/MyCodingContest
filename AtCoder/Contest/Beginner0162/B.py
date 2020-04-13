"""
AtCoder Beginner Contest 162
2020.4.12 21:00
"""

# B - FizzBuzz Sum

N = int(input())
N = 15
sum = 0

for i in range(1, N+1) :
    if i % 5 == 0 or i % 3 == 0 :
        continue # it doesn't need to return "Fizz", "Buzz" or "FizzBuzz".
    else :
        sum += i
    # print(i, sum)

print(sum)
