#include <iostream.h>
void main()
{
int n,i,x,max,nr=1;
cin>>n;
cin>>max; n--;
for (i=1; i<=n; i++)
{
	cin>>x;
	if (x>max)
	{
		max=x;
		nr=1;
	}
	else
	if (x==max)
		nr++;
}
cout<<max<<" obtinuta de "<<nr<<" elevi"<<endl;
}
