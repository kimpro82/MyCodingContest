N = int(input())

sum = 0
for n in range(1, N + 1) :
    if N % n == 0 :
        sum += n

print(sum)