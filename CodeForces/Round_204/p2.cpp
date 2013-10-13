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
const int N = 100020;
const int INF = 0x3f3f3f3f;

// Globals
int n, poz[N], dif[N];

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("p2.in", "r", stdin);
	freopen("p2.out", "w",stdout);
	#endif

    scanf("%d", &n);
    int i, sol=0, x;
    for(i=1; i<=n; i++){

        scanf("%d", &x);
        if(poz[x] != -1){
            if(poz[x]){
                if(!dif[x]){
                    dif[x] = i - poz[x];
                    poz[x] = i;
                }
                else{
                    if(i - poz[x] != dif[x]){
                        poz[x] = -1;
                        sol--;
                    }
                    else{
                        poz[x] = i;
                    }
                }
            }
            else{
                if(!poz[x])
                    sol++;
                poz[x] = i;
            }
        }
    }
    printf("%d\n", sol);
    for(i=1; i<=N; i++)
        if(poz[i] != -1 && poz[i])
            printf("%d %d\n", i, dif[i]);

	return 0;
}
