a = int(input())
b = str(input())

for i in range(0,len(b)) :
    print(a*int(b[-i-1]))

print(a*int(b))             // crazy