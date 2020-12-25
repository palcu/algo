#include <cstdio>
#include <cmath>
int main()
{
	freopen("pregen.txt","w",stdout);
	int i,j,nr=0,prim,rad,nr2;
	printf("int a[x]={2,");
	for (i=3; i<=32767; i+=2)
	{
		nr2=nr;
		rad=(int)sqrt(i);
		prim=1;
		for (j=3; j<=rad; j+=2)
		{
			if (i%j==0)
			{
				prim=0;
				break;
			}
		}
		if (prim)
		{
			printf("%d,",i);
			nr++;
		}
		if ((nr%10==0)&&(nr2!=nr))
			printf("\n");
		nr2=nr;
	}
	printf("%d",nr);
}
