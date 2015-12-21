from math import floor, ceil
n = int(input())
v = [int(x) for x in input().split()]

avg = sum(v) / len(v)
avg_min = floor(avg)
avg_max = ceil(avg)
sol_min, sol_max = 0, 0
for x in v:
    if x <= avg_min:
        sol_min += abs(x - avg_min)
    else:
        sol_max += abs(x - avg_max)
print(max(sol_min, sol_max))
