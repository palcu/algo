#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
    freopen("cifre1.in","r",stdin);
	freopen("cifre1.out","w",stdout);
	int n,n2,nrcif=0,i,multiplu=9;
	long int x=0;
    scanf("%d",&n); 
	if (n>9)
	{
	n2=n;
	while (n2/10!=0)
	{
		nrcif++;
		n2/=10;
	}
	for (i=1;i<=nrcif;i++)
	{
		x+=multiplu*i;
		multiplu*=10;
	}
	x+=(n-pow(10,nrcif)+1)*(nrcif+1);
	}
	else (x=n);
	printf("%d",x);	
	return 0;
}

