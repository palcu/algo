#include <cstdio>
#include <algorithm>
int b[1001], e[8];
int main()
{
	freopen("loto.in","r",stdin);
	freopen("loto.out","w",stdout);
	
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;++i)	scanf("%d",&b[i]);
	for (i=1;i<=6;++i)	scanf("%d",&e[i]);
	
	std::sort(b+1,b+n+1);
	std::sort(e+1,e+7);
	
	for (i=1; i<=n; ++i)
	{
		if (b[i]==e[1])
		{
			if (i==1)
				e[1]=b[i+1];
			else
			{
				if (b[i-1]-b[i]<b[i+1]-b[i])
					e[1]=b[i-1];
				else
					e[1]=b[i+1];
			}
			break;		
		}
	}
	
	for (i=n; i>0; --i)
	{
		if (b[i]==e[6])
		{
			if (i==n)
				e[6]=b[n-1];
			else
			{
				if (b[i-1]-b[i]<b[i+1]-b[i])
					e[1]=b[i-1];
				else
					e[1]=b[i+1];
			}
			break;		
		}
	}
	for (i=1; i<=7; ++i)
		printf("%d ",e[i]);
	
	return 0;
}
