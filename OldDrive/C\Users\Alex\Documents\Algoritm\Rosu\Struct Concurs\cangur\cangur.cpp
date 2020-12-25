#include <cstdio>
using namespace std;
int main()
{
	freopen("cangur.in","r",stdin);
	freopen("cangur.out","w",stdout);
	int n,i,s=7,z=7;
	scanf("%d",&n);
	if (z>1)
	{
		for (i=1; i<n; i++)
		{
			z=z*10+7;
			s+=z;
		}
		printf("%d",s);
	}
	else
	printf("7");
	return 0;
}
