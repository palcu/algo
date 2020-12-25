//cu 3 si 7, primele n numere

#include <cstdio>
#include <bitset>

using namespace std;
int a[1000];

int main()
{
	
	int n,n3=3,n7=7,i=1,j=1,k,t;
	scanf("%d",&n); a[1]=1;
	
	for (k=2;i<=n;++k)
	{
		if (n3<=n7) t=n3;
		else t=n7;
		
		a[k]=t;
		printf("%d ",t);
		
		if (n3==t) n3=3*a[++i];
		if (n7==t) n7=7*a[++j];
	}
}
