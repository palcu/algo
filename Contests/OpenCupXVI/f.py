m = [ [-1]*10 for i in range(10) ]

x = 1
ret = 0
m[1][1] = 0

def get_first_digit(x):
    while (x>9):
        x//=10
    return x

for _ in range(200):
    x *= 2
    ret += 1
    last = x%10
    first = get_first_digit(x)
    if m[first][last] < 0:
        m[first][last] = ret

[a, b] = [int(k) for k in input().split()]
print(m[a][b])
