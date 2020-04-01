"""
April Fools Day Contest 2020
2020.04.01
"""


# D. Again?


# D: first trial

def solution() :

    anum = input()
    num = int(anum[1:])
    
    if num % 2 == 1 :
        return 1
    else :
        return 0

solution()


# D: second trial

# anum = 'A278832'
anum = input()

def solution(anum=anum) :

    num = int(anum[1:])
    
    if num % 2 == 1 :
        return 1
    else :
        return 0

solution()



# D: third trial

# anum = 'A278832'
anum = input()
num = int(anum[1:])
    
if num % 2 == 1 :
    print(1)
else :
    print(0)
