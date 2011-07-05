##
# The following is the a Collatze sequence generator built in Ruby; not the
# greated implementation but it gets the job done.
#
# @Author: PJensen
# @Version: October, 2010
#
##
# The following iterative sequence is defined for the set of positive integers:
#
# n → n/2 (n is even)
# n → 3n + 1 (n is odd)
#
# Using the rule above and starting with 13, we generate the following sequence:
# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
#
# It can be seen that this sequence (starting at 13 and finishing at 1) contains
# 10 terms. Although it has not been proved yet (Collatz Problem), it is thought
# that all starting numbers finish at 1.
#
##  
# Question: 
#
# Which starting number, under one million, produces the longest chain?


## 
# Class: Collatz
# This class or object defines the existence of exactly one collatz sequence
# noting the generating value (:start) and the total number of elements (:count)
# As soon as a new instance is created, the method (compute) is called and
# will calculate the length of the sequence which ends up in (:count)
class Collatz 

	##
   # Allow arbitrary reading of start and count
	attr_reader :start, :count

   ## 
   # Constructor
   # (default parameter removed for clarity)
	def initialize(start)
		if start.kind_of?(Integer)
			@start = start
			@current = start
			@seq = {}
			@count = 0

			# Force computation
			compute
		end
	end

   ##
   # Show the just the details of this Collatz sequence
   # as a string; the sequence is *not* actually shown	
	def to_s
 		"Collatz: #{@start} -> #{@count}\n"
	end
 
   ##
   # Basic support for determining a specific key; 
   # so if you're looking for the nth key use
   # collatz[n]
	def [](key)
		if key.kind_of?(Integer)
         if (key < @seq.length)
   			return @seq[key]
         end
		end
	end 

	private

   ## 
   # This is where the dirty work of actually computing the length
   # of this sequence is done.
	def compute
		while @current != 1
		 	if (@current % 2) == 0
				@current = @current / 2
			else
				@current = (3 * @current) + 1
			end
			@seq[@count] = @current
			@count += 1
		end
		@count += 1
	end
end

# The highest value we'll go up to.
MAXIMUM_GENERATING_VALUE = 1_000_000

# the current longest sequences length, starts at zero.
$c_max = 0

# Might as well just start @ 12 and brute for the thing
# from here on out.
for i in 12 .. MAXIMUM_GENERATING_VALUE

   # Generate a new sequence with (i)
	a = Collatz.new(i)

   # If it's greater than the current max; we'll damn
   # save it and show it off.
	if a.count > $c_max
		$c_max = a.count
		print a
	end
end

# Show the result; last. This is the highest value we found!
print $c_max

