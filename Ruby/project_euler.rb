# Author::	PJensen (mailto:jensen.petej@gmail.com)
# Copyright:: Copyright (c) 2010 Pete Jensen 
module ProjectEuler

	# The base Problem class, all problems inherit from this class.
	class Problem

		# accessor for both problem number and description.
		attr_reader :number, :description

		# Initializes the problem given it's number and short description.
		# Params:
		# - pNumber: The problem number for this problem.	
		# - pDescription: A short description of this problem.
		def initialize(pNumber = -1, pDescription = '')
			@description = pDescription
			@number = pNumber
			@start_time = nil
		end

		private

		# The problem is starting
		def problem_start
			@start_time = Time.new
		end

		# The problem is stopping.
		def problem_stop
			@end_time = Time.new
		end
	
		public

		# Various problems implement their own run methods, ideally the proc
		# points to solve.
		def run(&p)
			problem_start
			p.call
			return problem_stop
		end
	
		protected

		# Various problems must implement their own solve methods.
		def solve
			raise 'Solve method not implemented.'
		end
	end
end
