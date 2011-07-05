
$g_cur = 14
$g_max = 0

print 'Woof'
14.upto 1_000_000 do |n|
	tmpVal = nil
	print tmpVal
	while tmpVal != 1
		if n % 2 == 0
			tmpVal = (n * 3) + 1
		else
			tmpVal = (n / 2)
		end
	end
	print tmpVal
	$g_cur += 1
end
