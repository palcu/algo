from operator import itemgetter
from pprint import pprint

f = open('input.in')
for _ in range(int(f.readline())):
    [nPlayers, nMinutes, teamNo] = [int(x) for x in f.readline().split(' ')]
    players = []
    for player in range(nPlayers):
        [name, shot, height] = f.readline().split(' ')
        players.append({
            'name': name,
            'shot': int(shot),
            'height': int(height),
            'mins': 0,
            'draft': 0,
        })
    players = sorted(players, key=itemgetter('shot', 'height'), reverse=True)
    for i,p in enumerate(players):
        p['draft'] = int(i)
    benches = []
    for t in range(2):
        benches.append([x for i,x in enumerate(players) if i%2 == t])

    playing = []
    for t in range(2):
        playing.append(benches[t][:teamNo])
        del benches[t][:teamNo]
#        pprint(playing[t])
#        pprint(benches[t])
#        print
#        print

    for m in range(nMinutes):
        # print m
        for t in range(2):
            for x in playing[t]:
                x['mins'] += 1
            playing[t].sort(key=itemgetter('mins', 'draft'), reverse=True)
            benches[t].sort(key=itemgetter('mins', 'draft'))
            if len(benches[t]):
                playing[t][0], benches[t][0] = benches[t][0], playing[t][0] 
 #            pprint(playing[t])
 #            pprint(benches[t])
 #            print
 #        print

    sol = []
    for team in playing:
        for player in team:
            sol.append(player['name'])
    sol.sort()
    print "Case #%s: %s" % (_+1, ' '.join(sol))


