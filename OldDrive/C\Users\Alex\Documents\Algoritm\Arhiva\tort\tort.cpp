#include <cstdio>
using namespace std;
int main()
{
	freopen ("tort.in","r",stdin);
	freopen ("tort.out","w",stdout);
	int m,n,r,min,m2,n2;
	scanf("%d%d",&m,&n);
	m2=m; n2=n;
	while (n2!=0)
	{
		r=m2%n2;
		m2=n2;
		n2=r;
	}
	min=m/m2*n/m2;
	printf("%d %d",min,m2);	
	return 0;
}
