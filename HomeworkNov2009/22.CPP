#include <iostream.h>
void main()
{
int p=0,i=0,c;
long int n, n2=0;
cin>>n;
while (n!=0)
{
	n2=(n2*10)+(n%10);
	n/=10;
}
while (n2!=0)
{
	c=n2%10;
	if (c%2==0)
		p=p*10+c;
	else
		i=i*10+c;
        n2/=10;
}
cout<<p<<" "<<i<<endl;
}