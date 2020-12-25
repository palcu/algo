#include <cstdio>
using namespace std;
int main()
{
	freopen("petrol.in","r",stdin);
	freopen("petrol.out","w",stdout);
	int E,D,n; //n char
	float e[100],d[100],s=0;
	int i,j;
	scanf("%d%d%d",&n,&E,&D);
	
	for (i=0; i<n; i++)
	{
		scanf("%f%f",&e[i],&d[i]);
		e[i]=E/e[i];
		d[i]=D/d[i];
	}
	
	if (n==1)
		e[0]>d[0] ? s=e[0] : s=d[0];
	else
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (i!=j)
			{
				if (e[i]+d[j]>s)
					s=e[i]+d[j];
			}
		}
	}
	printf("%.3f",s);
	return 0;
}
