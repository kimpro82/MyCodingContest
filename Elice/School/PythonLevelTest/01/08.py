input = int(input())

distance1 = input * ' '
if input % 2 == 1 :
    distance2 = input * ' '
else :
    distance2 = (input - 1) * ' '
    
print('*', distance1, '*', distance1, '*', sep = '')
print((int(input / 2) + 1) * ' ', '*', distance2, '*', sep = '')