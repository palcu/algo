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
const int N = 50004;
const int INF = 0x3f3f3f3f;

//Structs
struct Nod{
	int y,val;
	Nod(int a, int b){
		y=a;
		val=b;
	}
};

//Global Vars
int nNoduri, nMuchii;
vector<Nod> g[N];
int countInQueue[N], sol[N];
bool inQueue[N];

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
void hasCycle(){
	printf("Ciclu negativ!\n");
	exit(0);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("bellmanford.in","r",stdin);
	freopen("bellmanford.out","w",stdout);
	#endif

	scanf("%d%d", &nNoduri, &nMuchii);

	int a,b,c, i;
	for(i=0; i<nMuchii; i++){
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(Nod(b,c));
	}

	for(i=1; i<=nNoduri; i++)
		sol[i] = INF;

	queue<int> q;
	q.push(1);
	sol[1] = 0; countInQueue[1] = 1; inQueue[1]=1;

	int x;
	while(!q.empty()){
		x = q.front(); q.pop(); inQueue[x] = 0;
		for(i=0; i<g[x].size(); i++){
			Nod a = g[x][i];
			if(sol[a.y] > sol[x] + a.val){
				sol[a.y] = sol[x] + a.val;
				if(!inQueue[a.y]){
					if(countInQueue[a.y] > nNoduri)
						hasCycle();
					q.push(a.y);
					inQueue[a.y] = 1;
					countInQueue[a.y] ++;
				}
			}
		}
	}

	for(i=2; i<=nNoduri; i++)
		printf("%d ", sol[i]);
	printf("\n");

	return 0;
}
