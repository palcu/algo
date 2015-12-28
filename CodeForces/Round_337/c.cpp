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
int m[512*2][512*2];
int size = 1;
// Functions
void double_matrix() {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            m[i+size][j] = m[i][j];
            m[i][j+size] = m[i][j];
            m[i+size][j+size] = m[i][j] * (-1);
        }
    }
    size*=2;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("cdfc.in", "r", stdin);
    #endif
    
    int k; cin >> k;
    m[0][0] = 1;

    for (int i=0; i<k; i++) {
        double_matrix();
    }

    for (int i=0; i<size; i++, cout << "\n")
        for (int j=0; j<size; j++)
            cout << (m[i][j] == 1 ? '+' : '*');
    
    return 0;
}

