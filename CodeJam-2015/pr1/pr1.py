# https://code.google.com/codejam/contest/6224486/dashboard

def solve(test):
    n, v = test.strip().split()
    shyness = [int(c) for c in v]
    total_spectators, sol = 0, 0
    for index, current_spectators in enumerate(shyness):
        if index and total_spectators < index:
            spectators_to_call = index - total_spectators
            sol += spectators_to_call
            total_spectators += spectators_to_call
        total_spectators += current_spectators
    return sol



with open('A-large.in') as stream:
    lines = stream.readlines()
    for index, test in enumerate(lines[1:]):
        print("Case #{0}: {1}".format(str(index + 1), str(solve(test))))
