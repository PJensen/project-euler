import string

a = 'aRbFR'
b = 'LFaLb'

def D(n):
  if (n <= 0):
     return 'Fa'
  else:
     return D(n - 1).replace('a', a)
     return D(n - 1).replace('b', b)

print D(1)
s = D(1)

i = []
O = {0:'N', 90:'E', 180:'S', 270:'W'}

x = 0; y = 0; o = 0
d1 = []

print s
print 
print 'D(2) := FaRbFRRLFaLbFRa'

for c in s:
   print c,
   if (c == 'F'):
       d1 = []
       print ' => ' + O[o % 360]
   else:
      if (c == 'R'):
         o += 90
      if (c == 'L'):
         o -= 90

print i
