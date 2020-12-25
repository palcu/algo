#include <cstdio>
#define max 10
using namespace std;
int main()
{
	freopen("cifre3.in","r",stdin);
	freopen("cifre3.out","w",stdout);
	int a,b,v[max],va[max],vb[max];
	int i;
	scanf("%d%d",&a,&b);
	for (i=0; i<10; i++)
	{
		v[i]=0;
		va[i]=0;
		vb[i]=0;
	}
	while (a)
	{
		va[a%10]++;
		a/=10;
	}
	while (b)
	{
		vb[b%10]++;
		b/=10;
	}
	for (i=0; i<10; i++)
	{
		if (va[i]&&vb[i])
			printf("%d ",i);
	}
	printf("\n");
	for (i=9; i>=0; i--)
	{
		while (va[i])
		{
			printf("%d",i);
			va[i]--;
		}
		while (vb[i])
		{
			printf("%d",i);
			vb[i]--;
		}
	}
	return 0;
}
