import math;f=open('i');r=f.readline
for _ in range(1,int(r())+1):
  m=[];s=b=0
  for i in range(int(r())):m.append([1 if j=='#' else 0 for j in r()]);s+=sum(m[i])
  a=int(math.sqrt(s))
  while not filter(None,m[0]):m.pop(0)
  l=[i for i,x in enumerate(m[0]) if x];x=l[0];y=l[-1]
  for v in m:
    if a!=sum(v[x:y+1]):break
    else:b+=a
  if a*a!=s or b!=s:print "Case #%s: NO"%_
  else:print "Case #%s: YES"%_
