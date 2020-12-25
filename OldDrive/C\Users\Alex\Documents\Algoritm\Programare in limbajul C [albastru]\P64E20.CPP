#include <iostream.h>
void main()
{
int a,b,c,a1,b2,nr=0;
cin>>a>>b>>c;
while (c!=0)
{
	a1=a; b2=b;
	while (a1!=b2)
	{
		if (a1>b2) a1=a1-b2;
		else b2=b2-a1;
	}
	if (a1==c) nr++;
	a=b; b=c; cin>>c;
}
cout<<nr<<endl;
}