import os, sys, string, glob, math

def primes(n):
	if n < 2: return []
	if n == 2: return [2]
	s = range(3, n, 2)
	mroot = n ** 0.5
	half = len(s)
	i = 0
	m = 3
	while m <= mroot:
		if s[i]:
			j = (m * m - 3)//2
			s[j] = 0
			while j < half:
				s[j] = 0
				j += m
		i = i + 1
		m = 2 * i + 3
	return [2]+[x for x in s if x]
	
import p25
#import p14
#import p13
#import p2
#import p3
#import p5
#import p3
#import p4
#import p8	
#import p53

