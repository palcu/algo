#include <cstdio>
using namespace std;
int main()
{
	freopen("barca.in","r",stdin);
	freopen("barca.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	printf("%d\n",4*n);
	for (i=1; i<=n; i++)
	{
		printf("IG\n");
		printf("I\n");
		printf("%d\n",i);
		printf("G\n");
	}
	
	return 0;
}
