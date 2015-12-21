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

//Constants
const int N = 10;
const int M = 3;
const int K = 10;
const int INF = 0x3f3f3f3f;
const int NLIT = 20;

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
	freopen("default.in","r",stdin);
	freopen("default.out","w",stdout);
	#endif

	srand(time(NULL));
	printf("%d %d %d\n", N, M, K);
	int i, j;
	char s[1000000];
	memset(s, 0, sizeof(s));
	for(i=0; i<N; i++){
	    for(j=0; j<N; j++)
            s[j] = rand()%NLIT + 'A';
        printf("%s\n", s);
	}
	memset(s, 0, sizeof(s));
	for(i=0; i<K; i++){
        for(j=0; j<M*M; j++)
            s[j] = rand()%NLIT + 'A';
        printf("%s\n", s);
	}
	long long x;
	//cout << sizeof(x);

	return 0;
}
