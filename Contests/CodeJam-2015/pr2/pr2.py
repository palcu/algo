import math

def get_pasi(x, i):
    """Numarul de pasi pentru a imparti x in suma de numere mai mici sau egale
    cu i.
    """
    if x <= i:
        return 0

    jumate = x // 2
    cealalta_jumate = x - jumate
    return 1 + get_pasi(jumate, i) + get_pasi(cealalta_jumate, i)



def solve(plates):
    sol = max(plates)
    for i in range(1, max(plates) + 1):
        sol_local = 0
        for plate in plates:
            # import ipdb; ipdb.set_trace()
            sol_local += get_pasi(plate, i)
        sol_local += i
        sol = min(sol, sol_local)
    return sol


with open('B-small-attempt5.in') as stream:
    tests = int(stream.readline().strip())
    for index in range(tests):
        stream.readline()
        plates = [int(x) for x in stream.readline().strip().split()]
        print("Case #{0}: {1}".format(index + 1, solve(plates)))
