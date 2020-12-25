#include <iostream.h>
void main()
{
int a,b,a2,a3,nr=0;
float ma=0;
cin>>a>>b;
while (a<=b)
{
	a2=a; a3=0;
	while (a2!=0)
	{
		a3=a3*10+a2%10;
		a2/=10;
	}
	if (a3==a)
	{
		ma+=a;
		nr++;
	}
	a++;
}
ma/=nr;
cout<<ma<<endl;
}