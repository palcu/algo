#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	freopen ("la_scoala.in","r",stdin);
	freopen ("la_scoala.out","w",stdout);
	int n,rad,i,j,k;
	scanf ("%d", &n);
	
	if (int(sqrt(n))==sqrt(n))
		rad=sqrt(n)+1;
	else rad=sqrt(n);
	
	k=rad*rad; 
	printf("Premiati = %d\n",n-k);
	for (i=1;i<=rad;i++)
	{	
		for (j=1;j<=rad;j++)
		{
			printf("%d ",k);
			k--;
		}
		printf ("\n");
	}	
	return 0;
}