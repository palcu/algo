#include <cstdio>

int v[1000],a[1000],urm[1000];

void recon(int i)
{
	if(urm[i]+1) recon(urm[i]);
	printf("%d ",a[i]);
}

int main()
{
	freopen("date.in","r",stdin);
	
	int i,j,imax=0;
	int n; scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",&a[i]);
	
	urm[n-1]=-1; v[n-1]=1;
	for (i=n-2; i>=0; --i)
	{
		v[i]=1; urm[i]=-1;
		for (j=i+1; j<n; ++j)
			if (a[j]>a[i] && v[j]+1>v[i])
			{
				v[i]=v[j]+1;
				urm[i]=j;
			}
		if(v[i]>v[imax])imax=i;
	}
	
	printf("%d\n",v[imax]);
	recon(imax);
	return 0;
}
