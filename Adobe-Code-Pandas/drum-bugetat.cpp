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

// Constants
const int N = 1<<10;
const int INF = 0x3f3f3f3f;

// Globals
int nNoduri, nMuchii, buget;
int start, sink;
int nodCost[N];
vector<pii> g[N];
int nInQueue[N]; bool inQueue[N];
int d[N][N]; // d[nod][costDeParcurengere], reprez timpul minim
vector<int> posibDeCost[N];

// Functions
void has_cycle(){
    printf("-1\n");
    exit(0);
}
int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	ifstream fin("drum-bugetat.in");
	ofstream fout("drum-bugetat.out");
	#endif

	fin >> nNoduri >> nMuchii >> buget;
	fin >> start >> sink;
	int i;
	for(i=1; i<=nNoduri; i++)
        fin >> nodCost[i];
    for(i=0; i<nMuchii; i++){
        int x, y, z;
        fin >> x >> y >> z;
        g[x].pb(mp(y, z));
    }

    for(i=1; i<=nNoduri; i++)
        memset(d[i], INF, sizeof(d[i]));
    memset(d[start], 0, sizeof(d[start]));

    queue<int> q; q.push(start);
    inQueue[start] = 1; nInQueue[start] = 1;
    posibDeCost[start].pb(0);
    int solTimp = INF, solCost = INF;
    while(!q.empty()){
        int x = q.front(); q.pop(); inQueue[x] = 0;
        for(int p=0; p<posibDeCost[x].sz; p++){
            int costCurent = posibDeCost[x][p];
            int timpCurent = d[x][costCurent];
            for(i=0; i<g[x].sz; i++){
                pii nod = g[x][i]; int y = nod.F; int timp = nod.S;
                int costNou = costCurent + nodCost[y];
                int timpNou = timpCurent + timp;
                if(costNou <= buget && timpNou < d[y][costNou]){
                    if(d[y][costNou] == INF)
                        posibDeCost[y].pb(costNou);
                    d[y][costNou] = timpNou;

                    if(y == sink){
                        if(d[y][costCurent] < solTimp){
                            solTimp = d[y][costCurent];
                            solCost = costCurent;
                        }
                        else if (solTimp == d[y][costCurent])
                            solCost = min(solCost, costCurent);
                    }
                    else if(!inQueue[y]){
                        if(nInQueue[y]++ > nNoduri)
                            has_cycle();
                        q.push(y); inQueue[y] = 1;
                    }
                }
            }
        }
    }
    if(solTimp == INF)
        has_cycle();

    fout << solTimp << ' ' << solCost << '\n';

	fin.close(); fout.close(); return 0;
}
