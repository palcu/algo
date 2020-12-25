#include <cstdio>
using namespace std;
int main()
{
	freopen("efort.in","r",stdin);
	freopen("efort.out","w",stdout);
	int n,k,k2,d,i,j,m1,m2,m3;
	long int s=0;
	scanf("%d%d",&n,&k);
	k2=k;
	for (i=1; i<=n; i++)
	{
		scanf("%d",&d);
		if (d<=k2)
		{
			s+=d;
			k2-=d;
		}
		else
		{
			s+=k2; m1=m2=1;
			for (j=k2; j<d; j++)
			{
				m3=m1+m2;
				s+=m3;
				m1=m2; m2=m3;
			}
			k2=0;
		}
		if (k2==0)
			k2=k;
	}
	printf("%d",s);
	return 0;
}
