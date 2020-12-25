#include <iostream.h>
void main()
{
int n,n2=0,s;
cin>>n;
while (n!=0)
{
	n2=n2*10+n%10;
	n/=10;
}
s=n2%10;
n2/=10;
s+=n2%10;
cout<<s<<endl;
}