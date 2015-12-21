f = open('input.in')
def verify(v):
    state = val = 0
    for i in v:
        if i != 0 and state == 0:
            val = i
            state = 1
        if i == 0 and state == 1:
            state = 2
        if (i != val and state == 1) or (i > 0 and state == 2):
            return False
    return True
for _ in range(int(f.readline()[:-1])):
    m = [ ]
    for i in range(int(f.readline()[:-1])):
        m.append([1 if j == '#' else 0 for j in f.readline()[:-1]])
    ok = True
    for i in range(len(m)):
        m[0] = map(sum, zip(m[0], m[i]))
        if not verify(m[0]):
            print "Case #%s: NO" % (_ + 1)
            ok = False
            break
    if ok and len(filter(None, m[0])) != [x for x in m[0] if x != 0][0] - 1:
        print "Case #%s: NO" % (_ + 1)
    elif ok:
        print "Case #%s: YES" % (_ + 1)
