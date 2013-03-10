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
const int N = 32;
const int INF = 0x3f3f3f3f;

// Globals
int n, v[N];
char s[N];

// Structs

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	//freopen("baka.in","r",stdin);
	//freopen("baka.out","w",stdout);
	#endif

	scanf("%s", s); n = strlen(s);
	int sol = 0;
	for(int i=0; i<n; i++){
        if('A' <= s[i] && s[i] <= 'C') sol += 3;
        else if('D' <= s[i] && s[i] <= 'F') sol += 4;
        else if('G' <= s[i] && s[i] <= 'I') sol += 5;
        else if('J' <= s[i] && s[i] <= 'L') sol += 6;
        else if('M' <= s[i] && s[i] <= 'O') sol += 7;
        else if('P' <= s[i] && s[i] <= 'S') sol += 8;
        else if('T' <= s[i] && s[i] <= 'V') sol += 9;
        else if('W' <= s[i] && s[i] <= 'Z') sol += 10;
	}
	printf("%d\n", sol);

	return 0;
}
