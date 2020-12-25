#include <cstdio>
#include <string>

char x[101],y[101],z[101],n1[101],n2[101],n3[101],xy[101],yz[101],xyz1[101],xyz2[101];

void convert (char orig[101],char conv[101]);
void sum (char a[101], char b[101], char c[101]); //a+b=c
bool verif (char a[101], char b[101]);
void afis (char v[101]);

int main()
{
	freopen ("asociativ.in","r",stdin);
	freopen ("asociativ.out","w",stdout);
	
	char n,i;
	
	scanf("%d",&n);
	
	for (i=1; i<=n; ++i)
	{
		scanf("%s%s%s",n1,n2,n3);
		
		convert(n1,x); convert(n2,y); convert(n3,z);
		
		sum(x,y,xy); sum(xy,z,xyz1);
		sum(y,z,yz); sum(yz,x,xyz2);
		
		if (verif(xyz1,xyz2))
			afis(xyz1);
		else
			printf("0\n");
	}
	
	return 0;
}

void convert (char orig[101],char conv[101])
{
	conv[0]=strlen(orig);
	for (char i=conv[0]-1; i>=0; --i)
		conv[conv[0]-i] = orig[i]-'0';
}

void sum (char a[101], char b[101], char c[101])
{
	char j,i;
	if (a[0]>b[0]) c[0]=a[0];	//operatii de atribuie (face adunari cu 0)
	else c[0]=b[0];
	
	for (i=1, j=1; i<=c[0]; ++i, ++j)
	{
		c[j]=a[i]+b[i];
		if (c[j]/10)
		{
			c[j]%=10;
			++j;
			c[j]=1;
		}
	}
	c[0]=j-1;
}

bool verif (char a[101], char b[101])
{
	if (a[0]==b[0])
	{
		for (char i=1; i<=a[0]; ++i)
			if (a[i]!=b[i]) return 0;
		return 1;
	}
	return 0;
}	

void afis (char v[101])
{
	for (char i=v[0]; i>0; --i)
		printf("%d",v[i]);
	printf("\n");
}
