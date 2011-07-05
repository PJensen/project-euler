g = lambda aStr: aStr == aStr[::-1]
dig3 = range(100, 1000)
s = set()
for x in dig3:
    for y in dig3:
        s.add(x * y)
d = []
for i in s:
    if (g(str(i))):
    	d.append(i)
print max(d)

print filter(lambda x: x % 3 == 0, range(1, 100))
print map(lambda x: x * x, range(1, 101))
print reduce(lambda x, y: x + y, range(1, 101))