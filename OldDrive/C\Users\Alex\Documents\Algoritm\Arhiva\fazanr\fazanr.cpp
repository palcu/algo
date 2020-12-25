#include <cstdio>
int main()
{
	freopen ("fazanr.in","r",stdin);
	freopen ("fazanr.out","w",stdout);
	
	int n,i,x=0,c=0,c2=0,nr=0;
	scanf("%d",&n);
	scanf("%d",&c);
	c%=10;
	for (i=1; i<n; ++i)
	{
		scanf("%d",&x);
		c2=x%10;
		while (x>9)
			x/=10;
		if (c!=x)
			++nr;
		c=c2;
	}
	printf("%d",nr);
	return 0;
}
