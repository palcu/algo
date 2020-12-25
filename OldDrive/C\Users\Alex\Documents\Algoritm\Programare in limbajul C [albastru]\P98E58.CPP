#include  <iostream.h>
void main()
{
int i,i2,c1,c2,cresc=0;
for (i=100;i<=999;i++)
{
	i2=i;
	c1=i2%10;
	i2/=10;
	c2=i2%10;
	if (c1>c2)
	{
		i2/=10;
		c1=i2%10;
		if (c2>c1)
		{
			cout<<i<<" ";
			cresc++;
		}
	}
}
cout<<endl<<endl;

for (i=100;i<=999;i++)
{
	i2=i;
	c1=i2%10;
	i2/=10;
	c2=i2%10;
	if (c1<c2)
	{
		i2/=10;
		c1=i2%10;
		if (c2<c1)
		{
			cout<<i<<" ";
			cresc++;
		}
	}
}
cout<<endl<<cresc<<endl;

}

