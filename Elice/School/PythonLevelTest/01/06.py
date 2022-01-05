def isPrince(frogList):
    for item in frogList :
        if item[0] == 'F' :
            return item

print(isPrince(['Alice', 'Bob', 'Frog']))