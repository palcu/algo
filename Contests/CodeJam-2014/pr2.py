def solve():
    [c, f, target] = [float(x) for x in stream.readline().strip().split()]
    current_time = 0.0
    current_speed = 2.0

    while True:
        without_upgrade = target / current_speed
        with_upgrade = c / current_speed + target / (current_speed + f)
        if without_upgrade < with_upgrade:
            return current_time + without_upgrade
        else:
            current_time += c / current_speed
            current_speed += f

with open('B-large.in') as stream:
    tests = int(stream.readline())
    for i in range(tests):
        print("Case #{0}: {1}".format(i + 1, solve()))
