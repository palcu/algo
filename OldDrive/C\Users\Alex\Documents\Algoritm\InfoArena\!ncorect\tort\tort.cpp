#include <cstdio>
using namespace std;
int main()
{
	freopen("tort.in","r",stdin);
	freopen("tort.out","w",stdout);
	long a,b;
	int i,va[2000000000],vb[2000000000];
	
	va[0]=0; vb[0]=0; i=1;
	scanf("%ld%ld",&a,&b);
	while (a!=0)
	{
		va[0]++;
		va[i]=a%10;
		i++;
		a/=10;
	}
	i=0
	while (b!=0)
	{
		vb[0]++;
		vb[i]=b%10;
		i++;
		a/=10;
	}
	va[va[0]+1]=0;
	va[1]++;
	i=1;
	while (va[i]>9)
	{
		va[i]=0;
		va[i+1]++;
		i++;
	}
		
	return 0;
}
