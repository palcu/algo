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
const int N = 100008;
const int INF = 0x3f3f3f3f;

// Globals
int n, nQuery, v[N], sq[N], root;

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("rmq.in","r",stdin);
	freopen("rmq.out","w",stdout);
	#endif

	int i, j;
	cin >> n >> nQuery;
	for(i=1; i<=n; i++)
        cin >> v[i];

	root = sqrt(n);
	for(i=1; i*root<=n; i++){
        sq[i] = INF;
        for(j=(i-1)*root+1; j<=i*root; j++)
            sq[i] = min(sq[i], v[j]);
	}
	sq[root+1] = INF;
	for(; j<=n; j++)
        sq[root+1] = min(sq[root+1], v[j]);

	for(i=0; i<nQuery; i++){
        int a, b, l, r;
        cin >> a >> b;
        int sol = INF;

        for(j=1; j*root<a; j++)
            ;
        j++;

        l = min(root*(j-1), b);
        for(; root*j <= b; j++)
            sol = min(sol, sq[j]);
        r = max(root*(j-1), a);

        for(j=a; j<=l; j++)
            sol = min(sol, v[j]);
        for(j=r; j<=b; j++)
            sol = min(sol, v[j]);

        cout << sol << '\n';

	}

	return 0;
}
