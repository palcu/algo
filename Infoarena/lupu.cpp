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
const int N = 100008;
const int INF = 0x3f3f3f3f;
// Globals
int nOi, distMax, distPas;
typedef pair<int,int> pii;
pii oi[N];
priority_queue<pii> pq;
#define mp make_pair
// Functions
int main(){
    #ifndef ONLINE_JUDGE
    freopen("lupu.in","r",stdin);
    freopen("lupu.out","w",stdout);
    #endif
    int i, x, y;
    scanf("%d%d%d", &nOi, &distMax, &distPas);
    for(i=0; i<nOi; i++){
        cin >> x >> y;
        pq.push(mp(y,x));
    }
    int sol = 0;
    while(!pq.empty() && distMax >= 0){
        while(!pq.empty() && pq.top().second > distMax)
            pq.pop();
        if(!pq.empty())
            {sol += pq.top().first; pq.pop();}
        distMax -= distPas;
    }
    printf("%d\n", sol);
    return 0;
}
