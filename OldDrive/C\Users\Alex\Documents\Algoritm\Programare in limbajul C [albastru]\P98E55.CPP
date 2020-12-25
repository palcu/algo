#include <iostream.h>
void main()
{
int n,i,s,p,i2,c;
cin>>n;
for (i=10;i<=n;i++)
{
	i2=i; s=0; p=1;
	while (i2!=0)
	{
		c=i2%10;
		s+=c;
		p*=c;
		i2/=10;
	}
	if (i%s==0)
		if (p!=0)
			if (i%p==0) cout<<i<<" ";
}
cout<<endl;
}


