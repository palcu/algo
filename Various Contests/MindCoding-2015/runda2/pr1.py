def solve(line):
  x, y, z = line.strip().split()
  if x == "0" and y == "0" and z == "0":
    return False
  x = x.replace(y, z)
  x = list(x)
  while len(x) and x[0] == "0":
    x.pop(0)
  if not len(x):
    x = 0
  else:
    x = "".join(x)
  print x
  return True

while True:
  value = raw_input()
  c = solve(value) # next line was found
  if c == False:
    break
