x = int(input())

if (x % 2 == 1 or x < 4):
    print(0)
else:
    half = x//2
    if (half % 2 == 0):
        print(half//2-1)
    else:
        print((half-1)//2)
