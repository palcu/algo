#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	freopen("sir.in","r",stdin);
	freopen("sir.out","w",stdout);
	int n,nr=0,i=0,x,j,rad,prim;
	scanf ("%d",&n);
	while (nr!=n)
	{
		x=10*i+7; rad=sqrt(x); prim=1;
		for (j=3; j<=rad && x%j!=0; j+=2);
		if (x%j==0) prim=0;
		if (prim==1) nr++;
		i++;
		
	}
	printf("%d ",x);	
	return 0;
}