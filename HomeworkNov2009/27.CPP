#include <iostream.h>
void main()
{
int c;
long int n, n2=0;
cin>>n;
while (n!=0)
{
	n2=n2*10+n%10;
	n/=10;
}
while (n2!=0)
{
	c=n2%10;
	if (c%2==0) cout<<c;
	n2/=100;
}
cout<<endl;
}