#include <cstdio>

int main()
{
	freopen ("reforma.in","r",stdin);
	freopen ("reforma.out","w",stdout);
	
	int s,nr=0,e,i,o;
	int maxE,maxI,sI,maxO,sO;
	scanf("%d",&s);
	maxO=s/20;
	for (o=0; o<=maxO; o++)
	{
		sO=s-o*20;
		maxI=sO/10;
		for (i=0; i<=maxI; i++)
		{
			sI=sO-i*10;
			maxE=sI/5;
			for (e=0; e<=maxE; e++)
			{
				nr++;
			}
		}
	}
	
	printf("%d",nr);
	
	return 0;
}
