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
int a[N][N], sol[N][N];
int x, y;

// Structs

// Functions
inline void debugMatrix(int m[N][N]){
    for(int i=1;i<=x;i++){
        for(int j=1; j<=y; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("joc.in","r",stdin);
	freopen("joc.out","w",stdout);
	#endif

	scanf("%d%d", &x, &y);
	int k,i,j;
	for(i=1; i<=x; i++)
        for(j=1; j<=y; j++){
            scanf("%d", &k);
            a[i][j] = k;
        }
    int myMax = -INF, xMax = 0, yMax = 0;

    sol[1][1] = a[1][1];
    for(i=1; i<=x; i++)
        for(j=1; j<=y; j++){
            if(!(i==1 && j==1))
                sol[i][j] = -INF;
            if(i>1){
                sol[i][j] = max(sol[i][j], sol[i-1][j]);
            }
            if(j>1){
                sol[i][j] = max(sol[i][j], sol[i][j-1]);
            }
            if(i>1 && j>1)
                sol[i][j] = max(sol[i][j], min(a[i][j] - sol[i-1][j], a[i][j] - sol[i][j-1]));
            else{
                if(i>1)
                    sol[i][j] = max(sol[i][j], a[i][j] - sol[i-1][j]);
                if(j>1)
                    sol[i][j] = max(sol[i][j], a[i][j] - sol[i][j-1]);
            }

            if(sol[i][j] > myMax){
                myMax = sol[i][j];
                xMax = i;
                yMax = j;
            }
        }

    //debugMatrix(sol);
    printf("%d %d %d\n", myMax, xMax, yMax);
	return 0;
}
