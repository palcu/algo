#include <cstdio> 
#include <cmath> 
short int a[60000]; 

int main() 
{ 
    freopen("factori.in","r",stdin); 
    freopen("factori.out","w",stdout); 
	
    int n,nr; 
	
    scanf("%d",&n); 
    do 
    {
		if (!(n%2))
		{
			nr=0;
			p=2;
			while (n/p)
			{
				nr+=(int)n/p;
				p*=p;
			}
			while (!(n%2))
				n/=2;
			printf("%d ",&nr);
		}
		
		p=3
		while (n!=1)
		{
			
		
		
		
		scanf("%d",&n); 
    } 
    while (n); 
    return 0; 
} 