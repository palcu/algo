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
const int N = 20008;
const int INF = 0x3f3f3f3f;

// Globals
int n1, n2, k, n;
char s1[N], s2[N];
vector<int> last(N), c(N);

// Functions
/* Recursive solution
int dp(int a, int b){
    if(m[a][b]) return m[a][b];
    if(a==n1 && b==n2)
        return 0;
    if(a==n1)
        return n2-b;
    if(b==n2)
        return n1-a;
    int sol = INF;

    sol = min(sol, 1 + dp(a, b+1));
    sol = min(sol, 1 + dp(a+1, b));
    sol = min(sol, (s1[a] == s2[b] ? 0 : 1) + dp(a+1, b+1));

    m[a][b] = sol;
    return sol;
}
*/
int main(){
	#ifndef ONLINE_JUDGE
	freopen("edist.in","r",stdin);
	freopen("edist.out","w",stdout);
	#endif

    int i, j;
	scanf("%d %d %d\n", &n1, &n2, &k); n = max(n1, n2);
	scanf("%s\n%s\n", s1, s2);



/*  Big Solution
    for(i=1; i<=n1; i++)
        m[i][0] = i;

    for(i=1; i<=n2; i++)
        m[0][i] = i;

	for(i=1; i<=n1; i++)
        for(j=1; j<=i+k; j++){
            m[i][j] = INF;
            m[i][j] = min(m[i][j], m[i-1][j] + 1);
            m[i][j] = min(m[i][j], m[i][j-1] + 1);
            m[i][j] = min(m[i][j], m[i-1][j-1] + (s1[i] == s2[j] ? 0 : 1));
        }
    cout << m[n1][n2] << '\n';*/

    for(i=1; i<=n2; i++)
        last[i] = i;

    for(i=1; i<=n1; i++){
        c[0] = 1;
        int l = i-k > 0 ? i-k : 1;
        int r = min(i+k, n2);
        for(j=l; j<=r; j++){
            c[j] = INF;
            c[j] = min(c[j], c[j-1] + 1);
            c[j] = min(c[j], last[j] + 1);
            c[j] = min(c[j], last[j-1] + (s1[i] == s2[j] ? 0 : 1));
        }
        swap(c, last);
    }

    cout << last[n2] << '\n';

	return 0;
}
