##
# Problem
class Problem:
    def __init__(self, number):
        self.__number = number
        self.__tStart = None
        print 'Initialized Problem ' + str(self.__number)
        
    def solving(self):
        print 'Solving Problem ' + str(self.__number)
        self.__tStart = time.time()

    def solved(self, ans):
        print 'Solved Problem ' + str(self.__number) + ' in ' +\
              str(abs(self.__tStart - time.time())) + ' seconds!'
        print 'The answer is: ' + str(ans)