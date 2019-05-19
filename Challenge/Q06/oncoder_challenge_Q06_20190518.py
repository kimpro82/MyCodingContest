# Q6. 셀프넘버 판별

class Solution:

    def solution(self, a):
        self.a = a
        self.mysumlist = []
        self.mycount = 0

        for i in list(range(1,self.a+1)) :

            self.mysum = i
            for j in list(range(0,len(str(i)))) :
                self.mysum += int(str(i)[j])

            self.mysumlist.append(str(self.mysum))

        return self.mysumlist.count(str(a))


# test
do = Solution()
do.solution(25)


# practice
a = 25
print(str(a)[0])
print(str(a)[1])
print(len(str(a)))

# Let's master list(range())
print(range(0,len(str(a))))
print(list(range(0,len(str(a))))) # What a magic?

print(list(range(2,3)))
print(list(range(1,3)))
print(list(range(0,3)))

print(str(a)[0] + str(a)[1])
print(a + int(str(a)[0]) + int(str(a)[1]))

# loop 1
mylist = []
for i in list(range(1,a+1)) :
    mylist.append(i)
print(mylist)

# loop 2
mysum = a
for j in list(range(0,len(str(a)))) :
    mysum += int(str(a)[j])
print(mysum)

# using count() method
print(mysum.count(32))
print(str(mysum).count('32'))

# loop 1 + 2
mysumlist = []
for i in list(range(1,a+1)) :
    mysum = i
    for j in list(range(0,len(str(i)))) :
        mysum += int(str(i)[j])
        print(i, j, mysum)
    mysumlist.append(str(mysum))
    
print(mysumlist)
str(mysumlist).count('32')
