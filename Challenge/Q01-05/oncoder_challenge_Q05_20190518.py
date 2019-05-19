# Q5. 13 구하기
class Solution:
    def solution(self, a):
        self.a = a
        self.count = 0
        self.mylist = list(range(1,self.a+1))
        
        for i in self.mylist :
            if '13' in str(self.mylist[i-1]) :
                self.count += 1
                
        return self.count
        
# test
do = Solution()
do.solution(13)

# practice
a = 13
mylist = list(range(1,a+1))
mylist
mylist[12]

type(a)
'13' in str(a)
'13' in str(mylist[11])
'13' in str(mylist[12])