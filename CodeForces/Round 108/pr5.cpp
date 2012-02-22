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
const int N = 1<<10;
const int vx[] = {1,-1,0,0}, vy[] = {0,0,1,-1};
const int INF = 0x3f3f3f3f;
//Structs

//Global Vars
int n, m[N][N], x, y;
pair<int,int> v[N];
vector<pair<int,int> > graf[N];

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


bool inbound(int a, int b){
	return 1<=a && a<=x && 1<=b && b<=y;
}
//Solve Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("pr5.in","r",stdin);
	//freopen("pr5.out","w",stdout);
	#endif

	int nImp;
	cin >> x >> y >> nImp;

	int i,j;
	for(i=1; i<=x; i++)
		for(j=1;j<=y; j++)
			cin >> m[i][j];

	for(i=0; i<nImp; i++)
		cin >> v[i].first >> v[i].second;

	int dist[N];
	bool inQueue[N];

	for(i=0; i<nImp; i++){
		for(j=0;j<N;j++) dist[j] = INF;
		memset(inQueue, 0, sizeof(inQueue));
		queue<pair<int,int> > q;
		q.push(make_pair(v[i].X, v[i].Y));
		dist[v[i].first*x + v[i].second] = m[v[i].X][v[i].Y];
		while(!q.empty()){
			pair<int,int> pct = q.front();
			q.pop();
			int myPoint = pct.first*x+pct.second;
			inQueue[myPoint] = 0;
			for(j=0;j<4;j++){
				int xx = pct.X + vx[j];
				int yy = pct.Y + vy[j];
				if(inbound(xx,yy)){
					if(dist[xx*x + yy] > dist[myPoint] + m[xx][yy]){
						dist[xx*x + yy] = dist[myPoint] + m[xx][yy];
						if(!inQueue[xx*x + yy]){
							q.push(make_pair(xx,yy));
							inQueue[xx*x + yy]=1;
						}
					}
				}
			}
		}

		for(j=0; j<nImp; j++)
			if(i!=j)
				graf[i].push_back(make_pair(j,dist[v[j].X*x + v[j].Y]));
	}

	for(i=0; i<nImp; i++){
		for(j=0; j<graf[i].size(); j++)
			printf("%d ", graf[i][j].second);
		printf("\n");
	}

	return 0;
}
