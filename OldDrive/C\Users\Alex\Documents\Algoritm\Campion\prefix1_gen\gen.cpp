#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
	freopen("prefix1.in","w",stdout);
	long i;
	int n;
	srand(time(NULL));
	printf("100\n");
	printf("1");
	for (i=1; i<=99999; i++)
	{
		n=rand()%10;
		printf("%d",n);
	}
	return 0;
}
