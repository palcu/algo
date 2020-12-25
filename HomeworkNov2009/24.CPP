#include <iostream.h>
void main()
{
int n;
cin>>n;
while (n!=0)
{
	cout<<n%10;
	n/=100;
}
cout<<endl;
}