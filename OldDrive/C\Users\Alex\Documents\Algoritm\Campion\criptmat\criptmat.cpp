#include <cstdio>
#include <string>


char sir[200];
char matrice[50][50];

int main()
{
	freopen ("criptmat.in","r",stdin);
	freopen ("criptmat.out","w",stdout);

	int i,j,n,lg,grupe,tur=1,k;
	
	
	scanf("%d%s",&n,sir);
	lg=strlen(sir);
	grupe=lg/n;
	
	for (i=0; i<grupe; ++i)
	{
		if (tur>0)
		for (j=0; j<n; ++j)
			matrice[i][j]=sir[n*i+j];			
		else
		for (j=n-1, k=0; j>=0; --j, ++k)
			matrice[i][k]=sir[n*i+j];
		tur=-tur;
	}
	
	for (i=0; i<n; ++i)
		for (j=0; j<grupe; ++j)
			printf("%c",matrice[j][i]);
	
	return 0;
}
