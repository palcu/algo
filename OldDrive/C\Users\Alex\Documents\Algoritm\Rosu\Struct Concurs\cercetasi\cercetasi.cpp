#include <cstdio>
using namespace std;
int main()
{
	freopen("cercetasi.in","r",stdin);
	freopen("cercetasi.out","w",stdout);
	int d1,n1,d2,n2,t1,t2,rest;
	scanf ("%d%d%d%d",&d1,&n1,&d2,&n2);
	t1=n1*d1;
	t2=n2*d2;
	n1=t1;
	n2=t2;
	while (rest!=t2)
	{
		rest=t1%t2;
		t1=t2;
		t2=rest;
	}
	d1=n1/t1;
	d2=n2/t1;
	printf("Nr cercetasi detasament = %d \n",t1);
	printf("Det in Galaciuc = %d \n",d1);
	printf("Det in Soveja = %d \n",d2);
	
	return 0;
}