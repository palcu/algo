#include <cstdio>
#include <cmath>

int main()
{
	freopen("control1.in","r",stdin);
	freopen("control1.out","w",stdout);
	
	int a,b,c,a2,s,nr=0,dif;
	
	scanf("%d%d%d",&a,&b,&c);
	a2=a; 
	while (a2>9)
	{
		s=0;
		while (a2!=0)
		{
			s+=a2%10;
			a2/=10;
		}
		a2=s;
	}
	dif=c-a2; if(dif<0) dif=-dif;
	nr=(b-a+dif)/9;
	
	printf("%d",nr);
	return 0;
}
