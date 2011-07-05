require 'cx'
require 'test/unit'

class TestCollatz < Test::Unit::TestCase
   def generate_with_thirteen
      tmpSeq = Collatz.new(13)
      assert(10 == tmpSeq.count)
   end
end
