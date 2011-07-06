import time
##
# @File: p55.py
# @Author: PJensen
# @Version: Oct 31, 2010
# @Description: Find the numberof Lychrel numbers below 10k.
##
def fast_lychrel(n):
	N_MAX = 50
	tmp = 0; c = n
	for index in range(1, N_MAX + 1):
		tmp = int(c) + int(str(c)[::-1])
		if (str(tmp) == (str(tmp)[::-1])):
			return 0
		c = tmp
	return 1
tStart = time.time()
# display answer and execution time
print ('%s in %s seconds') % \
	(sum([fast_lychrel(x) for x in range(0, 10000)]), \
	time.time() - tStart)


#121 + 121 = 
#print fast_lychrel(121)
#assert(fast_lychrel(349) == 3)
#assert(fast_lychrel(1292) == 2)
#assert(fast_lychrel(4213) == 1)
#assert(fast_lychrel(10677) == 0)

#assert(fast_lychrel(349) == 3)

#print fast_lychrel(349)
#rint fast_lychrel(50)

#50 + 50 = 100
#100 + 1 = 101



#print fast_lychrel(4994)
#print sum([fast_lychrel(x) for x in range(1, 10000)])

class lychrel:
	def __init__(self, n):
		self.__MAX_ITER = 500
		self.__current_iter 
		self.n = n
		self.a = self.compute(n)
	def __repr__(self):
		return str(self.n) + ', ' + \
		str(self.a) + ', ' + str(self.__current_iter)
	def compute(self, c1):
		print '\t' + str(c1),
		if (self.__current_iter >= self.__MAX_ITER):
			return None
		self.__current_iter += 1
		c2 = int(str(c1)[::-1])
		dx = int(c1) + int(c2)
		print c1, c2
		if (str(dx) == str(dx)[::-1]):
			return dx
		else:
			return self.compute(dx)

#print lychrel(349)
#print lychrel(1292)
#print lychrel(4213)
#print lychrel(3124)
#print lychrel(7337)
#print lychrel(196)
#print lychrel(10677)
#print lychrel(4994)

if False:
	N_MAX = 10000
	total = 0
	for i in range(0, N_MAX + 1):
		L = lychrel(i)
		if (L.a <> None):
			total += 1
	print total
