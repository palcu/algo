#include <cstdio>
#include <iostream>

//EIUCLAP -> I am your idol

using namespace std;

const int NMAX=65000;
int n,v[3][NMAX],nlg[3],solatij;

/*bool verifok(){
	int i;
	for(i=0,j=n;i<n;++i,--j)
		if(v[solatij][i])!=j;
			return false;
	return true;
}*/

int main()
{
	freopen("turnuri.in","r",stdin);
	freopen("turnuri.out","w",stdout);
	
	//Variables
	int sola,solaa;//solution a
	int i,j;//cycle
	
	//Read
	scanf("%d%d%d%d",&n,&nlg[0],&nlg[1],&nlg[2]);
	for(i=0;i<3;++i){
		for(j=0;j<nlg[i];++j)
			scanf("%d",&v[i][j]);
	}
	
	//Verify
	i=0; bool ok=true;
	do{
		for(j=0;j<nlg[i];++j)
			if(v[i][j]==n){
				sola=j; ok=false;
				solatij=i;
				break;
			}
		if (!ok){ //daca am gasit tija mare
			solaa=min(sola,nlg[(i+1)%3]);
			if(solaa!=sola){
				solatij=(i+1)%3;
				sola=solaa;}
			solaa=min(sola,nlg[(i+2)%3]);
			if(solaa!=sola){
				solatij=(i+2)%3;
				sola=solaa;}
		}
	}
	while (i++<3 && ok);
	printf("%d\n0\n",solatij+1);
	return 0;
}
