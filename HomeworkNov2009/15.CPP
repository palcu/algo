#include <iostream.h>
void main()
{
int n,i;
long int x,max1,max2;
cin>>n;
cin>>max1;
cin>>x;
if (x>max1)
{
	max2=max1;
	max1=x;
}
else max2=x;
n-=2;

for (i=1; i<=n; i++)
{
	cin>>x;
	if (x>max1)
	{
		max2=max1;
		max1=x;
	}
	else
	{
		if (x>max2)
			max2=x;
	}
}
cout<<max2<<" "<<max1<<endl;
}