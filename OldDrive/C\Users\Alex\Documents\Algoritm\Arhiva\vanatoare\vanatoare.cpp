#include <cstdio>
using namespace std;
int main()
{
	freopen("vanatoare.in","r",stdin);
	freopen("vanatoare.out","w",stdout);
	int ka,kb,nr=0;
	int a=1,b=1,c;
	scanf("%d%d",&ka,&kb);
	while ((ka>=b/2+b%2)&&(kb>=b/2))
	{
		nr++;
		ka-=(b+1)/2;
		kb-=b/2;
		c=a+b;
		a=b; b=c;
	}
	printf("%d\n",nr);
	printf("%d\n",ka);
	printf("%d",kb);
	return 0;
}
