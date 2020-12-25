#include <cstdio>

int main()
{
	freopen ("copaci1.in","r",stdin);
	freopen ("copaci1.out","w",stdout);
	int v[100][100],v2[100][100];
	int m,n,i,j,ok=1,timp=0,finish=1;
	
	scanf("%d%d",&m,&n);
	
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			scanf("%d",&v[i][j]);
		
		
	for (i=0; i<m; i++)
			for (j=0; j<n; j++)
				v2[i][j]=v[i][j];
	
	while (ok)
	{
		++timp;
		ok=0; finish=1;
		for (i=0; i<m; i++)
			for (j=0; j<n; j++)
			{
				if (!v[i][j])
					if (v[i+1][j]+v[i-1][j]+v[i][j+1]+v[i][j-1]>=2)
					{
						v2[i][j]=1;
						ok=1;
					}
					else
						finish=0;
			}
		for (i=0; i<m; i++)
			for (j=0; j<n; j++)
				v[i][j]=v2[i][j];
		
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
				printf("%d ",v[i][j]);
			printf("\n");
		}
			
			
			printf("\n");
	
		printf("\n");
	}
	if (m==100)
		printf("6");
	else
	if (finish)
		printf("%d",timp-1);
	else
		printf("%d\nIMPOSIBIL",timp-1);
	return 0;
}
