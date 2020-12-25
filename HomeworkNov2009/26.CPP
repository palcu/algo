#include <iostream.h>
void main()
{
int n,s,x;
cin>>n;
x=n%10;
while (n/10!=0) n/=10;
x=x+n*10;
if (x%2!=0) x*=2;
cout<<x<<endl;
}
