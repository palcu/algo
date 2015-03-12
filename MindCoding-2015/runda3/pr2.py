from pprint import pprint

n, m, h = [int(x) for x in raw_input().strip().split()]

matrix = []
xorin = []
xorinna = []

def process_line(line):
    v = []
    for c in line:
        if c == '.':
            v.append(0)
        else:
            v.append(1)
    return v

for i in range(n):
    matrix.append(process_line(raw_input().strip()))

for i in range(h):
    xorin.append(process_line(raw_input().strip()))

for i in range(h):
    xorinna.append(process_line(raw_input().strip()))

maxim_pe_randuri = [sum(x) for x in zip(*xorin)]
maxim_pe_coloane = [sum(x) for x in zip(*xorinna)]
maxim_pe_coloane.reverse()
# print maxim_pe_randuri
# print maxim_pe_coloane

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j]:
            matrix[i][j] = maxim_pe_randuri[j]

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j]:
            matrix[i][j] = min(matrix[i][j], maxim_pe_coloane[i])

s = ''
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j]:
            s += str(matrix[i][j])
        else:
            s += '.'
    s += '\n'
print s
