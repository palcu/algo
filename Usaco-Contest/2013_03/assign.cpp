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

// Helpers
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

// Structs

// Constants
const int MAX_COWS = 32;
const int MAX_RELS = 64;
const int INF = 0x3f3f3f3f;

// Globals
int nCows, nRels;
int disjoint[MAX_COWS];
int dif[MAX_RELS][2], nDif = 0;
bool matrix[MAX_COWS][MAX_COWS];
vector<int> graph[MAX_COWS];
vector<pair<int, int> > gradNod;
bool vizitat[MAX_COWS];
int val[MAX_COWS];

// Functions
void topAndSize(int& x, int& size){
    while(disjoint[x] != x){
        x = disjoint[x];
        size++;
    }
}
int top(int x){
    while(disjoint[x] != x)
        x = disjoint[x];
    return x;
}
void uneste(int a, int b){
    int lgA=0, lgB=0;
    topAndSize(a, lgA);
    topAndSize(b, lgB);
    if(a != b){
        if(lgA < lgB)
            disjoint[a] = b;
        else
            disjoint[b] = a;
    }
}
inline bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.X != b.X)
        return a.X > b.X;
    return a.Y < b.Y;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	#endif

	int i, j;

	scanf("%d %d\n", &nCows, &nRels);
	for(i=1; i<=nCows; i++){
        disjoint[i] = i;
        val[i] = 3;
	}

    char c; int x, y;
    for(i=0; i<nRels; i++){
        scanf("%c %d %d\n", &c, &x, &y);
        if(c == 'S')
            uneste(x, y);
        else{
            dif[nDif][0] = x;
            dif[nDif++][1] = y;
        }
    }

    for(i=0; i<nDif; i++){
        dif[i][0] = top(dif[i][0]);
        dif[i][1] = top(dif[i][1]);
        matrix[ dif[i][0] ][ dif[i][1] ] =  matrix[ dif[i][1] ][ dif[i][0] ] = 1;
    }

    for(i=1; i<=nCows; i++){
        if(i == top(i)){ //daca e varf
            for(j=1; j<=nCows; j++)
                if(matrix[i][j])
                    graph[i].pb(j);
            gradNod.pb(make_pair(graph[i].size(), i));
        }
    }
    sort(gradNod.begin(), gradNod.end(), cmp);

    int sol = 1;
    for(i=0; i<gradNod.size(); i++){
        int nodParinte = gradNod[i].Y;
        sol *= val[nodParinte];
        vizitat[nodParinte] = 1;
        for(j=0; j<graph[nodParinte].size(); j++){
            int nod = graph[nodParinte][j];
            if(!vizitat[nod]){
                val[nod]--;
                if(!val[nod]){
                    printf("0\n");
                    exit(0);
                }
            }
        }
    }

    printf("%d\n", sol);

	return 0;
}
