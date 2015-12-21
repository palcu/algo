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
const int N = 1<<10;
const int INF = 0x3f3f3f3f;

// Globals
int n, m[N][N], sol[N];

// Structs

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	//freopen("sume.in","r",stdin);
	//freopen("sume.out","w",stdout);
	#endif

	scanf("%d", &n);
	int i,j, s=0;
	for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf("%d", &m[i][j]);
            s += m[i][j];
        }
	s /= (n-1) * 2;
	int s1 = 0;
	for(i=0; i<n; i++)
        s1 += m[0][i];
    if (n>2){
        sol[0] = (s1 - s) / (n-2);
        for(i=1; i<n; i++)
            sol[i] = m[i][i-1] - sol[i-1];
    }
    else{
        if (m[0][1] == 2){
            sol[0] = sol[1] = 1;
        }
    }
    for(i=0; i<n; i++)
        printf("%d ", sol[i]);
    printf("\n");
	return 0;
}
