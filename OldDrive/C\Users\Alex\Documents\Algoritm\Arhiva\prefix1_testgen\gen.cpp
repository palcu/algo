#include <cstdio>

int rest[100];

int main()
{
	freopen("gen.in","r",stdin);
	long n,i,k,max=0,r,x;
	scanf("%ld%ld",&k,&n);
	
	for (i=1; i<=n; i++)
	{
		scanf("%ld",&x);
		r=x%k;
		rest[r]++;
		if (rest[r]>max)
			max=r;
	}
	
	printf("%ld %d",max,rest[max]);
	return 0;
}
