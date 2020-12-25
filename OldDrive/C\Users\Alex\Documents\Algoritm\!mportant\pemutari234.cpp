#include<cstdio>
int n, v[3000];
void perm(int k)
{
	int i,x,ok;
	if (k==n+1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",v[i]);
		printf("\n");
	}
	else 
		for(x=1;x<=n;x++)
		{
			ok=1;
			for(i=1;i<k;i++)
				if(v[i]==x)
				{
					ok=0;
					break;
				}
				if(ok)
				{
					v[k]=x;
					perm(k+1);
				}
		}
}
int main()
{
	scanf("%d",&n);
	perm(1);
}
