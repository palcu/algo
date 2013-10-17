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
#include <fstream>
#include <sstream>

using namespace std;

// Defines
#define NAME(n) #n
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define F first
#define S second
#define pb push_back
#define sz size()
#define mp make_pair
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

// Helpers
template <typename T> inline void dbv(const T * v, const char * name, int n){
	fprintf(stderr, "=== %s ===\n", name);
	for(int i=0; i<n; i++)
		cerr << v[i] << " ";
	cerr << '\n';
}
template<typename T> void dbw(const std::vector<T>& t, const char * name){
	fprintf(stderr, "=== %s ===\n", name);
	unsigned n = t.size();
	for(typename std::vector<T>::size_type i=0; i<n; ++i)
		std::cerr << t[i] << ' ';
	cerr << '\n';
}

// Structs
struct Nod{
    int l, r, m, mid;
};

// Constants
const int N = 100008;
const int INF = 0x3f3f3f3f;

// Globals
int n, nQuery;
Nod arb[4*N+69];

// Functions
inline void create(int poz, int l, int r){
    if(r > n) return;
    arb[poz].l = l;
    arb[poz].r = r;
    arb[poz].mid = (l + r) / 2;
    if (l == r) return;
    int mid = (l+r) / 2;
    create(poz*2, l, mid);
    create(poz*2 + 1, mid + 1, r);
}
void insert(int poz, int i, int k){
    arb[poz].m = max(arb[poz].m, k);
    int mid = (arb[poz].l + arb[poz].r) / 2;

    if(arb[poz].l == arb[poz].r)
        return;

    if(i <= mid)
        insert(poz*2, i, k);
    else
        insert(poz*2+1, i, k);
}
inline int query(int poz, int a, int b){
    if(a <= arb[poz].l && arb[poz].r <= b)
        return arb[poz].m;

    int mid = (arb[poz].l + arb[poz].r) / 2;

    int sol = -1;
    if(a <= mid)
        sol = max(sol, query(poz*2, a, b));
    if(b > mid)
        sol = max(sol, query(poz*2+1, a, b));
    return sol;
}

int replace(int p, int k){
    int poz = 1;
    while(arb[poz].l != p || arb[poz].r != p){
        if(p <= arb[poz].mid)
            poz *= 2;
        else
            poz = poz*2 + 1;
    }
    arb[poz].m = k;
    while(poz != 1){
        arb[poz / 2].m = max(arb[poz/2*2].m, arb[poz/2*2+1].m);
        poz /= 2;
    }
    arb[1].m = max(arb[2].m, arb[3].m);
}

int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	ifstream fin("arbint.in");
	ofstream fout("arbint.out");
	#endif

    int i;

	fin >> n >> nQuery;
	create(1, 1, n);
	for(i=1; i<=n; i++){
        int x; fin >> x;
        insert(1, i, x);
	}
	for(i=0; i<nQuery; i++){
        int op, x, y;
        fin >> op >> x >>y;
        if(op == 0)
            fout << query(1, x, y) << '\n';
        else
            replace(x, y);
	}

	fin.close(); fout.close(); return 0;
}
