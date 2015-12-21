v = "a I U v o b I I i i c I ( i c d I ( i c e I U i c f I I i u g I ( i c h S S i c i I U v o j S S i c k I ( i c l D H v o m I I i i n I ( i c o - C i o p I I i i q o - i i r I ( i c s I ( i c t S S i c u - C i c v I I i u w o - i i x S S i c y I ( i c z I ( i c"

m = [""] * 26
d = {}
for i in range(26): m[i]= v[i*10:i*10+9]
for i in m: d.update({i[0]: i[2:]})

f = open('plm.txt', 'r')

words = []

for line in f:
    words.append(line)

converted = []
for word in words:
    cv = ""
    for lit in word[:-1]:
        cv += d[lit] + ' '
    cv = cv[:-1]
    converted.append(str(cv))

dcon = {}
for word in words:
    cv = ""
    for lit in word[:-1]:
        cv += d[lit] + ' '
    cv = cv[:-1]
    if cv in dcon:
        dcon[cv].append(word[:-1])
    else:
        dcon[cv] = [word[:-1]]

f = open('test.in', 'r')
for test in f:
    test = str(test[4:-1])
    sol = dcon[test]
    m = ""
    m += str(len(sol)) + ' '
    for i in reversed(sol):
        m += i + ' '
    print m

#cnv = []
#for line in f;
#    cnv.append(line)

