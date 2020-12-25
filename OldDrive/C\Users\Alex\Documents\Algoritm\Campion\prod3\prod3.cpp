#include <cstdio>

int main()
{
	freopen ("prod3.in","r",stdin);
	freopen ("prod3.out","w",stdout);
	
	int x,maxpoz=-1,maxneg=1,maxpoz2=-1,maxneg2=1,maxpoz3=-1;
	int minpoz=300001,minpoz2=30001,minneg=0,minneg2=0,minneg3=0;
	long n,i;
	scanf("%ld",&n);
	
	for (i=1; i<=n; i++)
	{
		scanf("%d",&x);
		if (x<0)
		{
			if (x<maxneg)
			{
				if (x<maxneg2)
				{
					maxneg=maxneg2;
					maxneg2=x;
				}
				else
					maxneg=x;					
			}
			if (x<minneg)
			{
				if (x<minneg2)
				{
					if (x<minneg3)
					{
						minneg=minneg2;
						minneg2=minneg3;
						minneg3=x;
					}
					else
					{
						minneg=minneg2;
						minneg2=x;
					}
				}
				else
					minneg=x;
				}
		}
		else
		{
			if (x>maxpoz)
			{
				if (x>maxpoz2)
				{
					if (x>maxpoz3)
					{
						maxpoz=maxpoz2;
						maxpoz2=maxpoz3;
						maxpoz3=x;
					}
					else
					{
						maxpoz=maxpoz2;
						maxpoz2=x;
					}
				}
				else
					maxpoz=x;
			}
			if (x<minpoz)
			{
				if (x<minpoz2)
				{
					minpoz=minpoz2;
					minpoz2=x;
				}
				else
					minpoz=x;
			}
		}
	}
	
/*
	if (maxpoz==-1)
	{
		if (maxneg2!=-30001)
			printf("%d %d %d",maxpoz3,maxneg2,maxneg);
		else
			printf("%d %d %d",maxpoz3, maxpoz2,
	else
	if (maxneg!=-30001)
	{
		if (maxneg*maxneg2>maxpoz*maxpoz2)
			printf("%d %d %d",maxpoz3,maxneg2,maxneg);
	}
	else
		printf("%d %d %d",maxpoz,maxpoz2,maxpoz3);
	*/
	if ((maxpoz!=-1)&&(maxneg!=1))
	{
		if (maxpoz*maxpoz2>maxneg*maxneg2)
			printf("%d %d %d",maxpoz,maxpoz2,maxpoz3);
		else
			printf("%d %d %d",maxpoz3,maxneg2,maxneg);
	}
	else
	if ((maxpoz!=-1)&&(maxneg==1))
		printf("%d %d %d",maxpoz,maxpoz2,maxpoz3);
	else
	if ((maxpoz==-1)&&(maxneg!=1))
		printf("%d %d %d",maxpoz3,maxneg,maxneg2);
	else
	if ((maxpoz3!=-1)&&(maxneg2!=1))
		printf("%d %d %d",maxpoz3,maxneg,maxneg2);
	else
	{
		if (minneg2*minneg3<minpoz*minpoz2)
			printf("%d %d %d",minneg,minneg2,minneg3);
		else
			printf("%d %d %d",minneg,minpoz,minpoz2);
	}

	return 0;
}
