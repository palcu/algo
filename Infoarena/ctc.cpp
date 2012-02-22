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
const int N = 100005;

//Structs

//Global Vars
int nNoduri, nMuchii, ordine[N], pOrdine;
bool marked[N], marked2[N];
vector<int> graph[N], rgraph[N];
vector<vector<int> > sol;

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
void dfs(int k){
	marked[k] = true;
	for(int i=0; i<graph[k].size(); i++)
		if (!marked[graph[k][i]])
			dfs(graph[k][i]);
	ordine[pOrdine++] = k;
}

void dfs2(int k){
	sol.back().pb(k);
	marked2[k] = 1;
	for(int i=0; i<rgraph[k].size(); i++)
		if(!marked2[rgraph[k][i]])
			dfs2(rgraph[k][i]);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("ctc.in","r",stdin);
	freopen("ctc.out","w",stdout);
	#endif

	scanf("%d%d", &nNoduri, &nMuchii);
	int i, x, y;
	for(i=0; i<nMuchii; i++){
		scanf("%d%d", &x, &y);
		graph[x].pb(y);
		rgraph[y].pb(x);
	}

	for(i=1; i<=nNoduri; i++)
		if(!marked[i])
			dfs(i);

	vector<int> gol;
	//dbv(ordine, "ordine", nNoduri);
	for(i=nNoduri-1; i>=0; i--)
		if(!marked2[ordine[i]]){
			sol.pb(gol);
			dfs2(ordine[i]);
		}

	printf("%d\n", sol.size());
	int j;
	for(i=0; i<sol.size(); i++){
		for(j=0; j<sol[i].size(); j++)
			printf("%d ", sol[i][j]);
		printf("\n");
	}
	return 0;
}
