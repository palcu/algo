import string
import sys

def check(string):
  # print string
  for i,char in enumerate(string):
    if char != string[-i-1]:
      return False
  return True

def solve(word):
  letters = list(word)
  for i in range(len(word) + 1):
    for letter in string.lowercase:
      tmp = letters[:]
      tmp.insert(i, letter)
      if check(tmp):
        print "".join(tmp)
        sys.exit()

word = sys.stdin.readline()
solve(word.strip())
print 'NA'
