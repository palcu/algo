#include <iostream.h>
void main()
{
int n,i,s=0,x=0;
cin>>n;
for (i=1; i<=n; i++)
{
	x=x*10+i;
	s+=x;
}
cout<<s<<endl;
}