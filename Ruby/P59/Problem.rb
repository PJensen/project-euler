
##
# Author:: PJensen (mailto:jensen.petej@gmail.com)
# Copyright:: Copyright (c) 2011 Pete Jensen All Rights Reserved
# License::   Distributes under the same terms as Ruby.
##
class Problem

   attr_reader :problem_answer
   attr_reader :problem_number

   # Initializes a new problem with the given problem number.
   def initialize(aProblemNumber)
      if aProblemNumber.kind_of?(Integer)
         @problem_number = aProblemNumber
         @problem_answer = nil
         puts 'Initialized Problem ' + @problem_number.to_s
      else
         raise "Argument Error"
      end
    end

   # 
   def solving(&m)
   end
    
   # problem solved, pass answer.
   def solved(ans)

   end

   # returns a string representation of this problem
   def to_s
      '(Problem: %s)' % self.problem_number
   end
end


##
# Problem
#class Problem:
#    def __init__(self, number):
#        self.__number = number
#        self.__tStart = None
#        print 'Initialized Problem ' + str(self.__number)
#        
#    def solving(self):
#        print 'Solving Problem ' + str(self.__number)
#        self.__tStart = time.time()##
#
#    def solved(self, ans):
 #       print 'Solved Problem ' + str(self.__number) + ' in ' +\
  #            str(abs(self.__tStart - time.time())) + ' seconds!'
   #     print 'The answer is: ' + str(ans)
