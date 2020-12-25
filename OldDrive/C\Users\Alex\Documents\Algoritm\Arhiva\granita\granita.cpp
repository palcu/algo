#include <cstdio>
#include <algorithm>

struct segm {int x; int y; bool z;};
segm v[16000];

bool sortare(segm a, segm b)
{
	if (a.x==b.x)
	{
		if (a.y<b.y) return 1; return 0;
	}
	if (a.x<b.x) return 1; return 0;
}

int main()
{
	freopen("granita.in","r",stdin);
	freopen("granita.out","w",stdout);
	
	int n,i,j,htc=0;
	
	scanf("%d",&n);
	for (i=1; i<=n; ++i) scanf("%d%d",&v[i].x,&v[i].y);
	
	std::sort(v+1,v+n+1,sortare);
	
	for (i=1; i<n; ++i)
	{
		if (!v[i].z) for (j=i+1; j<=n && v[i].y > v[j].x; ++j)
			if (!v[j].z) if (v[i].x<v[j].x && v[i].y>v[j].y) {++htc; v[j].z=1;}
	}
	
	printf("%d",htc);
	return 0;
}
