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
#include <climits>
#include <fstream>
#include <sstream>

using namespace std;

// Defines
#define NAME(n) #n
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define F first
#define S second
#define pb push_back
#define sz size()
#define mp make_pair
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

// Helpers
template <typename T> inline void dbv(const T * v, const char * name, int n){
	fprintf(stderr, "=== %s ===\n", name);
	for(int i=0; i<n; i++)
		cerr << v[i] << " ";
	cerr << '\n';
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
const int N = 1<<10;
const int INF = 0x3f3f3f3f;

// Globals
int n;

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("p1.in", "r", stdin);
	freopen("p1.out", "w", stdout);
	#endif

	cin >> n;
	int i, x;
	int nFive=0, nZero=0;
	for(i=0; i<n; i++){
        cin >> x;
        if(x == 0) nZero++;
        if(x == 5) nFive++;
	}

	if(nFive<9 && !nZero)
        cout << "-1\n";
    else if(nFive<9 && nZero)
        cout << "0\n";
    else{
        if(!nZero){
            cout <<"-1\n";
            exit(0);
        }
        int h = nFive / 9;
        for(i=0; i<h; i++)
            cout << "555555555";
        for(i=0; i<nZero; i++)
            cout << "0";
    }

	return 0;
}
