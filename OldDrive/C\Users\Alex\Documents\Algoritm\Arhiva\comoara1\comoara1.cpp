#include <cstdio>
using namespace std;
int main()
{
	freopen("comoara1.in","r",stdin);
	freopen("comoara1.out","w",stdout);
	int a[1001],n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for (i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	for (i=1; i<=m; ++i)
	{
		for (j=0; j<n && a[j]>=a[j+1]; ++j);
		for (k=j; k<n; ++k)
			a[k]=a[k+1];
		--n;
	}
	
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}
