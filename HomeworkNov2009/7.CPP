#include <iostream.h>
void main()
{
int n,i,s=0;
cin>>n;
for (i=1; i<=n; i++)
	s+=i*10+i+1;
cout<<s<<endl;
}