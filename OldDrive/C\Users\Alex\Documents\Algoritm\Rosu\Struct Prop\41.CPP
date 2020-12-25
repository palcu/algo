#include <iostream.h>
void main()
{
int n,i,x,x2,max,dmax=0,nrdiv,j;
cin>>n;
for (i=1; i<=n; i++)
{
	cin>>x; x2=x/2; nrdiv=2;
	for (j=2; j<=x2; j++)
		if (x%j==0) nrdiv++;
	if (nrdiv>dmax)
	{
		dmax=nrdiv;
		max=x;
	}
}
cout<<max;
}