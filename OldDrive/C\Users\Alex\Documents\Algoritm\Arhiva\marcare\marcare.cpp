#include <cstdio>
using namespace std;
int main()
{
	freopen("marcare.in","r",stdin);
	freopen("marcare.out","w",stdout);
	int n,s,k,nr=0,i,ok,a[254],b[254];
	scanf("%d%d%d",&n,&s,&k);
	for (i=0;i<n;i++)
		a[i]=i+1;
	
	for (i=0;i<n;i++)
		b[i]=0;
	ok=1;
	while (ok)
	{
		if (b[s-1]==1)
			ok=0;
		else
		{
			printf("%d ",a[s-1]);
			b[s-1]=1;
			s+=k;
			if (s>n)
				s=s-n;
		}
	}
	for (i=0;i<n;i++)
	{
		if (b[i]==0)
			nr++;
	}
	printf("\n%d",nr);
	return 0;
}
