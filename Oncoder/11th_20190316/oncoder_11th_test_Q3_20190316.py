# -*- coding: utf-8 -*-


# Q3 - My Answer

# a given sample lists of coordinate and velocity
start = ["0 0 2","5 0 1"] # X Y V
finish = ["5 12","10 12"] # X Y

import math

start2 = []
finish2 = []

distance = []
demanded_time = []

class Solution:
    def solution(self, start, finish) :
        
        # "X Y V" "X Y" 꼴의 start, finish를 거리 연산이 가능한 "X, Y, V", "X, Y" 꼴로 변형
        self.start2 = start2
        self.finish2 = start2
        
        for i in range(len(self.start)) :
            self.start2.append(self.start[i].split(' '))
            self.finish2.append(self.finish[i].split(' '))
            
        j = len(self.start) + 1
        for j in range(j) :
            self.start2[i][j] = int(self.start2[i][j])
            
        k = len(self.start)
        for k in range(k) :
            self.finish2[i][k] = int(self.finish2[i][k])
                
        
        # 각 유닉의 이동 거리 및 도달 시간 계산
        self.distance = distance
        self.demanded_time = demanded_time
        
        l = len(self.start2)
        for l in range(l) :
            # 이동 거리 : 피타고라스의 정리("c^2 = a^2 + b^2") 활용
            self.distance.append(math.sqrt((self.finish2[l][0] - self.start2[l][0])**2 + (self.finish2[l][1] - self.start2[l][1])**2))
            self.demanded_time.append(self.distance[l]/self.start2[l][2])

        print(min(self.demanded_time))


# In the test, I don't need to make an instance for myself.
a = Solution()
a(["0 0 2","5 0 1"],["5 12","10 12"])



# Before making class


# Part.1 - Preprocessing
start2 = []
finish2 = []

for i in range(len(start)) :
    start2.append(start[i].split(' '))
    finish2.append(finish[i].split(' '))
    
    j = len(start) + 1
    for j in range(j) :
        start2[i][j] = int(start2[i][j])
        
    k = len(start)
    for j in range(j) :
        finish2[i][j] = int(finish2[i][j])

print(start2)
print(finish2)


# Part.2 - Calculating the each distances and their demanded moving time
import math

distance = []
demanded_time = []

l = len(start2)
for l in range(l) :
    # 이동 거리 : 피타고라스의 정리("c^2 = a^2 + b^2") 활용
    distance.append(math.sqrt((finish2[l][0] - start2[l][0])**2 + (finish2[l][1] - start2[l][1])**2))
    demanded_time.append(distance[l]/start2[l][2])

print(distance)
print(demanded_time)
print(min(demanded_time))

    
