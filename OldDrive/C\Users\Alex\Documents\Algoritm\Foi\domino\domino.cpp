#include <cstdio>

typedef struct piesa{int n1,n2;} PIESA;

PIESA vp[1000];
int suc[1000][2];
int v[1000][2];

void recon(int i)
{
	i=succ[i][bit]
}

int main()
{
	freopen("date.in","r",stdin);
	int i=0,j,bit=0,min;
	
	while (!feof(stdin))
	{
		scanf("%d%d",&vp[i].n1,&vp[i].n2);
		++i;
	}
	int n=i-1;
	int imax=n-1;
	v[n-1][0]=1; suc[n-1][0]=n;
	v[n-1][1]=1; suc[n-1][1]=n;
	
	for (i=n-2; i>=0; --i)
	{
		v[i][0]=1; suc[i][0]=n;
		v[i][1]=1; suc[i][1]=n;
		for (j=i+1; j<n; ++j)
		{
			if (vp[j].n1==vp[i].n2 && v[i][0]<v[j][0]+1)
			{
				v[i][0]=v[j][0]+1;
				suc[i][0]=j;
			}
			
			if (vp[j].n2==vp[i].n2 && v[i][0]<v[j][1]+1)
			{
				v[i][0]=v[j][1]+1;
				suc[i][0]=j;
			}
			
			if (vp[j].n1==vp[i].n1 && v[i][1]<v[j][0]+1)
			{
				v[i][1]=v[j][0]+1;
				suc[i][1]=j;
			}
			
			if (vp[j].n2==vp[i].n1 && v[i][1]<v[j][1]+1)
			{
				v[i][1]=v[j][1]+1;
				suc[i][1]=j;
			}
		}
		min=v[i][0]>v[i][1]?v[i][0]:v[i][1];
		if (min>v[imax][bit])
		{
			imax=i;
			bit=v[i][0]>=v[i][1]?0:1;
		}
	}
	
	if (bit) printf("%d %d\n",vp[imax].n2,vp[imax].n1);
	else printf("%d %d\n",vp[imax].n1,vp[imax].n2);
	
	recon(imax);
	
	return 0;
}
