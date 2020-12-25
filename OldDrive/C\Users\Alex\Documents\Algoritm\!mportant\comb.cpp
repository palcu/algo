#include<cstdio>
int v[100],n,p,k;
void combinari (int k)
{
	int x,i;
	if (k==p+1)
	{
		for (i=1;i<=p;i++) printf("%d ",v[i]);
		printf("\n");
	}
	else 
		for (x=v[k-1]+1;x<=n-p+k;x++)
		{
			v[k]=x;
			combinari(k+1);
		}
}

int main()
	freopen("comb.in","r",stdin);
{
	freopen("comb.out","w",stdout);
	scanf("%d %d",&n,&p);
	for (k=1;k<=p;k++) combinari(k);
	return 0;
}
