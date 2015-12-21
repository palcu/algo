from collections import defaultdict

n_noduri, n_operatii = [int(x) for x in raw_input().split()]
litere = list(raw_input().strip())
# print n_noduri
graph = [[] for _ in range(n_noduri + 1)]
tati = [0 for _ in range(n_noduri + 1)]
level = [0 for _ in range(n_noduri+1)]
is_visited = [0 for _ in range(n_noduri+1)]

for _ in range(n_noduri-1):
    x, y = [int(x) for x in raw_input().split()]
    graph[x].append(y)
    graph[y].append(x)

for i in range(2, n_noduri+1):
    tati[i] = min(graph[i])

def measure_stuff(x, y):
    counts = [False for _ in range(26)]
    # print x, y
    while x != y:
        if level[x] < level[y]:
            # print x, y
            litera = litere[y-1]
            index = ord(litera) - ord('a')
            # print litera
            counts[index] = not counts[index]
            y = tati[y]
        else:
            # print x, y
            litera = litere[x-1]
            # print litera
            index = ord(litera) - ord('a')
            counts[index] = not counts[index]
            x = tati[x]
    litera = litere[x-1]
    # print litera
    index = ord(litera) - ord('a')
    counts[index] = not counts[index]
    print sum(counts)

def dfs(x, l):
    level[x] = l
    for i in range(1, n_noduri+1):
        if tati[i] == x:
            dfs(i, l+1)


def add(x, c):
    # print x, c
    new_id = len(tati) - 1
    litere.append(c)
    tati.append(x)
    level.append(level[x] + 1)

is_visited[1] = 1
level[1] = 1
dfs(1, 1)

# print level
for _ in range(n_operatii):
    x, y, z = raw_input().strip().split()
    # print x, y, z
    if x == "1":
        measure_stuff(int(y), int(z))
    else:
        add(int(y), z)

# print tati
# print level
