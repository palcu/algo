import itertools
import collections

N = 4
v = [x+1 for x in range(N)]
d = collections.defaultdict(int)

def get_index(l):
    saved_perm = l[:]
    sol = -1
    while l:
        sol += 1
        l2 = []
        el = l.pop(0)
        for i in l:
            if i < el:
                l2.append(i)
            else:
                el = i
        l = l2[:]
    print saved_perm, sol
    return sol

print len(list(itertools.permutations(v)))
for perm in itertools.permutations(v):
    d[get_index(list(perm))] += 1

print d
