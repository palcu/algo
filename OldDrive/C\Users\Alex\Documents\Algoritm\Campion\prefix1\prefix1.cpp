#include <cstdio>
#include <string>

#define LG_MAX 100000
int rest[101];

int main()
{
	freopen("prefix1.in","r",stdin);
	freopen("prefix1.out","w",stdout);
	
	char s[LG_MAX];
	int v[LG_MAX+1], k, max=0;
	long i, r=0;
	
	scanf("%d",&k);
	
	scanf("%s",s);
	v[0]=strlen(s);
	for (i=0; i<=v[0]; i++) 
		v[i+1] = s[i]-'0';	
	
	for (i=1; i<=v[0]; i++)
	{
		r=(r*10+v[i])%k;
		++rest[r];
		if (rest[r]>rest[max])
			max=r;
	}
	
	printf("%d %d",max,rest[max]);
	
	return 0;
}
