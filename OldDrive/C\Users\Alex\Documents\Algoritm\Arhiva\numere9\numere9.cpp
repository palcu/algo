#include<cstdio>
using namespace std;
int main()
{
	freopen("numere9.in","r",stdin);
	freopen("numere9.out","w",stdout);
	
	int n,m;
	int a[9],b[9];
	int i=0,j=0,l=0,ok,x,k;
	
	scanf("%d%d",&n,&m);
	
	while (n!=0)
	{
		a[i]=n%10;
		n/=10;
		i++;
	}
	
	for (i=1;i<=m;i++)
	{
		scanf("%d",&n);
		x=n;
		
		while (n!=0)
		{
			b[j]=n%10;
			n/=10;
			j++;
		}
		ok=1;
		
		while (l!=j)
		{
			for (k=0; k<j; k++)
			{
				if (a[k]==b[l])
				{
					l++;
					ok=1;
				}
				else
					ok=0;
			}
		}
		if (ok)
			break;
	}
	printf("%d",x);
	return 0;
}
