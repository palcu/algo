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
const int N = 1<<10;
const int INF = 0x3f3f3f3f;

// Globals
int nNoduri, nMuchii, sink, c[N][N], f[N][N];
vector<int> graph[N];
int flow = 0, from[N];
bool viz[N];

// Functions
bool bfs(){
    queue<int> q; q.push(1);
    memset(viz, 0, sizeof(viz)); memset(from, 0, sizeof(from));
    from[1] = viz[1] = 1;

    while(!q.empty() && !viz[sink]){
        int where = q.front(); q.pop();

        for(int i=0; i<graph[where].sz; i++){
            int next = graph[where][i];
            if(!viz[next] && c[where][next] - f[where][next] > 0){
                q.push(next);
                viz[next] = 1;
                from[next] = where;
            }
        }
    }

    return viz[sink];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("maxflow.in","r",stdin);
	freopen("maxflow.out","w",stdout);
	#endif

	int i, x, y, z, nod, flow = 0;

	cin >> nNoduri >> nMuchii; sink = nNoduri;
	for(i=0; i<nMuchii; i++){
        cin >> x >> y >> z;
        graph[x].pb(y);
        graph[y].pb(x);
        c[x][y] += z;
	}

    while(bfs()){
        for(i=0; i<graph[sink].sz; i++){
            int fmin = INF; nod = graph[sink][i];

            if(viz[nod] && c[nod][sink] - f[nod][sink] > 0){
                from[sink] = nod;
                for(nod = sink; nod != 1; nod = from[nod])
                    fmin = min(fmin, c[from[nod]][nod] - f[from[nod]][nod]);

                if(fmin){
                    for(nod = sink; nod != 1; nod = from[nod]){
                        f[from[nod]][nod] += fmin;
                        f[nod][from[nod]] -= fmin;
                    }
                    flow += fmin;
                }
            }
        }
    }

    cout << flow << '\n';

	return 0;
}
