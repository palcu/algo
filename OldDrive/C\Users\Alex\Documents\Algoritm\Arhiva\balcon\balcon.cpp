#include <cstdio>
#include <algorithm>
#include <cmath>
int v[300],mat[25][25];
int main()
{
	int n,i,x,a,b,c,d;
	scanf("%d",&n);
	n*=n;
	for (i=1; i<=n; ++i)
		scanf("%d",&v[i]);
	sort(v+1,v+n+1);
	n=sqrt(n);
	a=c=1;
	b=d=n;
	d=1; contor=1;
	while (contor<=n)
	{
		switch(d)
		{
		case 1:
			for (i=a; i<=b; ++i)
				mat[a][i]=