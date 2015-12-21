/*
	Alex Palcuie === http://palcu.blogspot.com/
	Valcea
	starbomb
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

const int NMAX = 128;
const double EPSILON = 0.001;

struct Cerc{
	double x,y;
} v[NMAX];

int n, raza;
bool m[NMAX][NMAX];

inline double dist(const int i, const int j){
	double x = v[i].x - v[j].x;
	double y = v[i].y - v[j].y;
	return sqrt(x*x + y*y);
}

inline void debug_matrix(){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

int inters[NMAX], sol = 0;
inline void brut(const int cerc, const int poz){
	inters[poz] = cerc;
	sol = max(sol, poz);
	int i,j;
	bool ok;
	for(i = cerc + 1; i<n; i++){
		ok=1;
		for(j=1; j<=poz; j++)
			if(!m[i][ inters[j] ]){
				ok=0;
				break;
			}
		if(ok) brut(i, poz+1);
	}
}

inline bool maimicsauegal(double d, const int x){
	double dif = d - x;
	return dif < EPSILON;
}

int main(){
	freopen("starbomb.in", "r", stdin);
	freopen("starbomb.out", "w", stdout);
	
	scanf("%d %d\n", &raza, &n);
	int diametru = 2*raza;
	int i, j;
	
	for(i=0; i<n; i++)
		scanf("%lf %lf\n", &v[i].x, &v[i].y);
	
	
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++){
			double d = dist(i,j);
			if(maimicsauegal(d, diametru)) //compara cu epsilon
				m[i][j] = m[j][i] = 1;
		}
	
	//debug_matrix();
	
	brut(0,1);
	
	printf("%d\n", sol);
	
	return 0;
}
