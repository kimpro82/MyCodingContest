# Q4. 짝수 갯수 구하기

class Solution:
    def solution(self, arr):
        self.arr = arr
        n = 0
        for i in list(arr) :
            if i % 2 == 0 :
                n += 1
            else :
                n += 0
        return n
