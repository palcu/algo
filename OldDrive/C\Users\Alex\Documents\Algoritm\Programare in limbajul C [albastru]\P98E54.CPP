#include <iostream.h>
#include <math.h>
void main()
{
int n,i,x,i2,i3,prim,j;
cin>>n;
for (i=11;i<n;i+=2)
{
	i2=i; i3=0;
	while (i2!=0)    //palindrom
	{
		i3=i3*10+i2%10;
		i2/=10;
	}

	if (i3==i)
	{
		i3=sqrt(i3); prim=1;
		for (j=3;j<=i3;j+=2)     //prim
		{
			if (i%j==0)
			{
				prim=0;
				break;
			}
		}
		if (prim) cout<<i<<" ";
	}
}
cout<<endl;
}
