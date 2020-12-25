#include <iostream.h>
void main()
{
int n,c0=0,n2,i;
cin>>n;
n2=n;
while (n2%10==0)
{
	c0++;
	n2/=10;
}
while (n2!=0)
{
	n=n*10+n2%10;
	n2/=10;
}
for (i=1;i<c0;i++)
	n*=10;
}