#include <cstdio>
#include <cstring>

int main()
{
	freopen ("palc.in","r",stdin);
	freopen ("palc.out","w",stdout);
	
	int n,ok=0,jum,perm=0,i,aux,perm2=0,direct,ok2=0;
	char s[201],s2[201];
	
	scanf("%s",s); strcpy(s2,s);
	n=strlen(s);
	jum=n/2;
	
	for (i=0; i<jum; i++)
	{
		if (s[i]!=s[n-i])
			direct=0;
	}
	if (!direct)
	{
		while ((perm<n-1)&&(!ok))
		{
			++perm; ok=1;
			for (i=n-1; i>=0; i--)
				s[i+1]=s[i];
			s[0]=s[n];
			for (i=0; i<jum; i++)
				if (s[i]!=s[n-i-1])
					ok=0;
		}
	
		while ((perm2<n-1)&&(!ok2))
		{
			++perm2;
			ok2=1; aux=s2[0]; --n;
			for (i=0; i<n; i++)
				s2[i]=s2[i+1];
			s2[n]=aux;
			for (i=0; i<jum; i++)
				if (s2[i]!=s2[n-i])
					ok2=0;
			++n;
		}
	}
	if ((!direct)&&(!ok)&&(!ok2))
		printf("-1");
	else
	{
		if ((perm<perm2)&&(perm))
			printf("%d",perm);
		else
			printf("%d",perm2);
	}
	
	return 0;
}
