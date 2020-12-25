#include <iostream.h>
void main()
{
int a,b,a1=0,b1=0;
cin>>a>>b;
while (a!=0)
{
	if (a%2==1)
		a1++;
	a/=2;
}
while (b!=0)
{
	if (b%2==1)
		b1++;
	b/=2;
}
if (a1>b1) cout<<"a";
else cout<<"b";
}