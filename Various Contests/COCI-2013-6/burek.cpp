/***************************************************
 * Alex Palcuie
 * Romania
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
 * 2013
****************************************************/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cstring>

using namespace std;

// Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define X first
#define Y second
#define pb push_back

// Helpers
template <typename T>
inline void db(const T x, const char * name){
	cerr << name << " = " << x << '\n';
}
template <typename T> inline void dbv(const T * v, const char * name, int n){
	fprintf(stderr, "=== %s ===\n", name);
	for(int i=0; i<n; i++)
		cerr << v[i] << " ";
	cerr << '\n';
}
template <typename T> inline void dbs(T x){
	cerr << x << ' ';
}

template<typename T>
void dbw(const std::vector<T>& t, const char * name){
	fprintf(stderr, "=== %s ===\n", name);
	unsigned n = t.size();
	for(typename std::vector<T>::size_type i=0; i<n; ++i)
		std::cerr << t[i] << ' ';
	cerr << '\n';
}

// Constants
const int N = 1000005;
const int INF = 0x3f3f3f3f;

// Globals
int nTriangles, nTeste;
int graphX[N], graphY[N];

// Structs

// Functions
inline int max3(int a, int b, int c){
    return max(max(a,b),c);
}
inline int min3(int a, int b, int c){
    return min(min(a,b),c);
}
int main(){
	#ifndef ONLINE_JUDGE
	//freopen("burek.in","r",stdin);
	//freopen("burek.out","w",stdout);
	#endif

	int i, j, coord[6];
	scanf("%d", &nTriangles);
	for(i=0; i<nTriangles; i++){
        for(j=0; j<6; j++)
            scanf("%d", &coord[j]);
        int minX, maxX, minY, maxY;
        minX = min3(coord[0], coord[2], coord[4]);
        minY = min3(coord[1], coord[3], coord[5]);
        maxX = max3(coord[0], coord[2], coord[4]);
        maxY = max3(coord[1], coord[3], coord[5]);
        for(j=minX+1; j<maxX; j++)
            graphX[j]++;
        for(j=minY+1; j<maxY; j++)
            graphY[j]++;
	}
	scanf("%d\n", &nTeste);
	char c; int x;
	for(i=0; i<nTeste; i++){
        scanf("%c = %d\n", &c, &x);
        if(c == 'x')
            printf("%d\n", graphX[x]);
        else
            printf("%d\n", graphY[x]);
	}

	return 0;
}
