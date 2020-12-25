#include <iostream.h>
#include <math.h>
void main()
{
int b1,b2,i=0,nrc0=0;
long n, n2=0, n3=0, n10=0;
cin>>n>>b1>>b2;

while (n!=0)
{
	n10+=(n%10)*pow(b1,i);
	n/=10; i++;
}

n=n10;
while (n%b2==0)
{
	nrc0++;
	n/=b2;
}

while (n!=0)
{
	n3=n3*10+n%b2;
	n/=b2;
}

while (n3!=0)
{
	n2=n2*10+n3%10;
	n3/=10;
}
n2*=pow(10,nrc0);
cout<<n10<<" "<<n2;
}