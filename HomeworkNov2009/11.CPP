#include <iostream.h>
void main()
{
int n,i1,i2,i3,max;
cin>>n; max=(n-3)/3;
for (i1=1; i1<=max; i1++)
	for (i2=i1+1;i2<=max+1;i2++)
		for (i3=i2+1; ;i3++)
			if (i1+i2+i3==n)
			{
				cout<<n<<"="<<i1<<"+"<<i2<<"+"<<i3<<endl;
				break;
                        }
}