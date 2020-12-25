#include <cstdio>
#include <ctime>
#include <cstdlib>

void generare();
int main()
{
	srand(time(NULL));
	generare();
	freopen("biliard.in","r",stdin);
	freopen("biliard.out","w",stdout);
	
	long m, n, x, y, t, a=0, b=0, timp=0, i, x2, y2;
	int buzunar=0;
	
	for (i=1; i<1000; ++i)
	{
		scanf("%ld%ld%ld%ld%ld", &m, &n, &x, &y, &t);
		a=0; b=0; timp=0; buzunar=0; x2=x; y2=y;
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
		printf("m=%d n=%d x=%d y=%d\n",m,n,x2,y2);
		if (!buzunar)
			if ((a>m)||(b>n))
				printf("gresit m=%d n=%d x=%d y=%d\n",m,n,x2,y2);
	}
	
	return 0;
}

void generare()
{
	freopen("biliard.in","w",stdout);
	int m,n,x,y,t,i;
	/*
	for (i=1; i<100; i++)
	{
		m=rand()%10000;
		n=rand()%10000;
		x=rand()%m;
		y=rand()&n;
		t=rand()%100+20;
		printf("%d %d %d %d %d\n",m,n,x,y,t);
	}
	*/
	for (m=2; m<=10; m++)
		for (n=2; n<=10; n++)
			for (x=1; x<=10; x++)
				for (y=1; y<=10; y++)
					printf("%d %d %d %d 100\n",m,n,x,y);
}
