#include <cstdio>
#include <cmath>

int v[30000];
int w[30000];

bool prim(int x);
void aranj(int k, int n, int k2);

int main()
{
	freopen("secvente1.in","r",stdin);
	freopen("secvente1.out","w",stdout);
	
	int n,p,k,x=0,a,i=1,folosit;
	char D,DD;
	bool div;
	
	scanf("%d",&D);
	for (DD=1; DD<=D; ++DD)
	{
		//contruim vectorul
		scanf("%d%d%d",&n,&p,&k);
		x=folosit=0; v[0]=1;
		for (i=1; i<=n; ++i)
		{
			scanf("%d",&a);
			div=0;
			if (!(a%p))
				div=1;
			
			if (a!=1)
			{
				if (div)	
					{v[v[0]]=i; ++v[0];}
				else if (prim(a))
					{v[v[0]]=i; ++v[0];}
			}
		}
		
		//afisam secvente (aranjamente)
		--v[0];
		printf("%d\n",v[0]);
		aranj(1,v[0],k);
	}
	
	
	return 0;
}

bool prim(int x)
{
	int i, rad=(int)sqrt(x);
	if (!(x%2))	return 0;
	for (i=3;i<=rad;i+=2)
		if (!(x%i)) return 0;
	return 1;
}

void aranj(int k, int n, int k2)
{
	int i,g,x;
	if (k==k2+1)
	{
		for (i=1; i<=n;++i)	printf("%d",w[i]);
		printf("\n");
	}
	else
		for (x=1;x<=n;++x)
		{
			g=0;
			for (i=1;i<k;++i)
				if (w[i]>=x)
				{
					g=1;
					break;
				}
			if (!g)
			{
				w[k]=x;
				aranj(k+1,n,k2);
			}
		}
}
