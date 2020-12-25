#include <iostream.h>
void main()
{
int n,i,x,cmmdc;
cin>>n;
cin>>x; cmmdc=x; n--;
for (i=1;i<=n;i++)
{
	cin>>x;
	while (cmmdc!=x)
	{
		if (x>cmmdc) x=x-cmmdc;
		else cmmdc=cmmdc-x;
	}
}
cout<<cmmdc<<endl;
}