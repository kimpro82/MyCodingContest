# Q3. 홀수 짝수 판별

class Solution:
    def solution(self, a):
        self.a = a
        if a % 2 == 1 :
            return "ODD"
        else :
            return "EVEN"
