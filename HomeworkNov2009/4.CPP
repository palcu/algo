#include <iostream.h>
void main()
{
int n,p,div=0,i,max;
cin>>n>>p;
max=n/2;
for (i=2;i<=max;i++)
{
	if (n%i==0)
	{
		cout<<n/i<<" ";
		div++;
	}
	if (div==p) break;
}
cout<<endl;
}