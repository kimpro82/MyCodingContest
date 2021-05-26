a = int(input())
b = str(input())

sum = 0
for i in range(0,len(b)) :
    answer = a * int(b[-i-1])
    print(answer)
    sum += answer * pow(10, i)

print(sum)