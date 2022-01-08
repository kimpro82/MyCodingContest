class Class1(object):
    def method1(self):
        return 'm1'


#빈칸을 잘 채워 넣어 뒤의 print문이 잘 실행되도록 해 봅시다.
class Class2(Class1):
    def method2(self):
        return 'm2'


c1 = Class1()
print(c1.method1())

c2 = Class2()
print(c2.method1())
print(c2.method2())