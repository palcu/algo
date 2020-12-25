#include <cstdio>

//typedef char nume[20];

struct chestie{char x[20]; int y;};
chestie alim[1000];

int main()
{
	freopen("bacan.in","r",stdin);
	//freopen("bacan.out","w",stdout);
	
	int n,i,a,b,c;
	
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%s",alim[i].x);
		scanf(" * %d",&alim[i].y);
	}
	
	for (i=1;i<=n;++i)
	{
		printf("%s ",alim[i].x); 
		printf("%d",alim[i].y);
		printf("\n");
	}
	
	return 0;
}
