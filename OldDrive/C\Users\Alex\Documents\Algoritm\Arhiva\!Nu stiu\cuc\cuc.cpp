#include <cstdio>
using namespace std;
int main()
{
	freopen("cuc.in","r",stdin);
	freopen("cuc.out","w",stdout);
	long n,i,n2,i2;
	scanf("%ld",&n);
	for (i=n-1; i>0; i--)
	{
		n2=n; i2=i;
		while (n2>0)
		{
			n2-=i2;
			i2--;
		}
		if (n2==0)
			break;
	}
	printf ("%ld",i2-1);
	return 0;
}