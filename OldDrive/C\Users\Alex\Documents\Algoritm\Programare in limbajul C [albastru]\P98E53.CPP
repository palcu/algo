#include <iostream.h>
#include <math.h>
void main()
{
int n,i,x,j,nr,nrmax=0;
cin>>n;
for (i=1;i<=n;i++)
{
	cin>>x; nr=0; j=3;

	if (x%2==0) nr++;
	while (x%2==0) x/=2;

	while (x!=1)
	{
		if (x%j==0)
		{
			nr++;
			x/=j;
		}
	j+=2;
	}
	if (nr>nrmax) nrmax=nr;
}
cout<<nrmax<<endl;
}


