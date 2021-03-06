import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class EllysSortingTrimmer:
    def getMin(self, S, L):
        letters = list(S)
        for i in range(len(S) - L + 1):
            right = len(S) - i
            left = right - L
            letters[left:right] = sorted(letters[left:right])
        letters = letters[0:L]
        return "".join(letters)

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, p1, hasAnswer, p2):
	sys.stdout.write(str("Test ") + str(testNum) + str(": [") + str("\"") + str(p0) + str("\"") + str(",") + str(p1))
	print(str("]"))
	obj = EllysSortingTrimmer()
	startTime = time.clock()
	answer = obj.getMin(p0, p1)
	endTime = time.clock()
	res = True
	print(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
	if (hasAnswer):
		print(str("Desired answer:"))
		print(str("\t") + str("\"") + str(p2) + str("\""))

	print(str("Your answer:"))
	print(str("\t") + str("\"") + str(answer) + str("\""))
	if (hasAnswer):
		res = answer == p2

	if (not res):
		print(str("DOESN'T MATCH!!!!"))
	elif ((endTime - startTime) >= 2):
		print(str("FAIL the timeout"))
		res = False
	elif (hasAnswer):
		print(str("Match :-)"))
	else:
		print(str("OK, but is it right?"))

	print(str(""))
	return res

all_right = True
tests_disabled = False


# ----- test 0 -----
disabled = False
p0 = "ABRACADABRA"
p1 = 5
p2 = "AAAAA"
all_right = (disabled or KawigiEdit_RunTest(0, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = "ESPRIT"
p1 = 3
p2 = "EIP"
all_right = (disabled or KawigiEdit_RunTest(1, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = "BAZINGA"
p1 = 7
p2 = "AABGINZ"
all_right = (disabled or KawigiEdit_RunTest(2, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
p1 = 13
p2 = "ABCDEFGHIJKLM"
all_right = (disabled or KawigiEdit_RunTest(3, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = "GOODLUCKANDHAVEFUN"
p1 = 10
p2 = "AACDDEFGHK"
all_right = (disabled or KawigiEdit_RunTest(4, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 5 -----
disabled = False
p0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
p1 = 21
p2 = "AAAAAAAAABBDDDDDDDEEI"
all_right = (disabled or KawigiEdit_RunTest(5, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 6 -----
disabled = False
p0 = "TOPCODER"
p1 = 3
p2 = "CDT"
all_right = (disabled or KawigiEdit_RunTest(6, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

if (all_right):
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))

else:
	print(str("Some of the test cases had errors."))

# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!
