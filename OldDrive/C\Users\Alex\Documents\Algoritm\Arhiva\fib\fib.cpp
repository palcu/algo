#include <cstdio> 
int main() 
{ 
    freopen("fib.in","r",stdin); 
    freopen("fib.out","w",stdout); 
    int cif=2,n,i; 
    int a[100],b[100],c[100];
	a[0]=1; b[0]=1; a[1]=1; b[1]=1; c[0]=1; c[1]=2;
	scanf("%d",&n);
	while (cif<n)
	{
		if (b[0]>a[0])
			a[b[0]]=0; c[b[0]+1]=0;
		for (i=1; i<=b[0]; i++)
		{
			c[i]=a[i]+b[i];
			if (c[i]>9)
			{
				++c[i+1];
				c[i]=c[i]%10;
			}
			a[i]=b[i];
			b[i]=c[i];
		}
		a[0]=b[0];
		if (c[b[0]+1]==1)
		{
			++b[0];
			b[b[0]]=1;
		}
		cif+=b[0];
	}
	n=cif-n+1;
	printf("%d",b[n]);
    return 0; 
} 
