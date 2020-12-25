#include <cstdio>
using namespace std;
int main()
{
	freopen("gardul.in","r",stdin);
	freopen("gardul.out","w",stdout);
	int n,p,q,i,nr0=0,nrr=0,nra=0,nrv=0;
	scanf("%d%d%d",&n,&p,&q);
	for (i=1;i<=n;i++)
	{
		if ((i%p==0)&&(i%q==0))
			nrv++;
		else
		{
			if (i%p==0)
				nrr++;
			else
			{
				if (i%q==0)
					nra++;
			}
		}
	}
	nr0=n-nrv-nrr-nra;	
	printf("%d\n%d\n%d\n%d",nr0,nrr,nra,nrv);	
	return 0;
}
