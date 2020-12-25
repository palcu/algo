#include <cstdio>
using namespace std;
int main()
{
	freopen("timer.in","r",stdin);
	freopen("timer.out","w",stdout);
	long int h=0,m=0,s=0,a=-1,b=-1,c=-1,z=0;
	scanf("%ld:%ld:%ld",&h,&m,&s);
	scanf("%ld:%ld:%ld",&a,&b,&c);
	if (c==-1)
	{
		if (b==-1)
		{
			c=a;
			b=0;
			a=0;
		}
		else
		{
			c=b;
			b=a;
			a=0;
		}
	}
	s+=c;
	m+=b;
	h+=a;
	if (s>59)
	{
		m+=s/60;
		s=s%60;
	}
	if (m>59)
	{
		h+=m/60;
		m=m%60;
	}
	if (h>23)
	{
		z=h/24;
		h=h%24;
	}
	if (h<10)
		printf("0%ld:",h);
	else
		printf("%ld:",h);
	if (m<10)
		printf("0%ld:",m);
	else
		printf("%ld:",m);
	if (s<10)
		printf("0%ld",s);
	else
		printf("%ld",s);
	if (z>0)
		printf("+%ld",z);
	return 0;
}
