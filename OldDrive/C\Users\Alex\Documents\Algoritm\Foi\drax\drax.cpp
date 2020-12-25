#include <iostream>
using namespace std;

int st[100];
int n,p;

int valid(int k)
{
for(int i=1;i<k;i++) if(st[i]==st[k]) return 0;
return 1;
}

int solutie(int k) {return k==n;}

void tipar() {for(int i=1;i<=n;i++) cout<<st[i]<<" "; cout<<"\n";}

void back(int k)
{
	for(int i=1;i<=p;i++)
	{
	st[k]=i;
	if(valid(k))
		{
			if(solutie(k))
			tipar();
			else if(k<n) back(k+1);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&p);
	back(1);
	return 0;
}
