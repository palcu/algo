#include <cstdio>
#include <string>

struct string {char st[2]; char dr[2];};
string cuv[1000];

typedef char string2[1000];
string2 big[1000];

int v[1000], pred[1000];

bool bine(int i, int j)
{
	if (cuv[i].st[0]!=cuv[j].dr[0]) return 0;
	if (cuv[i].st[1]!=cuv[j].dr[1]) return 0;
	return 1;
}

int recon(int i)
{
	if (pred[i]+1) recon(pred[i]);
	printf("%s ",big[i]);
}

int main()
{
	freopen("date.in","r",stdin);
	int i=0,j,lg,n=0,imax=0;
	char a[15];
	
	while(!feof(stdin))
	{
		scanf("%s",big[i]);
		cuv[i].st[0]=big[i][0];
		cuv[i].st[1]=big[i][1];
		lg=strlen(big[i]);
		cuv[i].dr[1]=big[i][lg-1];
		cuv[i].dr[0]=big[i][lg-2];
		++i;
	}
	n=i-1;
	
	pred[0]=-1; v[0]=1;
	for (i=0; i<n; ++i)
	{
		v[i]=1; pred[i]=-1;
		for (j=0; j<i; ++j)
			if (bine(i,j) && v[j]+1>v[i])
			{
				v[i]=v[j]+1;
				pred[i]=j;
			}
		if (i>imax) imax=i;
	}
	
	printf("%d\n",v[imax]);
	recon(imax);
	
	return 0;
}
