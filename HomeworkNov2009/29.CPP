#include <iostream.h>
void main()
{
int n,c,max,nr=1;
cin>>n;
max=n%10; n/=10;
while (n!=0)
{
	c=n%10;
	if (c>max)
	{
		max=c;
		nr=1;
	}
	else
	if (c==max)
		nr++;
	n/=10;
}
cout<<max<<" de "<<nr<<" ori"<<endl;
}