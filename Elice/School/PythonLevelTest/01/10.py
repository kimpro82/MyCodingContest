class Rectangle:
    '''1. Rectangle 클래스를 완성해봅시다.'''
    def __init__ (self, width, height) :
        self.width = width
        self.height = height
    def area(self) :
        return self.width * self.height

class Square:
    """2. Square 클래스를 정의하고, 완성해봅시다."""
    def __init__ (self, width) :
        self.width = width
    def area(self) :
        return self.width ** 2


elice = Rectangle(10, 20)
print(elice.area())

bob = Square(10)
print(bob.area())