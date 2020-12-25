#include <cstdio>
#define caz 10

int main()
{
	freopen("biliard.in","r",stdin);
	freopen("biliard.out","w",stdout);
	
	long m, n, x, y, t, a=0, b=0, timp=0, x2, y2;
	int buzunar=0;
	
	scanf("%ld%ld%ld%ld%ld", &m, &n, &x, &y, &t);
	for (m=5; m<=caz; m++)
		for (n=5; n<=caz; n++)
			for (x2=5; x2<=5; x2++)
				for (y2=5; y2<=5; y2++)
				{
					timp=0; a=0; b=0; x=x2; y=y2;
	while (timp<=10)
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
			if (b>n)
			{
				b=2*n-b;
				y=-y;
			}
		}
		
		
	}
	printf("m=%d n=%d x=%d y=%d a=%d b=%d",m,n,x2,y2,a,b);
	if ((a>m)||(a<0)||(b>n)||(b<0))
		printf("gresit m=%d n=%d x=%d y=%d a=%d b=%d",m,n,x2,y2,a,b);
	}
}
