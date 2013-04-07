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
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;

// Constants
const int N = 50008;
const int INF = 0x3f3f3f3f;

// Structs
struct Nod{
    int y, val;
    Nod(int a, int b){
        y=a; val=b;
    }
};

int d[N];

struct comp{
    bool operator () (int a, int b){
        return d[a] > d[b];
    }
};

// Globals
priority_queue<int, vector<int>, comp> pq;
int nNoduri, nMuchii;

vector<Nod> graph[N];

// Functions
int main(){
	freopen("dijkstra.in","r",stdin);
	freopen("dijkstra.out","w",stdout);

	int i, a, b, x;
	scanf("%d%d", &nNoduri, &nMuchii);

	for(i=0; i<nMuchii; i++){
        scanf("%d%d%d", &a, &b, &x);
        graph[a].pb(Nod(b, x));
	}

	fill_n(d+1, nNoduri, INF);
	d[1] = 0;
	pq.push(1);

	while(!pq.empty()){
        int nod = pq.top();
        pq.pop();
        for(i=0; i<graph[nod].size(); i++){
            Nod x = graph[nod][i];
            if(d[x.y] > d[nod] + x.val){
                d[x.y] = d[nod] + x.val;
                pq.push(x.y);
            }
        }
	}

	for(i=2; i<=nNoduri; i++)
        printf("%d ", d[i] == INF ? 0 : d[i]);

	return 0;
}
