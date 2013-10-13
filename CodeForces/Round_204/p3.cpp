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
#include <iomanip>

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
const int N = 2048;
const int INF = 0x3f3f3f3f;

// Globals
double v[N], z[N];

// Functions
int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("p3.in", "r", stdin);
	freopen("p3.out", "w", stdout);
	#endif

	double s = 0;
	int i, j, n;

	cin >> n; n*=2; int pesteCinci = 0, subCinci = 0;
	for(i=0; i<n; i++){
        cin >> v[i];
        s += v[i];
        z[i] = v[i] - (int)v[i];
        if(z[i]){
            if(z[i] < 0.5) subCinci++;
            else pesteCinci++;
        }
	}
	sort(z, z+n);
	double sol = 0;
	i=0; int nZero = 0; j=n-1;
	while(!z[i]) {i++; nZero++;}

	{
	    while(pesteCinci > subCinci && nZero && i<=j){
            nZero--;
            sol += 1 - z[j];
            j--;
            pesteCinci--;
	    }
	    while(pesteCinci < subCinci && nZero && i<=j){
            nZero--;
            sol -= z[j];
            i++;
            subCinci--;
	    }
        for(; i<j; i++, j--)
            if(z[i]){
                sol -= z[i];
                sol += 1 - z[j];
            }
	}

	printf("%.3lf", abs(sol));

	return 0;
}
