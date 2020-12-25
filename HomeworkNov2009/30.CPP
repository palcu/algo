#include <iostream.h>
void main()
{
int n,s=0,i=2;
cin>>n;
while (s+i<n)
{
	cout<<i<<" ";
	s+=i; i+=2;
}
cout<<endl;
}