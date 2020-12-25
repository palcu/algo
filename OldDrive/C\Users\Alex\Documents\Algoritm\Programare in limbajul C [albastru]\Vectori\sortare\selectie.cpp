#include <cstdio>
int main()
{
	int a[10],i,pozmax,dr,n,max;
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for (dr=n-1; dr>0; dr--)
	{
		for (max=a[0], pozmax=0, i=1; i<=dr; i++)
			if (a[i] > max)
			{
				max=a[i];
				pozmax=i;
			}
		a[pozmax]=a[dr];
		a[dr]=max;
	}
	
	for (i=0; i<n; i++)
		printf("%d",a[i]);
	
	
	while (1);
	return 0;
}