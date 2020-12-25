#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	freopen("roci.in","r",stdin);
	freopen("roci.out","w",stdout);
	long n,i;
	int v[100000],v2[100000],x,max=0,ok=0,max2=0,g=0;;
	scanf("%d",&n);
	for (i=0; i<n; i++)
		scanf("%d",&v[i]);
	sort(&v[0],&v[n]);
	for (i=0; i<n; i++)
		printf("%d",v[i]);
	return 0;
}
