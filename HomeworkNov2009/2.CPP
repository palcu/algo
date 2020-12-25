#include <iostream.h>
#include <math.h>
void main()
{
int n,i,x,prim,j,rad,nrprim=0;
float ma=0;
cin>>n;
for (i=1;i<=n;i++)
{
	cin>>x;
	prim=1;
	if (x==1) prim=0;
	else
	if (x%2==0)
		if (x!=2)
			prim=0;
	else
	{
		rad=sqrt(x);
		for (j=3;j<=rad;j+=2)
		{
			if (x%j==0)
			{
				prim=0;
				break;
			}
		}
	}
	if (prim==1)
	{
		ma+=x;
		nrprim++;
	}
}
ma/=nrprim;
cout<<ma<<endl;
}