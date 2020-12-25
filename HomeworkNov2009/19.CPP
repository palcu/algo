#include <iostream.h>
void main()
{
int n,i,a,b,c,d,nrd=0,nri=0;
cin>>n>>a>>b; n--;
for (i=1; i<=n; i++)
{
	cin>>c>>d;
	if ((d<a)||(b<c))
		nrd++;
	if ((c>a)&&(d<b))
		nri++;
}
cout<<nrd<<" "<<nri<<endl;
}