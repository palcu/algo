from collections import defaultdict

points = defaultdict(int)
goals = defaultdict(int)

def add_match(s):
  team1, team2, goals1, goals2 = s.strip().split()
  goals1 = int(goals1)
  goals2 = int(goals2)
  goals[team1] += goals1
  goals[team2] += goals2

  if goals1 > goals2:
    points[team1] += 3
    points[team2] += 0
  elif goals1 == goals2:
    points[team1] += 1
    points[team2] += 1
  else:
    points[team2] += 3
    points[team1] += 0

while True:
  try:
    value = raw_input()
    add_match(value) # next line was found
  except (EOFError):
    break #end of file reached

teams = []
# print points
for k, v in points.iteritems():
  teams.append({'team': k, 'points': v, 'goals': goals[k]})

def comp(t1, t2):
  if t1['points'] != t2['points']:
    if t1['points'] > t2['points']:
      return -1
    return 1
  if t1['goals'] != t2['goals']:
    if t1['goals'] > t2['goals']:
      return -1
    return 1
  if t1['team'][0] != t2['team'][0]:
    if t1['team'][0] > t2['team'][0]:
      return 1
    return -1

teams.sort(cmp=comp)
# print teams
for team in teams:
  print team['team']
