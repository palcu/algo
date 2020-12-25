#include <iostream.h>
void main()
{
long n,p=1;
cin>>n;
while (p<=30000)
{
	cout<<p<<" ";
	p*=n;
}
cout<<endl;
}