/***************************************************
 * Alex Palcuie
 * Romania - 2013
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
****************************************************/

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
const int N = 2048;
const int INF = 0x3f3f3f3f;

// Globals
int x, y;
bool m[N][N];
ifstream fin("binar.in");
ofstream fout("binar.out");
 
// Functions
inline void solve_for(vector<short>& v, int depth){
    unsigned short i;
    if(v.size() <= 1 || depth == x+1){
        if(v.size()){
            for(i=0; i<v.size(); i++)
                fout << v[i] + 1 << " ";
        }
        return;
    }
  
    vector<short> with[2];
    for(i=0; i<v.size(); i++)
        with[m[ depth ][ v[i] ]].push_back(v[i]);
  
    solve_for(with[0], depth+1);
    solve_for(with[1], depth+1);
}
int main(){
    fin >> x >> y; fin.get();
  
    char str[N];
    unsigned short i, j;
    for(i=0; i<x; i++){
        fin.getline(str, N);
        for(j=0; j<y; j++)
            m[i][j] = str[j] - '0';
    }
  
    vector<short> v(y);
    for(int i=0; i<y; i++)
        v[i] = i;
  
    solve_for(v, 0);
  
    return 0;
}
