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



# practice

int('278832', 16) # 2,590,770
int('089956', 16) # 563,542
int('089957', 16) # 563,543
int('144045', 16) # 1,327,173

'A278832'[1:] # '278832'

int(a[1:])
int(a[1:]) % 2
