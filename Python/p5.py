# 2520 is the smallest number that can be divided by each 
# of the numbers from 1 to 10 without any remainder.
#
# What is the smallest positive number that is evenly divisible 
# by all of the numbers from 1 to 20?
import time; tStart = time.time()
done = False; n = 22; M_RANGE = 20 
f = lambda g: [(g * 1.0 % dx) for dx in range(1, M_RANGE + 1)]
while not done:
    done = sum(f(n)) == 0; n += 1
print n - 1, tStart - time.time()
