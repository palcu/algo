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
int n;
char m[N][N];
bool b[N];

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
	freopen("pr1.in","r",stdin);
	//freopen("pr1.out","w",stdout);
	#endif

	int x,y; scanf("%d %d\n", &x, &y);
	int i,j,sol=0;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			scanf("%c", &m[i][j]);
			m[i][j] -= '0';
		}
		scanf("\n");
	}

	for(i=0;i<y;i++){
		int best = 0;
		vector<int> who;
		for(j=0;j<x;j++){
			//printf("%d ", m[j][i]);
			if(m[j][i] > best){
				best = m[j][i];
				who.clear();
				who.pb(j);
			}
			else if (m[j][i] == best){
				who.pb(j);
			}
		}
		int k;
		for(k=0;k<who.size();k++){
			if(!b[who[k]]){
				sol++;
				b[who[k]] = 1;
			}
		}
	}
	printf("%d\n", sol);

	return 0;
}
