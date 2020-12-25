#include <cstdio>
using namespace std;
int main()
{
	freopen("concurs3.in","r",stdin);
	freopen("concurs3.out","w",stdout);
	int h,n,no=0,ns=0,premiat=0;
	int i,x,h2,s,o;
	scanf("%d%d",&h,&n);
	h2=h; h2/=10; s=h2%10; h2/=10; o=h2%10;
	for (i=1; i<=n; i++)
	{
		scanf("%d",&x);
		if (h==x)
			premiat=1;
		x/=10; x=x%10*10+x/10;
		if (x%10==o)
		{
			no++;
			x/=10;
			if (x%10==s)
				ns++;
		}
	}
	if (premiat)
		printf("DA\n");
	else
		printf("NU\n");
	printf("%d\n%d",no,ns);
	return 0;
}
