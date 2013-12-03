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
    freopen("valera.in", "r", stdin);
    freopen("valera.out", "w", stdout);
    
    int nDays, v[3];
    cin >> nDays >> v[1] >> v[2];

    for(int i=0; i<nDays; i++){
        //prv(v,3);
        int t;
        cin >> t;
        if(t==1)
            v[1]--;
        else if(t==2){
            if(v[2] > 0)
                v[2]--;
            else if (v[1] > 0)
                v[1]--;
            else
                v[2]--;
        }
    }
    int s = 0;
    //prv(v,3);
    if(v[1] < 0)
        s += -v[1];
    if(v[2] < 0)
        s += -v[2];
    cout << s << '\n';
    
    return 0;
}

