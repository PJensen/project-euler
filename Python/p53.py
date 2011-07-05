import time, math
	
def fact(n):
	retVal = 1
	if (n == 0 or n == 1):
	    return retVal
	r = range(1, n + 1)
	for i in r:
		retVal *= i
	return retVal

# How many values of C(n,r), for 1 ≤ n ≤ 100, exceed one-million?
class C:
    def __repr__(self):
		return self.value
    def __str__(self):
        return 'C(' + str(self.n) + ',' + str(self.r) + ') := ' + str(self.value)
    # 0 <= r <= n
    def __init__(self, n, r):
        self.n = n
        self.r = r
        rFact = fact(self.r)
        nFact = fact(self.n)
        nMinusRFact = fact(self.n - self.r)
        self.value = nFact / (rFact * nMinusRFact)
tStart = time.time()
count = 0
for n in range(1, 100 + 1):        
    for r in range(1, n + 1):
    	if C(n, r).value > 1000000 and (r <= n):
    	    count += 1
print abs(tStart - time.time())
print count


d = str(fact(10))
print d
s = 0
for c in d:
    s += int(str(c))
print s