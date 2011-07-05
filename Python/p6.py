
nMax = 100
nSet = range(1, nMax + 1)
def sqr(n):
    return n ** 2
print sum(nSet) ** 2 - sum(map(sqr, nSet)) 	