#include <cstdio>

int v[100000],a[100000],pred[100000];

void recon(int i)
{
	if(pred[i]+1) recon(pred[i]);
	printf("%d ",a[i]);
}

int main()
{
	freopen("scmax.in","r",stdin);
	freopen("scmax.out","w",stdout);
	
	int i,j,imax=0; v[0]=1; pred[0]=-1;
	
	int n; scanf("%d",&n);
	for (i=0; i<n; ++i) scanf("%d",&a[i]);
	
	for (i=1; i<n; ++i)
	{
		v[i]=1;
		pred[i]=-1;
		for (j=0; j<i; ++j)
			if ( a[j]<a[i] && v[j]+1>v[i])
			{
				v[i]=v[j]+1;
				pred[i]=j;
			}
		if (v[i]>v[imax]) imax=i;
	}
	
	printf("%d\n",v[imax]);
	recon(imax);
	
	
	return 0;
}
