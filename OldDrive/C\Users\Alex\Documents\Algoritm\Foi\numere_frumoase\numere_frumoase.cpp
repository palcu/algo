#include <cstdio>

bool a[1000000];

int main()
{
	int i,n,n2,n3,n5;
	
	scanf("%d",&n);
	for (i=2; i<=n; i+=2)
		a[i]=1;
	for (i=3; i<=n; i+=3)
		a[i]=1;
	for (i=5; i<=n; i+=5)
		a[i]=1;
	for (i=1; i<=n; ++i)
		if (a[i]) printf("%d ",i);
	
	
	
	return 0;
}
