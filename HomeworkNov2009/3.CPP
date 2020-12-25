#include <iostream.h>
void main()
{
int n,i,x,p=1,n2,x2,r;
cin>>n;
for (i=1;i<=n;i++)
{
	cin>>x; n2=n; x2=x;
	while (n2!=0)
	{
		r=x2%n2;
		x2=n2;
		n2=r;
	}
	if (x2==1) p*=x;

}
cout<<p<<endl;
}