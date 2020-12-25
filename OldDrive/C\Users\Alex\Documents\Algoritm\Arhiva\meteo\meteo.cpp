#include <cstdio>
#include <algorithm>
using namespace std;
int v[100000];
int main()
{
	freopen ("meteo.in","r",stdin);
	freopen ("meteo.out","w",stdout);
	
	int n,i,p,mn=0,mp=0,nr,n2,p2;
	scanf("%d%d%d",&n,&p,&nr);
	for (i=1; i<=nr; ++i)
		scanf("%d",&v[i]);
	sort(v+1,v+nr+1);
	n2=n;
	for (i=1; i<=n2; ++i)
		if (v[i]!=v[i+1])
			mn+=v[i];
		else
			++n2;
	mn/=n;
	p2=p;
	for (i=nr; i>nr-p2; --i)
		if (v[i]!=v[i-1])
			mp+=v[i];
		else
			++p2;
	mp/=p;
	printf("%d %d",mn,mp);
	
	return 0;
}
