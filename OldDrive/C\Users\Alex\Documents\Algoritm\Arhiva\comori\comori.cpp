#include <cstdio>
int main()
{
	freopen("comori.in","r",stdin);
	freopen("comori.out","w",stdout);
	int x=0,y=0,n,d,p;
	int i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&d,&p);
		switch (d)
		{
		case 1: 
			y+=p; 
			break;
		case 2:
			x+=p;
			y+=p;
			break;
		case 3:
			x+=p;
			break;
		case 4:
			x+=p;
			y-=p;
			break;
		case 5:
			y-=p;
			break;
		case 6:
			x-=p;
			y-=p;
			break;
		case 7:
			x-=p;
			break;
		case 8:
			x-=p;
			y+=p;
		}
	}
	printf("%d %d",x,y);	
	return 0;
}