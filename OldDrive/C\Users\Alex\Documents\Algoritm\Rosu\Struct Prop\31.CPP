#include <iostream.h>
void main()
{
int n,n2,n3=0;
cin>>n;  
n2=n;
while (n2!=0)
{
	n3=n3*10+n2%10;
	n2/=10;
}
if (n==n3)
	cout<<n%100;
else
	cout<<n3%10;
}
