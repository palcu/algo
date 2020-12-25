#include <cstdio>

int a[500000];

int main()
{
	int i,t,n,n2,n3,n5,l,j,k,alex;
	
	scanf("%d",&n);
	n2=2; n3=3; n5=5; i=1; j=1; k=1; a[1]=1; t=1; l=1;
	
	for (alex=1; t<=n; ++alex)
	{
		if (n2<=n3)
			if (n2<=n5)	t=n2;
			else t=n5;
		else
			if (n3<=n5) t=n3;
			else t=n5;
		++l;
		a[l]=t;
		if (n2==t) n2=2*a[++i];
		if (n3==t) n3=3*a[++j];
		if (n5==t) n5=5*a[++k];
	}
	
	for (i=1; i<=alex; ++i)
		printf("%d ",a[i]);
	
	return 0;
}
