#include <cstdio>

int v[100001], w[100001], z[100001];

int main()
{
	freopen("album.in","r",stdin);
	freopen("album.out","w",stdout);
	
	int i,j,n,poz0=0,htc=0;
	
	scanf("%d",&n);
	for (i=1; i<=n; ++i)
	{
		scanf("%d",&v[i]);
		z[v[i]]=i;
	}
	for (i=1; i<=n; ++i)
		scanf("%d",&w[i]);
	poz0=z[0];
	
	for (i=1; i<n; ++i)
	{
		if (w[poz0])	//daca nu e 0
		{
			//printf("%d: %d -> %d\n",w[poz0],z[w[poz0]],poz0);
			v[poz0]=w[poz0];
			v[z[w[poz0]]]=0;
			poz0=z[w[poz0]];
			++htc;
		}
		else
		{
			for (j=1; j<=n; ++j)
				if (v[j]!=w[j] && w[j])
				{
					//printf("%d: %d -> %d\n",v[j],j,poz0);
					z[v[j]]=poz0;
					v[poz0]=v[j];
					v[j]=0; poz0=j;
					++htc; --i;
					break;
				}
		}
	}
	printf("%d",htc);
	return 0;
}
