#include <cstdio>
using namespace std;
int main()
{
	freopen("valori_panta.in","r",stdin);
	freopen("valori_panta.out","w",stdout);
	
	int n,i,x,c1,c2,ok,n2=0,max,min,init=0,nr=0;
	scanf("%d",&n);
	
	while (init==0)
	{
		init=1;
		scanf("%d",&x);
		if (n>9)
		{
			n2=n;
			c1=n2%10; n2/=10; c2=n2%10; n2/=10;
			if (n==0)
			{
				if (c1==c2)
					init=0;
			}
			else
			{
				if (c1>c2)
				{
					while (n!=0)
					{
						c1=c2;
						c2=n%10;
						n/=10;
						if (c1<=c2)
						{
							init=0;
							break;
						}
					}
				}
				else
				{
					while (n!=0)
					{
						c1=c2;
						c2=n%10;
						n/=10;
						if (c1>=c2)
						{
							init=0;
							break;
						}
					}
				}
			}
		}
		if (init==1)
		{
			max=x;
			min=x;
			nr++;
		}
		n--;
	}
	
	for (i=1; i<=n; i++)
	{
		scanf("%d",&x);
		ok=1;
		if (n>9)
		{
			n2=n;
			c1=n2%10; n2/=10; c2=n2%10; n2/=10;
			if (n==0)
			{
				if (c1==c2)
					ok=0;
			}
			else
			{
				if (c1>c2)
				{
					while (n!=0)
					{
						c1=c2;
						c2=n%10;
						n/=10;
						if (c1<=c2)
						{
							ok=0;
							break;
						}
					}
				}
				else
				{
					while (n!=0)
					{
						c1=c2;
						c2=n%10;
						n/=10;
						if (c1>=c2)
						{
							ok=0;
							break;
						}
					}
				}
			}
		}		
		if (ok==1)
		{
			nr++;
			if (x>max)
				max=x;
			if (x<min)
				min=x;
		}
	}
	
	if (nr==0)
		printf("NU EXISTA");
	else
	printf("%d %d %d",nr,max,min);
	
	return 0;
}