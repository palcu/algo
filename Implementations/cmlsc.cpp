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
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define X first
#define Y second
#define pb push_back
 
//Constants
const int N = 1027;
 
//Structs
 
//Global Vars
int x, y, m[N][N];
int v[N], w[N];
int sol[N], sz;
 
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
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    #endif
 
    int x, y;
    scanf("%d%d", &x, &y);
 
    int i,j;
    for(i=1; i<=x; i++) scanf("%d", &v[i]);
    for(i=1; i<=y; i++) scanf("%d", &w[i]);
 
    for(i=1; i<=x; i++)
        for(j=1; j<=y; j++)
            if(v[i] == w[j])
                m[i][j] = m[i-1][j-1] + 1;
            else
                m[i][j] = max(m[i-1][j], m[i][j-1]);
 
    printf("%d\n", m[x][y]);
 
    i=x, j=y;
    while(i && j){
        if(v[i] == w[j]){
            sol[sz++] = v[i];
            i--, j--;
        }
        else if (m[i-1][j] < m[i][j-1])
            j--;
        else
            i--;
    }
    for(i=sz-1; i>=0; i--)
        printf("%d ", sol[i]);
 
    return 0;
}
