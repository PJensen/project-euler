

s = [1,1]
def fast_fib(n):
    ax = 1
    while (ax < n):
    	s.append(s[-1] + s[-2])
    	ax += 1
	return s[-1]
	
print fast_fib(10)

def fib(n):
    if (n == 1):
        return 1
    elif (n == 2):
        return 2
    else:
        return fib(n - 1) + fib(n - 2)
dx = 100
while len(str(fib(dx))) < 1000:
    dx += 1
    print fib(dx)
print dx