#include <iostream.h>
#include <math.h>
void main()
{
int n,i,pag=0,cif=0,prim,j,rad,i2;
cin>>n;
for (i=3;i<=n;i++)
{
	prim=1; rad=sqrt(i);
	if (i%2==0) prim=0;
	else
	{
		for (j=3;j<=rad;j+=2)
		{
			if (i%j==0)
			{
				prim=0;
				break;
			}
		}
	}
	if (prim==1)
	{
		i2=i;
		while (i2!=0)
		{
			cif++;
			i2/=10;
		}
	}
	else
	pag++;
}
cout<<pag<<" "<<cif<<endl;
}
