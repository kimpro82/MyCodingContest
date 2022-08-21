import math

n = int(input())

if n == 1 :
    prime = False
elif n <= 3 :
    prime = True
else :
    prime = True
    for i in range(2, int(math.sqrt(n)) + 1) :

        # test
        # print(n, int(math.sqrt(n)) + 1, i, n % i, prime)

        if n % i == 0 :
            prime = False
            break

if prime == True :
    print("소수입니다.")
else :
    print("소수가 아닙니다.")      # I missed a period …… crazy