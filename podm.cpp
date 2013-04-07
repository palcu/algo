/***************************************************
 * Alex Palcuie
 * Romania - 2013
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
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
#include <climits>

using namespace std;

// Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define F first
#define S second
#define pb push_back
#define sz size()
#define mp make_pair

// Helpers
template <typename T> inline void db(const T x, const char * name){
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
template<typename T> void dbw(const std::vector<T>& t, const char * name){
	fprintf(stderr, "=== %s ===\n", name);
	unsigned n = t.size();
	for(typename std::vector<T>::size_type i=0; i<n; ++i)
		std::cerr << t[i] << ' ';
	cerr << '\n';
}

// Structs

// Constants
const int N = 502;
const unsigned long long INF = ULLONG_MAX;

// Globals
typedef unsigned long long ull;
ull n, v[N];
ull m[N][N];

// Functions
ull dp(int a, int b){
    if(m[a][b]) return m[a][b];
    if(a == b) return 0;

    ull sol = INF;
    for(int k=a; k<b; k++){
        ull x;
        if(m[a][k])
            x = m[a][k];
        else
            x = dp(a, k);
        if(m[k+1][b])
            x += m[k+1][b];
        else
            x += dp(k+1, b);
        x += v[a-1] * v[k] * v[b];

        //ull x = dp(a, k) + dp(k+1, b) + ();
        sol = min(sol, x);
    }
    m[a][b] = sol;
    return sol;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("podm.in","r",stdin);
	freopen("podm.out","w",stdout);
	#endif

	ull i; cin >> n;
	for(i=0; i<=n; i++)
        scanf("%lld", &v[i]);

	ull sol = dp(1, n);
    cout << sol << '\n';

	return 0;
}
