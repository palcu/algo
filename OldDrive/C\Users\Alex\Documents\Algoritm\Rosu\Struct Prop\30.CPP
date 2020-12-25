#include <iostream.h>
void main()
{
int n,i=0,a=0,b=1;
cin>>n;
while (i!=n)
{
if ((a+b)%n==0)
	{
	cout<<a<<" "<<b<<endl;
	i++;
	}
a++; b++;
}
}