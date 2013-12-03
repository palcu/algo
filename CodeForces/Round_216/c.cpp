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
struct Nod{
    int a,b;
    bool status;
};

// Constants
const int N = 100001;
const int INF = 0x3f3f3f3f;

// Globals
int n, nElected;
vector<int> v[N];
bool isElected[N];
vector<Nod> init;

// Functions
void verify_parents(int k){
    if (isElected[k]){
        isElected[k] = false; 
        nElected--;
    }
    for(int i=0; i<v[k].size(); i++)
        if(v[k][i] < k)
            verify_parents(v[k][i]);
}
Nod make_nod(int a, int b, int status){
    Nod n;
    n.a=a;
    n.b=b;
    n.status=status;
    return n;
}
bool cmp(Nod a, Nod b){
    return a.a < b.a;
}
int main(){
    freopen("elections.in", "r", stdin);
    freopen("elections.out", "w", stdout);
    
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b, status;
        cin >> a >> b >> status; status--;
        if(a>b) swap(a,b);
        init.push_back(make_nod(a,b,status));
    }
    sort(init.begin(), init.end(), cmp);
    for(int i=0; i<n-1; i++){
        int a, b, status;
        a = init[i].a;
        b = init[i].b;
        status = init[i].status;
        if(status){
            isElected[b] = status; 
            nElected++;
        }
        if(a>b) swap(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
        if(status)
            verify_parents(a);
    }

    cout << nElected << '\n';
    for(int i=2; i<=n; i++)
        if(isElected[i])
            cout << i << ' ';
    cout << '\n';
    
    return 0;
}

