#include <cstdio>
using namespace std;
int main()
{
	freopen("suma.in","r",stdin);
	freopen("suma.out","w",stdout);
	int n;
	int x,y,i;
	scanf("%d",&n);
	if (n==1)
		printf("1\n1");
	else
	{
	printf("1");
	n--;
	x=n/9;
	y=n-x-1;
	for (i=1; i<=y; i++)
		printf("0");
	printf("%d",n%9);
	for (i=1; i<=x; i++)
		printf("9");
	
	printf("\n");	
	n++;
	x=n/9;
	y=n-x-1;
	for (i=1; i<=x; i++)
		printf("9");
	printf("%d",n%9);
	for (i=1; i<=y; i++)
		printf("0");
	}
	return 0;
}
