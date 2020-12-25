#include <cstdio>

int a[1000],v[1000],pred[1000],s[1000];
bool bit[1000];
int main()
{
	freopen("date.in","r",stdin);
	int n,nn; scanf("%d",&n);
	int i,ii,j,max=0,s=0,per=0;
	bool ok=0;
	for (i=1; i<=n; ++i) 
	{ 
		scanf("%d",&a[i]); s+=a[i];
		if (a[i]>max) max=a[i];
	}
	
	for (nn=n/2; max<=nn; ++max)
		if (!(s%max)) {ok=1; break;}
	
	if (!ok)printf ("toate nr");
	else
	{
		//scoatem valorile egale
		for (i=1; i<=n; ++i) if (i==max) {bit[i]=1; printf("%d\n",max); ++per;	}
		// vector de booleni
		for (i=1; i<=n; ++i)
		{
			if (i!=max && !bit[i])
			{
				bit[i]=1; ok=0;
				
				
			}
		}
		printf("%d",max);
	}
		
		
	return 0;
	
}
