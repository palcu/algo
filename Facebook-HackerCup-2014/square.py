import math

f = open('input.in')
cases = int(f.readline())

for case in range(cases):
    m = [ ]
    lines = int(f.readline())

    # read and convert the matrix
    s = 0
    for i in range(lines):
        m.append([1 if j == '#' else 0 for j in f.readline()])
        s += sum(m[-1])

    # get what might be the length of a side
    sum_on_a_line = int(math.sqrt(s))
    
    # get first row with a black cell
    while not filter(None, m[0]):
        m.pop(0)
    
    # get left right indices
    l = [i for i, x in enumerate(m[0]) if x]
    left  = l[0]
    right = l[-1] + 1
    
    # sum up the portion of the matrix where the square
    # should be
    new_sum = 0
    for line in m:
        if sum_on_a_line != sum(line[left : right]):
            break
        else:
            new_sum += sum_on_a_line
    
    # test to see if the new_sum equals the old one
    if new_sum == s and sum_on_a_line * sum_on_a_line == s:
        print "Case #%s: YES" % (case + 1)
    else:
        print "Case #%s: NO" % (case + 1)
