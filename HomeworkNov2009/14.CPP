#include <iostream.h>
#include <math.h>
void main()
{
int a,b,n;
float c;
cin>>n;
for (a=3;a<n-2 ;a++)
	for (b=a+1;a<n-1;b++)
	{
		c=sqrt(a*a+b*b);
		if (c>n) break;
		else
			if (int(c)==c) cout<<a<<" "<<b<<" "<<c<<endl;
        }
}