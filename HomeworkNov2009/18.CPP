#include <iostream.h>
void main()
{
int n,i;
float s=0,x;
cin>>n;
for (i=1; i<=n; i++)
{
	cin>>x;
	s+=1/x;
}
s=n/s;
cout<<s<<endl;
}