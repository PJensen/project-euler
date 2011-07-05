import time, random, sys

f1 = lambda n: (n / 2)
f2 = lambda n: (3 * n) + 1

##
# g of (x) actually generates the full out sequence.
# where m of (x) just counts the length of the sequence
# g should be used when actually trying to get the
# answer
def g(x):
	s = [x];
	current = x;
	for i in range(0, x):
	    if (s[i] == 1):
	        break
	    if (s[i] % 2 == 0):
	        s.append(f1(s[i])); 
	    else:
		    s.append(f2(s[i]));
	return len(s)
	
##
# g of (x) actually generates the full out sequence.
# where m of (x) just counts the length of the sequence
# g should be used when actually trying to get the
# answer
def m(x):
	current = x;
	count = 0;
	for i in range(0, x):
	    if (current == 1):
	        break
	    if (current % 2 == 0):
	        current = (f1(current)); count += 1;
	    else:
		    current = (f2(current)); count += 1
	#print current
	return count + 1
	
#99991
#c_max = 0
#tx = range(1, 774888)[::-1]
#for i in tx:
#    tmpVal = m(i)
#    if (tmpVal > c_max):
#        print i,tmpVal
#        c_max = tmpVal
#    print c_max, i, tmpVal
#print 
#print m(927003)::927003 476
#print m(928931)
#print m(999999)

#sys.exit(1)
#print m(928931)

#print m(837799)

#sys.exit(0)

#ax = {}
#c_max = 0
#while True:
#    for i in range(1, 10):
#        n = int(random.randrange(774888, 1000000))
#        for d in range(1, 10):
#            ax[n] = m(n)
#            if (ax[n] > c_max):
#                print n, ax[n]
#                c_max = ax[n]
#sys.exit(0)
            
			
#while True:
#	for i in range(0, 10):
		#n = int(random.random() * 1000000)
		#dd[n] = m(n)
	#if (max(dd.values() > 400):
#		print dd
		##break
	#dd = {}



pattern = {}
for d in range(10000, 11000, 1):
    nMax = d
    # print 'Start: ',
    tStart = time.time()
    print "Running, ", d, 
    pattern[d] = max(map(g, range(1, nMax)))
    print time.time() - tStart
print pattern.values()

# print 'Start: ',
# tStart = time.time()
# print max(map(g, range(1, nMax)))
# gTime = time.time() - tStart
# print '[end]'
# 01k -> 0.07
# 10k -> 1.99
# 20k -> 6.48
# 50k -> 

# print round((mTime - gTime), 3) 

# print (mTime - gTime / gTime * 1.0) * 100        
# print map(, range(13, 100))
# print filter(lambda x: x % 3 == 0, range(1, 100))
# print map(lambda x: x * x, range(1, 101))
# print reduce(lambda x, y: x + y, range(1, 101))