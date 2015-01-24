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
const int N = 500005;
const int INF = 0x3f3f3f3f;
 
// Globals
pii v[N];
int n;
 
// Functions
/*
bool cmp(pii a, pii b){
    if(a.F == b.F)
        return a.S > b.S;
    return a.F < b.F;
}
*/
bool isIntersectieVida(pii a, pii b){
    return a.S <= b.F;
}
bool secondInclusInPrimul(pii a, pii b){
    return a.F <= b.F && b.S <= a.S;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("int.in", "r", stdin);
    freopen("int.out", "w", stdout);
    #endif
 
    cin >> n;
    int i;
 
    for(i=0; i<n; i++)
        cin >> v[i].F >> v[i].S;
 
    sort(v, v+n);
 
    int p = 0, sol = 1;
    for(i=1; i<n; i++){
        if(isIntersectieVida(v[p], v[i])){
            sol ++;
            p = i;
        }
        else if(secondInclusInPrimul(v[p], v[i]))
            p = i;
    }
 
    printf("%d\n", sol);
 
    return 0;
}
