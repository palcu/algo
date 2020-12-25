#include <iostream.h>
void main()
{
int n,i,j,n2;
cin>>n;
cout<<endl;

for (i=1; i<=n; i++)
{
	for (j=1;j<=n;j++)
		cout<<"* ";
	cout<<endl;
}
cout<<endl;

n2=n;
while (n2!=0)
{
	for (i=1; i<=n2; i++)
		cout<<"* ";
	n2--;
	cout<<endl;
}
cout<<endl;

for (i=1; i<=n; i++)
{
	for (j=1; j<=i; j++)
		cout<<"* ";
	cout<<endl;
}
cout<<endl;

for (i=1; i<=n; i++)
{
	for (j=1;j<=i;j++)
		cout<<j<<" ";
	cout<<endl;
}
cout<<endl;
}