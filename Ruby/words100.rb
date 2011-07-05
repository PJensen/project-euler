
require 'rubygems'
require 'linguistics'

Linguistics::use(:en)

#totalLength = 0

#for i in (1..1000) 
#   totalLength += i.en.numwords.gsub(/(\s|-)/, '').length
#end

#puts(totalLength)

#puts (1..1000).map { |i| i.en.numwords.gsub(/\s|-/, '') }.inject(0) { |sum, w| sum + w.size }

require 'active_support/all'
puts (1..1000).map { |i| i.en.numwords.gsub(/\s|-/, '') }.inject(0, &:size)
