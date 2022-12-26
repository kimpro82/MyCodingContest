values = [int(v) for v in input().split()]

length = len(values)
mean = sum(values) / length
print(mean)

for item in values :
    if item > mean :
        print(item)