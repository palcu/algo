#include <iostream.h>
int main() {
int n,i,s=0;
cin>>n;
while (n>=10)
	{
	s=0;
	while (n!=0)
		{
		s+=n%10;
		n/=10;
		}
	n=s;
	}
cout<<n;
}

