#include <cstdio>

int p[101];

int main()
{
	freopen ("submit.in","r",stdin);
	freopen ("submit.out","w",stdout);
	
	int n,i,j,m,b,s,x,bonus,max;
	scanf("%d",&n);
	for (i=1; i<=n; ++i)
		scanf("%d",&p[i]);
	scanf("%d%d",&b,&m);
	
	for (i=1; i<=m; ++i)
	{
		s=0;
		bonus=1;
		for (j=1; j<=n; ++j)
		{
			scanf("%d",&x);
			if (x)	s+=p[j];
			else bonus=0;
		}
		if (bonus) s+=b;
		s-=(i-1)*2;
		if (s>max) max=s;
	}
	
	printf("%d",max);
	return 0;
}
