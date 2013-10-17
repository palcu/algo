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

//Define
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))

//Constants
const int N = 50005;

//Structs

//Global Vars
int nEdges, nNodes;
vector<int> v[N];
bool isVisited[N];
deque<int> sol;

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

    for(unsigned i=0; i<v[k].size(); i++)
        if(!isVisited[v[k][i]]){
            isVisited[v[k][i]] = 1;
            dfs(v[k][i]);
        }
    sol.push_front(k);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("sortaret.in","r",stdin);
    freopen("sortaret.out","w",stdout);
    #endif

    cin >> nNodes >> nEdges;

    int x,y;
    while(nEdges--){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }

    for(unsigned i=1; i<=nNodes; i++)
        if(!isVisited[i]){
            isVisited[i]=1;
            dfs(i);
        }
    int n = sol.size();
    for(int i=0;i<n;i++)
        printf("%d ", sol[i]);

    return 0;
}
