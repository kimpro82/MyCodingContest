class maxMachine :
    def __init__(self) :
        self.numbers = []

    def addNumber(self, n) :
        self.numbers.append(n)

    def removeNumber(self, n) :
        if n in self.numbers :
            self.numbers.remove(n)

    def getMax(self) :
        return max(self.numbers)

def main():

    myMachine = maxMachine()

    '''
    테스트를 하고싶으면, 아래 부분을 수정합니다.
    '''

    myMachine.addNumber(2)
    myMachine.addNumber(5)
    myMachine.addNumber(3)
    myMachine.addNumber(4)

    print(myMachine.getMax())

    myMachine.removeNumber(5)

    print(myMachine.getMax())

    myMachine.removeNumber(1)

    print(myMachine.getMax())

if __name__ == "__main__":
    main()