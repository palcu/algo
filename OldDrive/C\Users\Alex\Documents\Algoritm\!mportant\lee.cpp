#include <cstdio>
int m[100][100],l[100],c[100];

int main()
{
	freopen("lee.in","r",stdin);
	freopen("lee.out","w",stdout);
	
	int cdx,cdy,nrob,i,j,x,y,ax,ay,p,u,lin,col;
	
	scanf("%d%d%d",&cdx,&cdy,&nrob);
	for (i=1; i<=nrob; ++i)
	{
		scanf("%d%d",&x,&y);
		m[x][y]=-1;
	}
	scanf("%d%d",&x,&y);
	
	scanf("%d%d",&ax,&ay);
	
	m[x][y]=1;
	l[1]=x;c[1]=y; p=u=1;
	
	while (p<=u && !m[ax][ay])
	{
		lin=l[p]; col=c[p];
		if (lin-1>=1 && !m[lin-1][col])
		{
			m[lin-1][col]=m[lin][col]+1;
			++u;
			l[u]=lin-1; c[u]=col;
		}
		
		if (lin+1>=1 && !m[lin+1][col])
		{
			m[lin+1][col]=m[lin][col]+1;
			++u;
			l[u]=lin+1; c[u]=col;
		}
		
		if (col-1>=1 && !m[lin][col-1])
		{
			m[lin][col-1]=m[lin][col]+1;
			++u;
			l[u]=lin; c[u]=col-1;
		}
		
		if (col+1>=1 && !m[lin][col+1])
		{
			m[lin][col+1]=m[lin][col]+1;
			++u;
			l[u]=lin; c[u]=col+1;
		}	
		
		++p;
	}	
	for (i=1; i<=cdx; ++i)
	{
		for (j=1;j<=cdy;++j)
			printf("%d ",m[i][j]);
		printf("\n");
	}
	
	return 0;
	
}
