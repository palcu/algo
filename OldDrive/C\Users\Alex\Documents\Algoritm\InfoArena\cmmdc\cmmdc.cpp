#include <cstdio>
using namespace std;
int main()
{
	freopen("cmmdc.in","r",stdin);
	freopen("cmmdc.out","w",stdout);
	int a,b,r;
	scanf("%d%d",&a,&b);
	while (b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	if (a==1)
		printf("0");
	else
	printf("%d",a);
	
	return 0;
}
