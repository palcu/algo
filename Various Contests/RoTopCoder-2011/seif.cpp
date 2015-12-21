/****************************************************
 * Name: Alexandru Palcuie
 * Website: http://palcu.blogspot.com/
 * Year: 2011
 * Contest: RoTopCoder
 * Problem: seif
*****************************************************/

#include <cstdio>
#include <cstring>

int main(){
	freopen("seif.in","r",stdin);
	freopen("seif.out","w",stdout);
	
	//Constants
	const int NMAX = 12;
	const unsigned int MAX_INT = 2<<29;
	
	//Should be Global but...
	unsigned i,x;
	unsigned n, nCifre;
	bool cifre[NMAX];
	memset(cifre,0,sizeof(cifre));
	
	//Read
	scanf("%u%u",&n,&nCifre);
	for(i=0;i<nCifre;++i){
		scanf("%u",&x);
		cifre[x] = true;
	}
	
	//Solve
	unsigned nCicluri=0;
	const unsigned maxCicluri=450000;
	bool isGood,hasPrinted = false;
	for(i=n; nCicluri<maxCicluri && i<MAX_INT; ++nCicluri,i+=n){
		x=i; 
		isGood = true;
		while(x){
			if (!cifre[x%10]){
				isGood = false;
				break;
			}
			x/=10;
		}
		if (isGood){
			printf("%u\n",i);
			hasPrinted = true;
			break;
		}
	}
	
	//Print
	if (!hasPrinted)
		printf("0\n");
	
	return 0;
}
