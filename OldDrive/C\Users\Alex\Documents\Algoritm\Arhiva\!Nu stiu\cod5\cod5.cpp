#include <cstdio>
using namespace std;
int main()
{
	freopen("cod5.in","r",stdin);
	freopen("cod5.out","w",stdout);
	
	int n,a[50],i,x,nr=1,ok,aux,j;
	
	scanf("%d%d",&n,&a[0]);
	n--;
	
	for (i=1; i<=n; i++)
	{
		scanf("%d",&x);
		ok=1;
		
		for (j=0; j<nr; j++)
		{
			if (a[j]==x)
			{
				a[
				break;
				
			}
		}
		if (ok==1)
		{
			a[nr]=x;
			nr++;
		}
	}
	
	do
	{
		ok=1;
		for (i=0; i<nr-1; i++)
		{
			if (a[i]>a[i+1])
			{
				aux=a[i+1];
				a[i+1]=a[i];
				a[i]=aux;
				ok=0;
			}
		}
	}
	while (ok==0);
	
	for (i=0; i<nr; i++)
		printf("%d",a[i]);
	
	return 0;
}
