#include <iostream.h>
#include <math.h>
void main()
{
int n,i,x,a=0,prim=1,rad;
cin>>n;
for (i=1; i<=n; i++)
{
	cin>>x;
	a=a*10+x%10;
}
if (a==1) prim=2;
else
if (a%2==0)
	if (a!=2) prim=0;
else
{
	rad=sqrt(a);
	for (i=3; i<=rad; i+=2)
	{
		if (a%i==0)
		{
			prim=0;
			break;
		}
	}
}
if (prim==1)
	cout<<a<<" este prim"<<endl;
else cout<<a<<" nu este prim"<<endl;
}