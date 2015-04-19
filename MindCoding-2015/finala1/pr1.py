INITIAL = 15
x = int(raw_input())
s1, s2 = 0, 0
pas = 0
for i in range(x, 0, -1):
    if pas in [0, 3]:
        s1 += i
    else:
        s2 += i
    pas = (pas + 1) % 4

# print(s1, s2)
print(INITIAL + abs(s1-s2))
