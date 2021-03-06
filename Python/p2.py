import os, sys, string, glob

# Each new term in the Fibonacci sequence is 
# generated by adding the previous two terms. By starting with 1 
# and 2, the first 10 terms will be:
# 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
#
# Find the sum of all the even-valued terms in the sequence which 
# do not exceed four million.
def fib(n):
    if (n == 1):
        return 1
    elif (n == 2):
        return 2
    else:
        return fib(n - 1) + fib(n - 2)
l = map(fib, range(1, 35))
a = []
for i in l:
    if (i % 2) == 0 and i < 4000000:
        a.append(i)
print sum(a)
