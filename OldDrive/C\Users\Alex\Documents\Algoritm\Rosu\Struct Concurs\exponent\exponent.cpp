#include <cstdio>
using namespace std;
int main()
{
	freopen("exponent.in","r",stdin);
	freopen("exponent.out","w",stdout);
	int n,k,nr=0;
	int i,i2;
	scanf("%d%d",&n,&k);
	for (i=1; i<=n; i++)
	{
		i2=i;
		while (i2%k==0)
		{
			nr++;
			i2/=k;
		}
	}
	printf("%d",nr);
	return 0;
}
