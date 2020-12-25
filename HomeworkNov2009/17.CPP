#include <iostream.h>
void main()
{
int n,n1,n2,corig=0,max=0,i;
float ma=0,m;
cin>>n;
for (i=1; i<=n; i++)
{
	cin>>n1>>n2;
	m=(n1+n2)/2;
	if (m<4.5) corig++;
	if (m>max) max=m;
	ma+=m;
}
ma/=n;
cout<<"media = "<<ma<<endl;
cout<<"corig = "<<corig<<endl;
cout<<"max = "<<max<<endl;
}
