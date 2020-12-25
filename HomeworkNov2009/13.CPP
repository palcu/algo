#include <iostream.h>
void main()
{
int n,l1,l2,l3,i,nr=0;
cin>>n>>l1>>l2; n-=2;
for (i=1;i<=n;i++)
{
	cin>>l3;
	if ((l1+l2>l3)&&(l1+l3>l2)&&(l2+l3>l1)&&(l1>0)&&(l2>0)&&(l3>0))
		nr++;
	l1=l2; l2=l3;
}
cout<<nr<<endl;
}