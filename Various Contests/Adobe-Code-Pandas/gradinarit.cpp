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
const int N = 64, S = N*3;
const int INF = 0x3f3f3f3f;

// Globals
int n, m, nDoze;
bool v[N]; int lg;
string s;
pii d[N][N];
pii f[N];

// Functions
void dynamic(){
    int i, j, k;
    for(i=0; i<lg;i ++){
        if(v[i]){
            f[i].F = f[i-1].F + 1;
            f[i].S = f[i-1].S;
        }
        else{
            f[i].F = f[i-1].F;
            f[i].S = f[i-1].S + 1;
        }
    }
    for(i=0; i<lg; i++)
        d[1][i] = max(f[i].F, f[i].S);

    for(i=2; i<lg; i++){
        d[i][j] = i;
        for(j=i; j<lg; j++){
            for(k=0; k<j; k++){
                d[i][j] = max(d[i][j], d[i][j-1] +)
                /*
                d[i][j].F = max(d[i][j].F, d[i-1][k].F + d[i-1][j].S - d[i-1][k].S);
                d[i][j].S = max(d[i][j].S, d[i-1][k].S + d[i-1][j].F - d[i-1][k].F);
                */
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	ifstream fin("gradinarit.in");
	ofstream fout("gradinarit.out");
	#endif

	fin >> n >> m >> nDoze; getline(fin, s);

	int i, j;
	for(i=0; i<n; i++){
        getline(fin, s);
        for(j=0; j<s.sz; j++){
            if(s[j] == 'C') // first = cartof
                v[lg++] = 1;
            else if (s[j] == 'R')
                v[lg++] = 0;
        }
        dynamic();
	}
    int sol = 0;
    fout << sol << '\n';
	fin.close(); fout.close(); return 0;
}
