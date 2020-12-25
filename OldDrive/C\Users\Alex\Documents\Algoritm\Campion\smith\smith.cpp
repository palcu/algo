#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	freopen("smith.in","r",stdin);
	freopen("smith.out","w",stdout);
	
	int i,sc,sf,nrcif,ok,i2,si,n4,n5,nrad;
	long n,n2,n3;
	char caz;
	
	scanf("%c%d",&caz,&nrcif);
	
	n=9;
		for (i=1; i<nrcif;i++)
			n=n*10+9;
	
	if (caz=='a')
	{
		n=9;
		for (i=1; i<nrcif;i++)
			n=n*10+9;
		ok=0;
		while (ok==0)
		{
			sc=0; sf=0;
			n2=n;
			while (n2!=0)
			{
				sc+=n2%10;
				n2/=10;
			}
			n3=n;
			while (n3%2==0)
			{
				sf+=2;
				n3/=2;
			}
			i=3;
			while ((n3>1)&&(i<n))
			{
				if (n3%i==0)
				{
					si=0;
					i2=i;
					while (i2!=0)
					{
						si+=i2%10;
						i2/=10;
					}
					while (n3%i==0)
					{
						sf+=si;
						n3/=i;
					}
				}
				i+=2;
			}
			
			if (sc==sf)
			{
				printf("%d",n);
				ok=1;
			}
			else
				n--;
		}
	}
	else
	if (caz=='b')
	{
		ok=0;
		while (ok==0)
		{
			n4=n; n5=0;
			while (n4!=0)
			{
				n5=n5*10+n4%10;
				n4/=10;
			}
			if (n==n5)
			{
				sc=0; sf=0;
				n2=n;
				while (n2!=0)
				{
					sc+=n2%10;
					n2/=10;
				}
				n3=n;
				while (n3%2==0)
				{
					sf+=2;
					n3/=2;
				}
				i=3;
				while ((n3>1)&&(i<n))
				{
					if (n3%i==0)
					{
						si=0;
						i2=i;
						while (i2!=0)
						{
							si+=i2%10;
							i2/=10;
						}
						while (n3%i==0)
						{
							sf+=si;
							n3/=i;
						}
					}
				i+=2;
				}
			
				if (sc==sf)
				{
					printf("%d",n);
					ok=1;
				}
				else
					n--;
			}
			else
				n--;
		}
	}
	else
	if (caz=='c')
	{
		ok=0;
		while (ok==0)
		{
			n4=n; n5=0;
			while (n4!=0)
			{
				n5=n5*10+n4%10;
				n4/=10;
			}
			if (n!=n5)
			{
				sc=0; sf=0;
				n2=n;
				while (n2!=0)
				{
					sc+=n2%10;
					n2/=10;
				}
				n3=n;
				while (n3%2==0)
				{
					sf+=2;
					n3/=2;
				}
				i=3;
				while ((n3>1)&&(i<n))
				{
					if (n3%i==0)
					{
						si=0;
						i2=i;
						while (i2!=0)
						{
							si+=i2%10;
							i2/=10;
						}
						while (n3%i==0)
						{
							sf+=si;
							n3/=i;
						}
					}
					i+=2;
				}
			
				if (sc==sf)
				{
					sc=0; sf=0;
					n2=n5;
					while (n2!=0)
					{
						sc+=n2%10;
						n2/=10;
					}
					n3=n5;
					while (n3%2==0)
					{
						sf+=2;
						n3/=2;
					}
					i=3;
					while ((n3>1)&&(i<n5))
					{
						if (n3%i==0)
						{
							si=0;
							i2=i;
							while (i2!=0)
							{
								si+=i2%10;
								i2/=10;
							}
							while (n3%i==0)
							{
								sf+=si;
								n3/=i;
							}
						}
						i+=2;
					}
			
					if (sc==sf)
					{
						printf("%d",n);
						ok=1;
					}
					else
						n--;
					}
				else
					n--;
			}
			else
				n--;
		}
	}
	else
	if (caz=='d')
	{
		n=9;
		for (i=1; i<nrcif;i++)
			n=n*10+9;
		nrad=(int)sqrt(n);
		ok=0;
			while (ok==0)
			{
				n=nrad*nrad;
				sc=0; sf=0;
				n2=n;
				while (n2!=0)
				{
					sc+=n2%10;
					n2/=10;
				}
				n3=n;
				while (n3%2==0)
				{
					sf+=2;
					n3/=2;
				}
				i=3;
				while ((n3>1)&&(i<n))
				{
					if (n3%i==0)
					{
						si=0;
						i2=i;
						while (i2!=0)
						{
							si+=i2%10;
							i2/=10;
						}
						while (n3%i==0)
						{
							sf+=si;
							n3/=i;
						}
					}
					i+=2;
				}
			
				if (sc==sf)
				{
					printf("%d",n);
					ok=1;
				}
				else
					nrad--;
			}
	}
	return 0;
}
