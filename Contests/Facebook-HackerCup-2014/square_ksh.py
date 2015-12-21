import math;f=open('i');r=f.readline
for _ in range(1,int(r())+1):
  m=[];s=b=0
  for i in range(int(r())):m.append([1 if j=='#' else 0 for j in r()]);s+=sum(m[i])
  a=int(math.sqrt(s))
  while not filter(None,m[0]):m.pop(0)
  x=m[0].index(1)
  b=sum([sum(v[x:x+a]) for v in m[:a]])
  print "Case #%s: %s"%(_,'YES' if b==s else 'NO')
