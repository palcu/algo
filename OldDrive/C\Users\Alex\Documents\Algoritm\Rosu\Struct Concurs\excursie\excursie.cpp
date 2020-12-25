#include <cstdio>
using namespace std;
int main()
{
	freopen("excursie.in","r",stdin);
	freopen("excursie.out","w",stdout);
	int n,h,d,smax=0;
	int h0=0,s=0,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&h,&d);
		if (h0>=h)
			s+=d;
		else
		{
			if (s>smax)
				smax=s;
			s=0;
		}
		h0=h;
	}
	printf("%d",smax);
	return 0;
}
