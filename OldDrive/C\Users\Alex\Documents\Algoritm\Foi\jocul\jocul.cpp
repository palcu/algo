#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{
	freopen("jocul.in","r",stdin);
	
	srand(time(NULL));
	int n,n2,i,si=0,sp=0,v[100];
	char v2[50];
	scanf("%d",&n);
	
	for (i=0; i<n; ++i)
	{
		scanf("%d",&v[i]);
		if (i%2) si+=v[i];
		else sp+=v[i];;
	}
	
	n2=n/2;
	
	if (si>sp)
	{
		printf("%d\n",si);
		printf("D"); v2[n2-1]='S';
	}
	else
	{
		printf("%d\n",sp);
		printf("S"); v2[n2-1]='D';
	}
	--n2;
	for (i=0; i<n2; ++i)
		if (rand()%2)
			{
				v2[i]='D';
				printf("D");
			}
		else
			{
				v2[i]='S';
				printf("S");
			}
	printf("\n");
	++n2;
	for (i=0; i<n2; ++i)
		printf("%c",v2[i]);
	
	
	
	return 0;
}
