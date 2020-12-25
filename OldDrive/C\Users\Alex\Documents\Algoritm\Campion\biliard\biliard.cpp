#include <cstdio>

int main()
{
	freopen("biliard.in","r",stdin);
	freopen("biliard.out","w",stdout);
	
	long m, n, x, y, t, a=0, b=0, timp=0;
	int buzunar=0;
	
	scanf("%ld%ld%ld%ld%ld", &m, &n, &x, &y, &t);
	
	while ((!buzunar) && (timp<t))
	{
		++timp;
		a+=x;
		b+=y;
		
		while ((a<0)||(a>m))
		{
			if (a<0)
			{
				a=-a;
				x=-x;
			}
			else
			if (a>m)
			{
				a=2*m-a;
				x=-x;
			}
		}
		
		while ((b<0)||(b>n))
		{
			if (b<0)
			{
				b=-b;
				y=-y;
			}
			else
			if (b>n)
			{
				b=2*n-b;
				y=-y;
			}
		}
		
		if (timp%2)
		{
			if (a==0)
			{
				if (b==0)
					buzunar=1;
				else
				if (b==n)
					buzunar=3;
			}
			else
			if (a==m)
			{
				if (b==0)
					buzunar=2;
				else
				if (b==n)
					buzunar=4;
			}
		}
	}
	
	if (buzunar)
		printf("%ld %d",timp,buzunar);
	else
		printf("%ld %ld",a,b);
	
	return 0;
}
