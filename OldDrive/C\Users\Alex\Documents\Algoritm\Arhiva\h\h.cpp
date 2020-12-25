#include <cstdio>
using namespace std;
int main()
{
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		printf("%d ",i);	
	for (i=3*n+1; i<=4*n; i++)
		printf("%d ",i);	
	return 0;
}
