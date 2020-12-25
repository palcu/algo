#include <cstdio>
using namespace std;
int main()
{
	freopen("cifre2.in","r",stdin);
	freopen("cifre2.out","w",stdout);
	int n,c,i,i2,nr=0;
	scanf ("%d%d",&n,&c);
	for (i=1;i<=n;i++)
	{
		i2=i;
		while(i2!=0)
		{
			if (c==(i2%10))
				nr++;
			i2/=10;
		}
	}
	
	printf("%d",nr);	
	return 0;
}
