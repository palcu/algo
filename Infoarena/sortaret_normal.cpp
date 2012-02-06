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
const int N = 50004;

//Structs

//Global Vars
int n, degree[N];
int nNodes, nEdges;
vector<int> v[N];

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
	freopen("sortaret.in","r",stdin);
	freopen("sortaret.out","w",stdout);
	#endif

	cin >> nNodes >> nEdges;
	int i;

	int x,y;
	for(i=0; i<nEdges; i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		degree[y]++;
	}

	queue<int> q;
	for(i=1; i<=nNodes; i++)
		if(!degree[i])
			q.push(i);

	while(!q.empty()){
		x = q.front(); q.pop();
		printf("%d ", x);
		y = v[x].size();
		for(i=0; i<y; i++){
			degree[v[x][i]]--;
			if(!degree[v[x][i]])
				q.push(v[x][i]);
		}
	}


	return 0;
}
