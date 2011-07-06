import math, os, sys, string, time
        
##
# Problem 305
class P305(Problem):
    
    K_UPPER_LIMIT = 2
    K_LOWER_LIMIT = 1

    class SGenerator:
        def __init__(self):
            self.S = ''
            self.__index = 0
            self.grow()
        def generator(self):
            while True:
                self.__index += 1
                self.S += str(self.__index)
                yield self.S
        def __str__(self):
            return self.S
        def __repr__(self):
            return self.S
        def grow(self):
            #print '.'
            [self.generator().next() for s in range(0, 5000)]
            
    def __init__(self):
        self.m = {}
        self.g = P305.SGenerator()
        self.dx = None
        Problem.__init__(self, 305)

    # f(n) := the starting position of the n'th occurrence of n in S.
    def f(self, n):

        print 'f(%s) := ' % n,
        
        strN = str(n); lenN = len(strN)

        # make sure that S contains the number of n's we're looking for.
        count = self.g.S.count(strN)
        while count < n:
            self.g.grow()
            count = self.g.S.count(strN)

        ## print self.g.S            

        # lookahead until the index either meet or exceeds the value n, the index does
        # not actually need to fall on nth of n, but meet or exceed it.
        index = 0
        nSplit = self.g.S.split(strN)
        for i in nSplit:
            index += (len(i) + lenN)
            if (self.g.S[0:index].count(strN) >= n):
                break
            
        # recompute index based on index.
        index = self.g.S.index(strN, index)

        print index        

        return index
                    
    def solve(self):
        Problem.solving(self)
        result = sum([self.f(int(math.pow(3, k))) \
            for k in range(P305.K_LOWER_LIMIT, P305.K_UPPER_LIMIT)])
        Problem.solved(self, result)
        
print '\n' * 50

for ix in range(2, 13):
    P305.K_LOWER_LIMIT = 1
    P305.K_UPPER_LIMIT = ix
    problem = P305()
    problem.solve()