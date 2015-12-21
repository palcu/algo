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
unsigned long long MAXS = pow(10, 12) + 2;

// Globals
vector<int> bells;

// Functions
int boxes_can_fit(unsigned long long box_size) {
    unsigned long long res = 1, curr = 0, left = 0, right = bells.size() - 1;

    while (left != right && res < 1000000) {
        if (curr + bells[right] <= box_size) {
            curr += bells[right];
            right--;
        } else if (curr + bells[left] <= box_size) {
            curr += bells[left];
            left++;
        } else {
            res++;
            curr=0;
        }
    }
    if (curr + bells[right] <= box_size) {
        curr += bells[right];
    } else {
        res++;
    }

    cout << box_size << " " << res << endl;
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("334b.in", "r", stdin);
    //freopen("334b.out", "w", stdout);
    #endif
    
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        int x; cin >> x;
        bells.push_back(x);
    }

    unsigned long long left = bells.back(), right = MAXS;

    while (left <= right) {
        unsigned long long middle = right - (right - left) / 2;

        if (boxes_can_fit(middle) <= k) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    cout << left << endl;
    

    
    return 0;
}

