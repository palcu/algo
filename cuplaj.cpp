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
const int N = 10008;
const int INF = 0x3f3f3f3f;

// Globals
int nLeft, nRight, nMuchii;
int l[N], r[N];
bool u[N];
vector<int> graph[N];

// Functions
void link(int a, int b){
    l[a] = b;
    r[b] = a;
}
bool pairup(int x){
    if(u[x]) return 0;
    u[x] = 1;

    int i;
    for(i=0; i<graph[x].sz; i++){
        int k = graph[x][i];
        if(!r[k]){
            link(x, k);
            return 1;
        }
    }
    for(i=0; i<graph[x].sz; i++){
        int k = graph[x][i];
        if(pairup(r[k])){
            link(x, k);
            return 1;
        }
    }
    return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("cuplaj.in","r",stdin);
	freopen("cuplaj.out","w",stdout);
	#endif

	int i;
	cin >> nLeft >> nRight >> nMuchii;
	for(i=0; i<nMuchii; i++){
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
	}

	bool change = true;
	while(change){
        change = false;
        memset(u, 0, sizeof(u));
        for(i=1; i<=nLeft; i++)
            if(!l[i]){
                bool p = pairup(i);
                change |= p;
            }
	}

    int sol = 0;
    for(i=1; i<=nLeft; i++)
        if(l[i])
            sol++;
    cout << sol << '\n';

    for(i=1; i<=nLeft; i++)
        if(l[i])
            cout << i << " " << l[i] << '\n';

	return 0;
}
