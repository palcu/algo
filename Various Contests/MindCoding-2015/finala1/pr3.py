people, days = [int(i) for i in raw_input().strip().split()]
groups = people / 4
sol = "("
solutii_grupuri = []
for no_group in range(groups-1):
    v = []
    for i in range(people-3-no_group*4):
        x1 = i+1
        x2 = i+2
        if x1 % 2 == 0:
            x1 /= 2
        else:
            x2 /= 2
        v.append(x1*x2)
    print(v)
    solutii_grupuri.append(str(sum(v)))
# print solutii_grupuri
sol += "+".join(solutii_grupuri)
sol += ")^{0}".format(str(days))
print sol
# print len(sol)
