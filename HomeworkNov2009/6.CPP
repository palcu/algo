#include <iostream.h>
void main()
{
int x,y,n,nr=0,i=1;
cin>>n>>x>>y;
while (i<x) i*=2;
while (i<=y)
{
	cout<<i<<" ";
	nr++;
	if (n==nr) break;
	i*=2;
}
cout<<endl;
}