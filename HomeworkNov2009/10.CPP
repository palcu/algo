#include <iostream.h>
void main()
{
int a,b,n,i,x,sc,nr=0,x2;
float ma=0;
cin>>a>>b>>n;
for (i=1; i<=n; i++)
{
	cin>>x; x2=x; sc=0;
	while (x2!=0)
	{
		sc+=x2%10;
		x2/=10;
	}
	if ((a<=sc)&&(sc<=b))
	{
		ma+=x;
		nr++;
	}
}
ma/=nr;
cout<<ma<<endl;
}