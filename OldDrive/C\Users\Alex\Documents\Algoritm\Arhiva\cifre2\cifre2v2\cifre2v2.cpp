#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	freopen("cifre2.in","r",stdin);
	freopen("cifre2.out","w",stdout);
	int i2,n,c,nrcif=0,n2,x=0,i;
	scanf ("%d%d",&n,&c);
	n2=n;
	while (n2/10!=0)
	{
		n2/=10;
		nrcif++;
	}
	for (i=0; i<nrcif; i++)
		x=x*9+pow(10,i);
	for(i=pow(10,nrcif);i<=n;i++)
	{
		i2=i;
		while (i2!=0)
		{
			if ((i2%10)==c)
				x++;
			i2/=10;				
		}
	}
	
	printf("%d",x);
	return 0;
}
