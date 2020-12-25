#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; ++i)
#define FOR1(a) for (i=1; i<=a; ++i)

struct domino{ int p; int h; };
domino v[1000];
bool z[1000];

int n,a=0,b,bmax=0;
int i,j,i2;
int m=0;	//nr cate au fost doborate


void dobor (int i)
{
	bool ok=1;
	while (n!=m && ok)
		{
			ok=0;
			if (v[i].p+v[i].h>=v[j].p)
			{
				z[j]=1; ++j;
				++b; ++m;
				ok=1;
				dobor(i+1);
			}
		}
	i2=i;
}

int main()
{
	freopen("domino1.in","r",stdin);
	freopen("domino1.out","w",stdout);
	
	
	
	scanf("%d",&n);
	
	FOR1(n)
		scanf("%d%d",&v[i].p,&v[i].h);
	
	FOR1(n)
	{
		if (!z[i])
		{
			z[i]=1;
			++a; ++m; j=i+1; b=1;
			
			dobor(i); i=i2;
			
			if (b>bmax) bmax=b;
		}
	}
	
	printf("%d %d",a,bmax);
	
	return 0;
}
