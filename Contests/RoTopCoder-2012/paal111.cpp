/*
	Alex Palcuie === http://palcu.blogspot.com/
	Valcea
	like
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int NMAX = 100006;
int nPers, nLikes;
int v[NMAX];

int main(){
	freopen("like.in", "r", stdin);
	freopen("like.out", "w", stdout);
	
	
	scanf("%d%d", &nPers, &nLikes);
	int i, sol; sol = nPers;
	
	int x,y;
	for(i=0; i<nLikes; i++){
		scanf("%d%d", &x, &y);
		if(x == y)
			continue;
		int grupX = x, grupY = y;
		int lgX = 0, lgY = 0;
		while(v[grupX] != 0){
			grupX = v[grupX];
			lgX ++;
		}
		while(v[grupY] != 0){
			grupY = v[grupY];
			lgY ++;
		}
		
		if (grupX != grupY){
			sol --;
			if(lgX > lgY)
				v[grupY] = grupX;
			else
				v[grupX] = grupY;
		}
	}
	
	printf("%d\n", sol);
	
	return 0;
}
