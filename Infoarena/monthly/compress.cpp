/***************************************************
 * Alex Palcuie
 * Romania
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
 * 2013
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

// Constants
const int N = 100008;
const int INF = 0x3f3f3f3f;

// Globals
int n;
char s[N];

// Structs

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("compress.in","r",stdin);
	freopen("compress.out","w",stdout);
	#endif

	scanf("%s\n", s);
	int n = strlen(s);
	for(int i=0; i<n; i++){
        int c = 1, j = i+1;
        while(s[i] == s[j] && j<n){
            j++; c++;
        }
        printf("%c%d", s[i], c);
        i=j-1;
	}

	printf("\n");

	return 0;
}
