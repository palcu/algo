#include <cstdio>

int v[1000];

int main()
{
	freopen("grad.in","r",stdin);
	freopen("grad.out","w",stdout);
	
	int a,b,nrcuv=0,gr=0,i,j,n;
	int s=0;
	bool ok;
	
	scanf("%d",&n);
	scanf("%c",&a);
	for (j=1; j<=n; ++j)
	{
		scanf("%c",&a);
		if (a!=32)
			s+=(int)a-96;
		else if(s)
		{
			ok=1; ++nrcuv;
			for (i=1; i<=gr; ++i)
				if (s==v[i]) {ok=0; break;}
			if (ok) {++gr; v[gr]=s;}
			s=0;
		}
	}
	
	++nrcuv; ok=1;
	for (i=1; i<=gr; ++i)
		if (s==v[i]) {ok=0; break;}
	if (ok) {++gr; v[gr]=s;}
	
	printf("%d\n%d",nrcuv,gr);
	return 0;
}
