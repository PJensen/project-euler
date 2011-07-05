require 'rational'
(1..1000).each do |n|
  f = Rational(1, n)
  puts f.to_f
end
