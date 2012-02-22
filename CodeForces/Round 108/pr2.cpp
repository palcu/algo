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
#define ll long long

//Constants
const int N = 1<<10;

//Structs

//Global Vars
int n, v[N];

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
	freopen("pr2.in","r",stdin);
	//freopen("pr2.out","w",stdout);
	#endif

	long long m,n,posx, posy, nSteps, sol=0;

	cin >> m >> n >> posx >> posy >> nSteps;
	for(int i=0; i<nSteps; i++){
		long long x, y;
		cin >> x >> y;
		long long lgx, lgy;

		if(x>0)
			lgx = (m - posx) / x;
		else if (x<0)
			lgx = (posx-1) / abs(x);
		if (y>0)
			lgy = (n - posy) / y;
		else if (y<0)
			lgy = (posy -1) / abs(y);

		int steps = 0;
		if (x && y)
			steps = min(lgx, lgy);
		else if (x)
			steps = lgx;
		else if (y)
			steps = lgy;
		posx += x*steps;
		posy += y*steps;
		sol += steps;
		//pr(steps);
	}
	cout << sol;

	return 0;
}
