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
const int N = 2000008;
const int INF = 0x3f3f3f3f;

// Globals
char w[N], t[N];
int p[N], W, T;
vector<int> sol;

// Functions
int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	ifstream fin("strmatch.in");
	ofstream fout("strmatch.out");
	#endif

	fin.getline(w, N); W = strlen(w);
	fin.getline(t, N); T = strlen(t);

	int left = 0, right;
	for(right=1; right < W; right++){
	    while(left > 0 && w[left] != w[right])
            left = p[left];
        if(w[left] == w[right])
            left ++;
        p[right] = left;
	}

	int k = 0, nSol = 0;
	for(int i=0; i < T; i++){
        while(k && w[k] != t[i])
            k = p[k-1];
        if(w[k] == t[i])
            k++;
        if(k == W){
            k = p[W-1];
            if(sol.sz < 1000) sol.pb(i - W + 1);
            nSol++;
        }
	}


    fout << nSol << '\n';
    for(int i=0; i<sol.sz; i++)
        fout << sol[i] << ' ';
    fout << '\n';

	fin.close(); fout.close(); return 0;
}
