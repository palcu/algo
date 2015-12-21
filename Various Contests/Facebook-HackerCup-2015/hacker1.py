def solve(number):
  solmin, solmax = int(number), int(number)
  l = list(number)
  for i in range(len(l)):
    for j in range(len(l)):
      temp = l[:] # fucking Python is fucked up
      temp[i], temp[j] = temp[j], temp[i]
      if temp[0] == '0':
        continue # fucking special case
      temp = int("".join(temp))
      solmin = min(solmin, temp)
      solmax = max(solmax, temp)

  return solmin, solmax


with open('hacker1.in') as stream:
  lines = stream.readlines()
  for i, number in enumerate(lines[1:]):
    print "Case #{0}: {1} {2}".format(i+1, *solve(number[:-1]))
