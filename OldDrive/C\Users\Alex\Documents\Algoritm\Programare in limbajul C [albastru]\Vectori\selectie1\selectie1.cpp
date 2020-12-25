#include <cstdio>
int main()
{
	int a[10],i,pozmin,dr,n,min;
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for (dr=n-1; dr<n; dr++)
	{
		for (min=a[0], pozmin=0, i=1; i<=dr; i++)
			if (a[i] < min)
			{
				min=a[i];
				pozmin=i;
			}
		a[pozmin]=a[dr];
		a[dr]=min;
	}
	
	for (i=0; i<n; i++)
		printf("%d",a[i]);
	
	
	while (1);
	return 0;
}