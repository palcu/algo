#include <iostream.h>
void main()
{
int n,x,t,s=0,i;
float m;
cin>>n;
for (i=1;i<=n;i++)
	{
	cin>>x;
	s+=x;
	}
cout<<"teza ";
cin>>t;
m=(float)(s/n*3+t)/4;
cout<<m<<endl;
}