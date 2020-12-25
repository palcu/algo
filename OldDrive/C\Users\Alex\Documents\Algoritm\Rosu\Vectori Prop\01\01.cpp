#include <cstdio>
using namespace std;
int main()
{
	freopen("14.in","r",stdin);
	freopen("14.out","w",stdout);
	int n,i,v[100],st,dr,lmax,stmax,drmax;
	scanf("%d",&n);
	st=0; dr=0; lmax=0; drmax=0;
	for (i=0; i<n; i++)
		scanf("%d",&v[i]);
	
	for (i=0; i<n; i++)
	{
		if (v[i]<0)
		{
			if (v[i-1]>0)
			{
				if (dr-st-1>lmax)
					lmax=dr-st-1;
				stmax=st; drmax=dr-1;
			}
			st=i+1; dr=i+1;
		}
		else
			dr++;
	}
	for (i=stmax; i<=drmax; i++)
		printf("%d ",v[i]);
	return 0;	
}
