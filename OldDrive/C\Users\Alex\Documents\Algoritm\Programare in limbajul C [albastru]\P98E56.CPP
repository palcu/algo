#include <iostream.h>
void main()
{
int n,i,x,x2,d2=0,d5=0;
cin>>n;
for (i=1;i<=n;i++)
{
	cin>>x; x2=x;
	while (x%2==0)
	{
		d2++;
		x/=2;
	}
	while (x%5==0)
	{
		d5++;
		x/=52;
	}
}
if (d2<d5) cout<<d2;
else cout<<d5;
}
