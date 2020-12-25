#include <iostream.h>
#include <math.h>
void main()
{
int n,a,b,c,i,rad;
cin>>n;
for (i=1;i<=n;i++)
{
	if (n%i==0)
	{
		rad=sqrt(i);
		for (a=1;a<=rad;a++)
			for (b=0;b<=rad;b++)
				for (c=0;c<=rad;c++)
				if (i==a*a+b*b+c*c) cout<<a<<b<<c<<endl;
	}
}
}
