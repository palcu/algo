#include <cstdio>

int main()
{
	freopen("cabina.in","r",stdin);
	freopen("cabina.out","w",stdout);
	
	int n,a,a2,b,i,schimbari=0,pers,s=0,directie=0;
	scanf("%d",&n);
	scanf("%d%d",&a2,&pers);
	for (i=1; i<n; i++)
	{
		scanf("%d%d",&a,&b);
		pers+=b;
		if (a>a2)
		{
			s+=3*(a-a2);
			if (directie<0)
				++schimbari;
			directie=1;
		}
		else
		{			
			s+=a2-a;
			if (directie>0)
				++schimbari;
			directie=-1;
		}
		a2=a;
	}
	
	printf("%d\n%d\n%d",pers,s,schimbari);
	return 0;
}
