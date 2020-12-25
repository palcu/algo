#include <iostream.h>
int main() {
int n,i,j,x,y,f=0;
cin>>n;
for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
		{
		x=i;y=j;
		while (x!=y)
			if (x>y) x=x-y;
				else y=y-x;
		if (x==1) f++;

		}
cout<<f;
}