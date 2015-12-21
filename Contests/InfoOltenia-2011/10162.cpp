#include <cstdio>
#include <iostream>
#include <algorithm>

//EIUCLAP -> I am your idol

using namespace std;

const int NMAX=100000;
struct Carte{short int x,y;} v[NMAX];

bool cmp(Carte x, Carte y){
	if (x.x!=y.x)
		return x.x<y.x;
	return x.y<y.y;
}

inline void reverse_order(short int &x, short int &y){
	short int aux=x;
	x=y;
	y=aux;
	return;
}

int main()
{
	freopen("carti.in","r",stdin);
	freopen("carti.out","w",stdout);
	
	//Variables
	int n;
	int s=0; //solution
	int i;//cycle
	
	//Read
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%hd%hd",&v[i].x,&v[i].y);
		if (v[i].x>v[i].y)
			reverse_order(v[i].x,v[i].y);
	}
	
	//Body
	sort(v,v+n,cmp);
	
	int nn=n/2+n%2; //jumatate +1 daca e nevoie
	for(i=0;i<nn;++i)
		s+=v[i].x;
	for(i=n-1;i>=nn;--i)
		s-=v[i].y;
	printf("%d",s);
	return 0;
}

