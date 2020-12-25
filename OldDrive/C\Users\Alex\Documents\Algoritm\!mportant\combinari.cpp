#include<cstdio>
int p,n,v[100];
void comb( int k)
{
	int x,i;
	if(k==p+1)
	{
		for(i=1;i<=p;i++)
			printf("%d ",v[i]);
		printf("\n");
	}
	else 
		for(x=v[k-1]+1;x<=n-p+k;x++)
		{
			v[k]=x;
			comb(k+1);
		}
		
}

int main()
{
	
	v[0]=0;
	scanf("%d%d",&n,&p);
	comb(1);
}
