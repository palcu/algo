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
typedef unsigned long long ull;
typedef pair<int,int> pii;

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
const int N = 5008, G = 10008;
const int INF = 0x3f3f3f3f;

// Globals
int n, g;
pii v[N];
vector<int> d(G), last(G);

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("rucsac.in","r",stdin);
	freopen("rucsac.out","w",stdout);
	#endif

	int i, j; cin >> n >> g;
    for(i=0; i<n; i++)
        cin >> v[i].F >> v[i].S;

    for(i=0; i<n; i++){
        for(j=0; j<=g; j++){
            d[j] = last[j];
            if(v[i].F <= j)
                d[j] = max(d[j], last[j - v[i].F] + v[i].S);
        }
        swap(last, d);
    }

    cout << last[g] << '\n';

	return 0;
}
