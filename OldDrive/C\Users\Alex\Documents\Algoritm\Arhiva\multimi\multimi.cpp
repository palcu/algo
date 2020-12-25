#include <cstdio>
using namespace std;
int main()
{
	freopen("multimi.in","r",stdin);
	freopen("multimi.out","w",stdout);
	int n,a,b,x,y,i;
	scanf("%d%d%d",&n,&a,&b);
	n--;
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&x,&y);
		if (x>a)
			a=x;
		if (y<b)
			b=y;
	}
	if (a<=b)
	{
		for (i=a; i<=b; i++)
			printf("%d ",i);
		return 0;
	}
	else
		printf("multimea vida");
}
