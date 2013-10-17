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
const int N = 100008;
const int INF = 0x3f3f3f3f;

// Globals
int v[N], n, nQuery;

// Functions
int simple(int k){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(k == v[mid]){
            while(k == v[mid+1])
                mid++;
            return mid;
        }
        if(k < v[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -2;
}
int q1(int k){
    int l = 0, r = n-1;
    int sol = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(v[m] <= k){
            sol = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return sol;
}
int q2(int k){
    int l = 0, r = n - 1, sol = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(v[m] >= k){
            sol = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return sol;
}
int main(){
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	ifstream fin("cautbin.in");
	ofstream fout("cautbin.out");
	#endif

	int i; fin >> n;
	for(i=0; i<n; i++) fin >> v[i];
	fin >> nQuery; for(i=0; i<nQuery; i++){
        int op, k;
        fin >> op >> k;
        if(op == 0)
            fout << simple(k) + 1 << '\n';
        else if (op == 1)
            fout << q1(k) + 1 << '\n';
        else    fout << q2(k) + 1 << '\n';
	}

	fin.close(); fout.close(); return 0;
}
