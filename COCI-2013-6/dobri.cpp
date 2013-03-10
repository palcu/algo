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
const int N = 5012;
const int X = 200012;
const int TO0 = 100000;
const int INF = 0x3f3f3f3f;

// Globals
int n, v[N];
vector<int> sums;
bool isInV[X];

// Structs

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	//freopen("dobri.in","r",stdin);
	//freopen("dobri.out","w",stdout);
	#endif

	int i, j, sol=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
        scanf("%d", &v[i]);
        isInV[v[i]+TO0] = 1;
	}

    sums.pb(v[0]*2);
    for(i=1; i<n; i++){
        for(j=0; j<sums.size(); j++)
            if(isInV[v[i] - sums[j] + TO0]){
                sol++;
                break;
            }
        for(j=0; j<=i; j++)
            sums.pb(v[i] + v[j]);
    }
    printf("%d\n", sol);

	return 0;
}
