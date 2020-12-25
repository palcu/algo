#include <iostream.h>
void main()
{
int n,m,max;
cin>>n>>m;
if (n%2==0)
	n+=1;
else
	n+=2;
max=n+m;
while (n<=max)
{
	cout<<n<<" ";
	n+=2;
}
cout<<endl;
}