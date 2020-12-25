#include <iostream.h>
#include <math.h>
void main()
{
int nrc=0,i;
long int n,n2,n3=0;
cin>>n; n2=n;
while (n2!=0)
{
	nrc++;
	n2/=10;
}
if (nrc%2==0) nrc/=2;
else nrc=nrc/2+1;
for (i=1; i<=nrc; i++)
{
	n3=n3*10+n%10;
	n/=10;
}
while (n3!=0)
{
	n2=n2*10+n3%10;
	n3/=10;
}
cout<<n<<" "<<n2<<endl;
}