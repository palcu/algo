#include <iostream.h>
void main()
{
int n,i,moneda;
float s,d,d2,e,e2,s2;
cin>>n>>d>>e; s2=100; moneda=1;
for (i=1;i<n;i++)
{
	cin>>d2>>e2;  s=s2;
	if (moneda==1)
	{
		if(d2>d)
		{
			s2=d2/s*100; moneda=0;
			cout<<"Ziua "<<i+1<<" ... schimba "<<s<<" euro in "<<s2<<" dolari"<<endl;
		}
	}
	else
	{
		if(e2<e)
		{
			s2=s/e2*100; moneda=1;
			cout<<"Ziua "<<i+1<<" ... schimba "<<s<<" dolari in "<<s2<<" euro"<<endl;
		}
	}
	d=d2; e=e2;
}
}