N, M = map(int, input().split(' '))

rabbit = N
turtle = M

while (rabbit != turtle) :
    if (rabbit > turtle) :
        turtle += M
    elif (rabbit < turtle) :
        rabbit += N

print(rabbit)