#include <iostream.h>
void main()
{
int n,c;
cin>>n;
while (n!=0)
{
	c=n%10;
	if (c%2==0) cout<<c<<", ";
	n/=10;
}
cout<<endl;
}