# Author::	PJensen (mailto:jensen.petej@gmail.com)
# Copyright:: Copyright (c) 2010 Pete Jensen 
require 'project_euler'

# The problem space
module ProjectEuler::Problem220

	# An instance of the heighway dragon.
	class HeighwayDragon < ProjectEuler::Problem
		A, B = 'aRbFR', 'LFaLb'
		# Initializes the heigway-dragon problem space by setting
		# the string sequence and calling the super constructor.
		def initialize
			# Call superconstructor
			super 220, 'Heighway Dragon'
		
			# Define the inital state of the sequence.
			@sequence = 'Fa'	
		end

		def generate
			@sequence.replace!('a', A)
		end

		# Solve
		def solve
			generate
		end
	end

	a = HeighwayDragon.new()
	a.solve
	
end
