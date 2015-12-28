n = int(input())
v = [int(x) for x in input().split()]
low = min(v)

res = low * n
v = [x-low for x in v]
v *= 2

start = -1
sol = 0

for i, x in enumerate(v):
    if x != 0:
        if start < 0:
            start = i
    else:
        if start >= 0:
            sol = max(sol, i-start)
            start = -1

res += sol
print(res)
