/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2012
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
#include <functional>
#include <fstream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cstring>

using namespace std;

//{Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define X first
#define Y second
#define pb push_back

//Constants
const int N = 50005;
const int INF = 10000000;

//Structs
struct Nod{
	int x, val;
	Nod(int a, int b){
		x = a;
		val = b;
	}
};
bool operator<(Nod const& x, Nod const& y){
	return x.val > y.val;
}

//Global Vars
int nMuchii, nNoduri, marked[N];
int parent[N], sol[N];
vector<Nod> v[N];

//{Helpers
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
//}

//Solve Functions

int main(){
	#ifndef ONLINE_JUDGE
	freopen("djsktra.in","r",stdin);
	//freopen("dijkstra.out","w",stdout);
	#endif

	scanf("%d%d", &nNoduri, &nMuchii);

	int i, x, y, val;
	for(i=1; i<=nNoduri; i++)
		sol[i] = INF;
	for(i=0; i<nMuchii; i++){
		scanf("%d%d%d", &x, &y, &val);
		v[x].push_back(Nod(y,val));
	}

	priority_queue<Nod> pq;
	pq.push(Nod(1,0));
	sol[1] = 0;

	int c = 1;
	while(!pq.empty() && c < nNoduri){
		Nod nod = pq.top(); pq.pop();
		if(!marked[nod.x]){
			marked[nod.x] = 1; c++;
			for(i=0; i<v[nod.x].size(); i++)
				if(sol[nod.x] + v[nod.x][i].val < sol[ v[nod.x][i].x ]){
					sol[ v[nod.x][i].x ] = sol[nod.x] + v[nod.x][i].val;
					pq.push(Nod(v[nod.x][i].x, v[nod.x][i].val));
				}
		}
	}
	for(i=2; i<=nNoduri; i++){
		if(sol[i] != INF)
			printf("%d ", sol[i]);
		else
			printf("0 ");
	}

	return 0;
}
