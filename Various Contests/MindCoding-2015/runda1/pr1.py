test = int(raw_input())

def is_consec(s):
    # print s
    for i in range(3):
        # print ord(s[i+1])
        if ord(s[i]) + 1 != ord(s[i+1]):
            return False
    return True

def is_power_2(num):
    # print num
    return num != 0 and ((num & (num - 1)) == 0)

def se_poate_transforma(s):
    return s[0] != '0'

def solve():
    time = raw_input().strip()
    h, m = time.split(':')
    # print h+m
    if not (0 <= int(m) < 60):
        return 'NO'
    if not (0 <= int(h) < 24):
        return 'NO'
    if m == "00":
        return 'YES'
    if h == m[::-1]:
        return 'YES'
    if h == m:
        return 'YES'
    if se_poate_transforma(h+m) and is_power_2(int(h+m)):
        return 'YES'
    if is_consec(h + m):
        return 'YES'
    return 'NO'

for _ in range(test):
    print solve()
