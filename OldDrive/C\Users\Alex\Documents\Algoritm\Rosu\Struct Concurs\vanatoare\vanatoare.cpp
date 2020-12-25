#include <cstdio>
using namespace std;
int main()
{
	freopen("vanatoare.in","r",stdin);
	freopen("vanatoare.out","w",stdout);
	int ka,kb,nr=0;
	int a,b,c;
	scanf("%d%d",&ka,&kb);
	a=0; b=1;
	while ((ka>0)&&(kb>0))
	{
		c=a+b;
		nr++;
		ka-=(c+1)/2;
		kb-=c/2;
		a=b; b=c;
	}
	printf("%d\n",nr-1);
	printf("%d\n",ka+(b+1)/2);
	printf("%d",kb+b/2);
	return 0;
}
