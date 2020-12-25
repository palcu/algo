#include <iostream.h>
#include <math.h>
void main()
{
int n,n2,nrcif=0,nrcif2,max,i,s=0,par=0,nx;
cin>>n;
n2=n;
while (n2!=0)
{
	nrcif++;
	n2/=10;
}
nrcif2=nrcif-2;
n2=n;
for (i=1; i<=nrcif2; i++)
	n2/=10;
max=n2/2;
for (i=1; i<=max; i++)
{
	if (n2%i==0)
		s+=i;
}
if (n2==s)
	cout<<nrcif;
else
{
	while (n!=0)
	{
		if ((n%10)%2==0)
			par++;
		n/=10;
	}
	cout<<par;
}
}