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
const int N = 100005;
const int INF = 999999999;

//Structs
typedef deque<pair<int,int> > deq;

//Global Vars
int n, v[N], k;
deq d_max, d_min;

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
void popfleft(deq & d, int i){
	if (d.front().first + k < i)
			d.pop_front();
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("vile.in","r",stdin);
	freopen("vile.out","w",stdout);
	#endif

	int i;
	scanf("%d%d",&n,&k);

	int sol=0;
	scanf("%d",&v[0]);

	d_min.push_back(make_pair(0, v[0]));
	d_max.push_back(make_pair(0, v[0]));

	for(i=1; i<n; i++){
		scanf("%d", &v[i]);

		popfleft(d_min, i);
		popfleft(d_max, i);

		while(!d_min.empty() && v[i] < d_min.back().second)
			d_min.pop_back();
		d_min.push_back(make_pair(i, v[i]));

		while(!d_max.empty() && v[i] > d_max.back().second)
			d_max.pop_back();
		d_max.push_back(make_pair(i, v[i]));

		sol = max(sol, d_max.front().second - d_min.front().second);
	}

	printf("%d\n", sol);

	return 0;
}
