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

//Structs

//Global Vars
int n, v[N], x, y;
char m[N][N];

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
	freopen("pr3.in","r",stdin);
	//freopen("pr3.out","w",stdout);
	#endif

	scanf("%d %d\n", &x, &y);
	for(int i=0; i<x; i++)
		fgets(m[i], N, stdin);
	int i,j;
	bool b[100];
	unsigned long long sol = 1, c=1000000007;
	for(i=0;i<y;i++){
		memset(b, 0, sizeof(b));
		unsigned long long k = 0;
		for(j=0; j<x; j++)
			if(!b[ m[j][i]-'A' ]){
				k++;
				b[ m[j][i]-'A' ] = 1;
			}
		sol = sol * k % c;
	}
	cout << sol;
	return 0;
}
