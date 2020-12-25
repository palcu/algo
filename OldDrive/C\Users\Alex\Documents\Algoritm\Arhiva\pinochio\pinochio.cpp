#include <cstdio>
using namespace std;
int main()
{
	freopen("pinochio.in","r",stdin);
	freopen("pinochio.out","w",stdout);
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	n+=(k/7)*(5*p-2);
	k%=7;
	switch (k)
	{
		case 6: n+=(k-1)*p-1; break;
		default: n+=k*p; break;
	}
	printf("%d",n);	
	return 0;
}
