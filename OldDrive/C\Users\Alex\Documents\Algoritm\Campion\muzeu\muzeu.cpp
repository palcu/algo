#include <cstdio>
using namespace std;
int main()
{
	freopen("muzeu.in","r",stdin);
	freopen("muzeu.out","w",stdout);
	int n,k,a,b,i,d=0;
	scanf("%d%d",&n,&k);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&a,&b);
		if (b>=d)
			d=b;
		else
		{
			if (a>=d-b)
				d=b;
			else
				d=d-a;
		}
	}
	printf("%d",k-d);
	return 0;
}
