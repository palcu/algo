#include <iostream.h>
void main()
{
int n,c,nr=1;
cin>>n;
c=n%10; n/=10;
while (n!=0)
{
	if (n%10==c) nr++;
	n/=10;
}
cout<<c<<" de "<<nr<<" ori"<<endl;
}