/***************************************************
 * Alex Palcuie
 * Romania - 2015
 * alex [dot] palcuie [at] gmail [dot] com
 * http://blog.palcu.ro/
****************************************************/

#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

// Functions
int main(){
    #ifndef ONLINE_JUDGE
    freopen("edb.in", "r", stdin);
    #endif
    
    int nBooks, nGenres;
    cin >> nBooks >> nGenres;
    vector<int> v(nGenres+1, 0);

    for (int i=0; i<nBooks; i++) {
        int x; cin >> x;
        v[x]++;
    }

    unsigned long long sol;
    if (nBooks % 2 == 0) {
        sol = nBooks / 2 * (nBooks - 1);
    } else {
        sol = (nBooks - 1) / 2 * nBooks;
    }

    for (int i=1; i<=nGenres; i++) {
        if (v[i] > 1) {
            unsigned long long t1 = v[i], t2;
            if (t1 % 2 == 0) {
                t2 = t1 - 1;
                t1 /= 2;
            } else {
                t2 = (t1 - 1) / 2;
            }
            sol -= t1 * t2;
        }
    }
    cout << sol << "\n";
    return 0;
}

