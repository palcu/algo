#include<cstdio>
int n, v[3000];
bool a[3000];
void perm(int k)
{
	int i,x;
	if (k==n+1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",v[i]);
		printf("\n");
	}
	else 
		for(x=1;x<=n;x++)
			if(!a[x])
			{
				v[k]=x;
				a[x]=1;
				perm(k+1);
				a[x]=0;
			}


}
int main()
{
	scanf("%d",&n);
	perm(1);
	
	
}