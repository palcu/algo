#include <cstdio>

int putere(int a, int n)
{
	int x;
	if (!n) return 1;
	if (n==1) return a;
	x=putere(a,n/2);
	if (!(n%2)) return x*x;
	return x*x*a;
}

int main()
{
	int a,n;
	scanf("%d%d",&a,&n);
	printf("%d",putere(a,n));
	return 0;
}