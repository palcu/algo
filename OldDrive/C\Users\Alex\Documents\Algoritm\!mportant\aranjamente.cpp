#include<cstdio>
int n,p, v[3000];
bool a[3000];
void aranj(int k)
{
	int i,x;
	if (k==p+1)
	{
		for(i=1;i<=p;i++)
			printf("%d ",v[i]);
		printf("\n");
	}
	else 
		for(x=1;x<=n;x++)
			if(!a[x])
			{
				v[k]=x;
				a[x]=1;
				aranj(k+1);
				a[x]=0;
			}


}
int main()
{
	scanf("%d%d",&n,&p);
	aranj(1);
	
	
}
