#include <iostream.h>
#include <math.h>
void main()
{
int n,i=3,nr=1,d,rad,prim;
cin>>n;
cout<<"2 "; n--;
while (nr!=n)
{
	rad=sqrt(i); prim=1;
	for (d=3; d<=rad && i%d!=0; d+=2);
	if (i%d==0)
		prim=0;
	if (prim==1)
	{
		cout<<i<<" ";
		nr++;
	}
	i+=2;
}
}