require 'matrix'

m = Matrix[[131, 673,234, 103, 18], 
	   [201, 96, 342, 965, 150], 
           [630, 803,746, 422, 111], 
           [537, 699,497, 121, 956], 
           [805, 732,524, 37,  331]]

m_x, m_y = 0, 0; m_sum = m[0, 0]

def junk(am, ax, ay)
  yield :right, am[ax + 1, ay]
  yield :down, am[ax, ay + 1]
#  yield :down_right, am[ax + 1, ay + 1]
end

# the matrix is square, do either column_size or row_size would do
# either way were looping over a set number of elements that ensures
# we end at m[X_MAX, Y_MAX] (e.g) the bottom right
6.times do |index|
 # puts 'At matrix index ' + index.to_s
  direction = :none; tmpMin = 1000
  junk(m, m_x, m_y) do |sym, val|
    if (val < tmpMin)
      tmpMin = val
      direction = sym
    end
  end
  case direction
    when :right then m_x += 1
    when :down then m_y += 1
  end
  m_sum += tmpMin
  puts tmpMin
#  puts "direction (" + direction.to_s + ") min " + m_sum.to_s
  tmpMin = 1000
end


#puts Matrix.instance_methods


#131	673	234	103	18
#201	96	342	965	150
#630	803	746	422	111
#537	699	497	121	956
#805	732	524	37	331
	
