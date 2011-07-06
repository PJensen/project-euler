import time

##
# @Fle: p74.py
# @Author: PJensen
# @Version: Oct 31, 2010
# @Description: Unoptimized solution for Problem-74.
# http://projecteuler.net/index.php?section=problems&id=74

# n-factorial
# remarks: only needs factorials for digits.
def n_fact(n):
	if (n == 1):
		return 1
	elif (n == 2):
		return 2
	elif (n == 3):
		return 6
	elif (n == 4):
		return 24
	elif (n == 5):
		return 120
	elif (n == 6):
		return 720
	elif (n == 7):
		return 5040
	elif (n == 8):
		return 40320
	elif (n == 9):
		return 362880
	elif (n == 0):
		return 1
#	 n_result = 1
#	 for index in range(1, n + 1):
#		 n_result *= index
#	 return n_result

# n-factorial digit sum
def fact_digit_chain_sum(gen):
	def fact_digit_chain(n):
		for c in str(n):
			yield n_fact(int(c))
	return sum(fact_digit_chain(gen))

# digit sums
def fact_digit_chain_sum_1(gen):
	retVal = 0
	for c in str(gen):
		n = int(c)
		if (n == 1):
			retVal += 1
		elif (n == 2):
			retVal += 2
		elif (n == 3):
			retVal += 6
		elif (n == 4):
			retVal += 24
		elif (n == 5):
			retVal += 120
		elif (n == 6):
			retVal += 720
		elif (n == 7):
			retVal += 5040
		elif (n == 8):
			retVal += 40320
		elif (n == 9):
			retVal += 362880
		elif (n == 0):
			retVal += 1
	return retVal

global m
m = {}

# generate the full non-repeating sequence
# but do not return the full chain
def fact_digit_chain_seq_len(n):
	c = [n]; current = f(n); index = 0
	while current not in c:
		c.append(current)
		current = f(current)
	m[n] = len(c)
	return len(c)

def f(n):
	if (n in m.keys()):
		return m[n]
	else:
		m[n] = fact_digit_chain_sum_1(n)
		return m[n]

# assertion as to the chain length of 69
assert((fact_digit_chain_seq_len(69) == 5))

# declare constant max and start time
N_MAX = 10000; tStart = time.time()

# lc that generates all chains w/ length 60 for generators up to N_MAX
# chains_with_length_60 = [x for x in range(1, N_MAX) if fact_digit_chain_seq_len(x) == 60]

chains_with_length_60 = 0
for current in range(1, N_MAX + 1):
	if fact_digit_chain_seq_len(current) == 60:
		chains_with_length_60 += 1

# show that exact number that meet the above criterion.
print ('chains of length 60 from 0 to %s: %s, calculated in %s') %\
	(N_MAX, str(chains_with_length_60) ,time.time() - tStart)
