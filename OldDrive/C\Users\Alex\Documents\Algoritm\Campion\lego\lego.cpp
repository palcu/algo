#include <cstdio>
#include <cmath>

int v[100];

int main()
{
	freopen ("lego.in","r",stdin);
	freopen ("lego.out","w",stdout);
	int alt=-1,n,paritate,s,i,suma=0,posibil;
	float magic;
	scanf("%d%d%d",&n,&v[1],&v[0]);
	paritate=(v[0]-v[1]%2)%2;
	
	posibil=1;
	switch (v[0]%4)
	{
	case 0:
			if (n%2) posibil=0; break;
		case 1:
		{
			switch (v[1]%2)
			{
				case 0:
					if (n%2) posibil=0; break;
				case 1:
					if (!(n%2)) posibil=0; break;
			}
			break;
		}
		case 2:
			if (!(n%2)) posibil=0; break;
		case 3:
		{
			switch (v[1]%2)
			{
				case 0:
					if (!(n%2)) posibil=0; break;
				case 1:
					if (n%2) posibil=0; break;
			}
			break;
		}
	}
	
	
	
	/*if (n%2!=paritate)
		printf("0");
	else*/
	if (posibil)
	{
		s=v[1];
		for (i=2; i<=v[0]; ++i)
		{
			magic=(n-s)/(v[0]-i+1);
			if (magic>v[i-1])
				v[i]=v[i-1]+1;
			else
				v[i]=v[i-1]-1;
			s+=v[i];
			/*
			if (v[i]==v[i-1])
			{
				v[i]+=alt;
				s+=alt;
				alt*=-1;
			}
			*/
		}
	}
	//daca mai raman
	if (s)
	{
		for (i=2; i<=n && n-s; ++i)
		{
			if (v[i-1]==v[i+1])
			{
				v[i]+=2;
				s+=2;
			}
		}
	}
	
	if (posibil)
	{
	for (i=1; i<=v[0]; ++i)
	{
		printf("%d\n",v[i]);
		suma+=v[i];
	}
	printf("%d",suma);
	}
	else
		printf("0");
	return 0;
}
