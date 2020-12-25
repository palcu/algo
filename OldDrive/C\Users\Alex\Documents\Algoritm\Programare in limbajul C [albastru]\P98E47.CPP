#include <iostream.h>
void main() {
int n,s0,s1,s2,s,i;
cin>>n;
s0=1; s1=2; s2=1;
if ((n==1) ||(n==3)) cout<<1;
else
if (n==2) cout<<2;
else
{
for (i=4;i<=n;i++)
	{
	 s=s2+2*s1-s0;
	 s0=s1;
	 s1=s2;
	 s2=s;
	}
cout<<s<<endl;
}
}