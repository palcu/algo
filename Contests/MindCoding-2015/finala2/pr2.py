from pprint import pprint

n = int(raw_input())
m = []

def my_nice_print(m):
    s = ''
    for line in m:
        for c in line:
            s += str(max(c['nedef'], c['right'], c['left'])) + ' '
        s += '\n'
    print s

for i in range(n):
    m.append([int(j) for j in raw_input().strip().split()])

sol = [[{} for _ in range(n)] for __ in range(n)]
for i in range(n):
    for j in range(n):
        sol[i][j]['nedef'] = m[i][j]
        sol[i][j]['left'] = m[i][j]
        sol[i][j]['right'] = m[i][j]

for i in range(n):
    if i != 0:
        for j in range(n):
            sol[i][j]['nedef'] = max(m[i][j], sol[i-1][j]['nedef']+m[i][j])
            sol[i][j]['right'] = max(m[i][j], sol[i-1][j]['nedef']+m[i][j], sol[i-1][j]['left']+m[i][j])
            sol[i][j]['left' ] = max(m[i][j], sol[i-1][j]['nedef']+m[i][j], sol[i-1][j]['right']+m[i][j])
    for j in range(1, n):
        sol[i][j]['left'] = max(sol[i][j]['left'], m[i][j] + sol[i][j-1]['left'], m[i][j] + sol[i][j-1]['nedef'])
    for j in range(n-2, -1, -1):
        sol[i][j]['right'] = max(sol[i][j]['right'], m[i][j] + sol[i][j+1]['right'], m[i][j] + sol[i][j+1]['nedef'])

answer = -2000
for line in sol:
    for j in line:
        answer = max(answer, j['nedef'], j['right'], j['left'])

my_nice_print(sol)
pprint(sol)
print answer
