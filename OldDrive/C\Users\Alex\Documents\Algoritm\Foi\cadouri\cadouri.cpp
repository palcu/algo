#include <cstdio>

int cadou[100], s[10000], a[101];

void recon(int i)
{
	if (s[i]>0)
	{
		recon (i-cadou[s[i]]);
		printf("%d ",cadou[s[i]]);
		a[s[i]]=1;
	}
}

int main()
{
	freopen("date.in","r",stdin);
	int n,i,j,suma=0;
	scanf("%d",&n);
	for (i=1; i<=n; ++i) {
		scanf("%d",&cadou[i]); suma+=cadou[i];}
	
	for (i=0; i<=10000; ++i) s[i]=101;
	s[0]=0;
	
	for (i=1; i<=n; ++i)
		for (j=0; j<=suma/2-cadou[i]; ++j)
			if (s[j] < i && s[j+cadou[i]] == 101)
				s[j+cadou[i]]=i;
	
	for (j=suma/2; j>=0; --j)
		if (s[j]!=101)
		{
			printf("%d %d\n",j,suma-j);
			recon(j);
			break;
		}
	for (i=1; i<=n; ++i)
		if (!a[i]) printf("%d ",cadou[i]);
	return 0;
}
