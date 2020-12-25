#include <iostream.h>
void main()
{
int n,i,max,min,x;
cin>>n;
cin>>x; max=x; min=x; n--;
for (i=1; i<=n; i++)
{
	cin>>x;
	if (x>max) max=x;
	if (x<min) min=x;
}
cout<<max<<min<<endl;
}