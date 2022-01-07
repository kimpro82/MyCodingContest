values = [int(v) for v in input().split()]

for item in values :
    if values.count(item) % 2 == 1 :
        print(item)
        break