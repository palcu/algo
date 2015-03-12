sizes = {
  'int': 4,
  'char': 1,
  'short': 2
}

def solve(line):
  declaration = line.strip().split(' ')
  if len(declaration) == 3:
    declaration.pop(0)
  variables = declaration[1].split(',')

  sol = 0
  for variable in variables:
    if not '[' in variable:
      sol += sizes[declaration[0]]
    else:
      parts = variable.split('[')
      x = sizes[declaration[0]]
      for part in parts[1:]:
        good_part = part.strip(']')
        x *= int(good_part)
      sol += x
  print sol


while True:
  try:
    line = raw_input()
    solve(line)
  except (EOFError):
    break
