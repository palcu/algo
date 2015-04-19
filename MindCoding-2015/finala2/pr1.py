from math import factorial, sqrt

data = {}
data[2] = 1
data[3] = 2
data[4] = 2
data[5] = 4

def is_prim(x):
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x)), 2):
        if x % i == 0: return False
    return True

x = int(raw_input().strip())

if x <= 5:
    print str(data[x])
else:
    if is_prim(x):
        print str(x-1)
    else:
        print "0"
