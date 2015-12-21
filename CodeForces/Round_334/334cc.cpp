/***************************************************
 * Alex Palcuie
 * Romania - 2015
 * alex [dot] palcuie [at] gmail [dot] com
 * http://blog.palcu.ro/
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
    #ifndef ONLINE_JUDGE
    freopen("334cc.in", "r", stdin);
    //freopen("334cc.out", "w", stdout);
    #endif
    
    string str, compressed;
    getline(cin, str);
    getline(cin, str);
    
    int diffs = 1, same = 0, three_consec = 0;
    compressed.push_back(str[0]);
    for (int i=1; i<str.size(); i++) {
        if (str[i] != str[i-1])
            diffs++;
        if (str[i] != str[i-1] || str[i] != str[i-2])
            compressed += str[i];
        if (i >= 2 && str[i] == str[i-1] && str[i] == str[i-2])
            three_consec = 2;
    }
    //cerr << compressed << endl;

    for (int i=0; i<compressed.size()-1; i++)
        if (compressed[i] == compressed[i+1])
            same++;
    same = min(same, 2);
    //cout << same << endl;
    cout << max(diffs + same, diffs+three_consec) << endl;
    
    return 0;
}

