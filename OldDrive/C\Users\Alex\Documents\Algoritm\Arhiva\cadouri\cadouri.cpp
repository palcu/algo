#include <cstdio>
int main()
{
	freopen ("cadouri.in","r",stdin);
	freopen ("cadouri.out","w",stdout);
	
	int b,f,n,i,x,B=0,F=0;
	scanf("%d%d%d",&f,&b,&n);
	for (i=1; i<=n; ++i)
	{
		scanf("%d",&x);
		if (x%2)
			++B;
		else
			++F;
	}
	if (f-F<=0)
		printf("0\n");
	else
		printf("%d\n",f-F);
	if (b-B<=0)
		printf("0");
	else
		printf("%d",b-B);
	
	return 0;
}
