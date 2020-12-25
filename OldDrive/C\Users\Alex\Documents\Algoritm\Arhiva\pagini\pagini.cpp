#include <cstdio>
using namespace std;
int main()
{
	freopen("pagini.in","r",stdin);
	freopen("pagini.out","w",stdout);
	int a[499],n,i,nr=0,l=1,lmax=0,ok=0,aux;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	do
	{
		ok=1;
		for (i=0; i<n-1; i++)
		{
			if (a[i]>a[i+1])
			{
				aux=a[i];
				a[i]=a[i+1];
				a[i+1]=aux;
				ok=0;
			}
		}
	}
	while (ok==0);
	
	for (i=0; i<n; i++)
	{
		if ((a[i]+1)==a[i+1])
			l++;
		else
		{
			if ((a[i-1]+1)==a[i])
			{
				nr++;
				if (l>lmax)
					lmax=l;
				l=1;
			}
		}
	}
	printf("%d\n%d",nr,lmax);	
	return 0;
}
