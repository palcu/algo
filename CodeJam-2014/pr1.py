def chosen_elements():
    chosen_row = int(f.readline())
    matrix = []
    for i in range(4):
        row = f.readline()
        matrix.append([x for x in row.strip().split()])
    return matrix[chosen_row - 1]

def solve():
    first_elements = chosen_elements()
    second_elements = chosen_elements()

    intersection = list(set(first_elements) & set(second_elements))
    if len(intersection) == 1:
        return intersection[0]
    elif not len(intersection):
        return "Volunteer cheated!"
    else:
        return "Bad magician!"

with open('A-small-attempt1.in') as f:
    tests = int(f.readline())
    for i in range(tests):
        print("Case #{0}: {1}".format(i+1, solve()))
