##
# Author:: PJensen (mailto:jensen.petej@gmail.com)
# Copyright:: Copyright (c) 2011 Pete Jensen All Rights Reserved
# License::   Distributes under the same terms as Ruby.
##

require 'problem'

##
# Each character on a computer is assigned a unique code and the preferred standard is 
# ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, 
# and lowercase k = 107.
#
# A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, 
# taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores 
# the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
#
# For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. 
# The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is
# impossible to decrypt the message.
#
# Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the 
# password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance
# for this method is using a sufficiently long password key for security, but short enough to be memorable.
#
# Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher1.txt 
# (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that 
# the plain text must contain common English words, decrypt the message and find the sum of the 
# ASCII values in the original text.
##
class P57 < Problem

   P57_WORDS_DAT = "words.dat"

   P57_CIPHER_DAT = 'cipher.dat'
   P57_CIPHER_DAT_DELIM = ','

   # initializes a new instance of problem #57
   def initialize
      @cipher_size = 0
      @word_list = []
      @cipher_dat = nil
      
      # call super
      super(57)

      # check cipher file
      if not File.file?(P57_CIPHER_DAT)
         raise 'Unabled to find "%s" problem .dat file.' % P57_CIPHER_DAT
      elsif not File.readable?(P57_CIPHER_DAT)
         raise 'The file "%s" was not readable.' % P57_CIPHER_DAT
      end
      
      # check words file
      if not File.file?(P57_WORDS_DAT)
        raise 'Unabled to find "%s" file.' % P57_WORDS_DAT
      end

      # load
      begin
         File.open(P57_CIPHER_DAT, 'r') do |fp|
            @cipher_dat = fp.gets.split(P57_CIPHER_DAT_DELIM)
         end
      rescue => ex
         raise '"%s" was unable to load.' % self.to_s
      end

      # record size
      cipher_size = @cipher_dat.size
      
      # load english words
      begin
        File.open(P57_WORDS_DAT, 'r') do |fp|

           @word_list.push(fp.gets) 
        end
      rescue => ex
        raise 'unable to load %s' % P57_WORDS_DAT
      end

      puts @word_list.size
   end

   # try a given word.
   def decode_encode(rot)
      #         yield (aRot.rotate.next ^ ch.to_i).chr
      #
      puts "decode_encode. #{rot.word}"

      i = rot.rotate
      @cipher_dat.each do |ch|
      end
   end
   
   # solve
   def solve
      super
      @word_list.each do |w|
         decode_encode(CipherRotator.new(w))
      end
   end

   # A cipher rotator
   class CipherRotator
      attr :word
      def initialize(aWord)
         @cipher_mod_rotator = 1
         @word = aWord
      end
      def reset
         @cipher_mod_rotator = 1
      end
      def rotate
      end
   end
end

p57 = P57.new()
p57.solve()


