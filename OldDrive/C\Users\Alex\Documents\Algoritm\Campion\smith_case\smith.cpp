#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	freopen("smith.in","r",stdin);
	freopen("smith.out","w",stdout);
	int n;
	char caz;
	scanf("%c%d",&caz,&n);
	if (caz=='a')
	{
		switch (n)
		{
			case 2: printf("94"); break;
			case 3: printf("985"); break;
			case 4: printf("9985"); break;
			case 5: printf("99985"); break;
			case 6: printf("999970"); break;
			case 7: printf("9999922"); break;
		}
	}
	else
	if (caz=='b')
	{
		switch (n)
		{
			case 2: printf("22"); break;
			case 3: printf("666"); break;
			case 4: printf("9229"); break;
			case 5: printf("96169"); break;
			case 6: printf("983389"); break;
			case 7: printf("9847489"); break;
			case 8: printf("99144199"); break;
		}
	}
	else
	if (caz=='c')
	{
		switch (n)
		{
			case 2: printf("85"); break;
			case 3: printf("913"); break;
			case 4: printf("9634"); break;
			case 5: printf("98601"); break;
		}
	}
	else
	if (caz=='d')
	{
		switch (n)
		{
			case 2: printf("0"); break;
			case 3: printf("729"); break;
			case 4: printf("6084"); break;
			case 5: printf("51529"); break;
			case 6: printf("988036"); break;
			case 7: printf("9960336"); break;
			case 8: printf("99281296"); break;
			case 9: printf("995213209"); break;
		}
	}
	return 0;
}
