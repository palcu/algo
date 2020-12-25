#include <iostream.h>
#include <math.h>
void main()
{
int n,prim,nr=0,i,rad;
cin>>n; n--;
if (n%2==0) n--;
while (nr!=2)
{
	prim=1; rad=sqrt(n);
	for (i=3; i<=rad; i+=2)
	{
		if (n%i==0)
		{
			prim=0;
			break;
		}
	}
	if (prim==1)
	{
		cout<<n<<" ";
		nr++;
	}
	n-=2;
}
cout<<endl;
}