/***************************************************
 * Alex Palcuie
 * Romania - 2013
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
 * FeMei fara stres
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
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Defines
#define F first
#define S second
#define pb push_back
#define sz size()
#define mp make_pair
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

// Structs

// Constants
const int N = 1000020;
const int INF = 0x3f3f3f3f;

// Globals
ull nBeri, k, q, x, y, z;
ull v[N];

// Functions
bool sortare(ull x, ull y){
    return x > y;
}
ull max_ull(ull a, ull b){
    if(a>b) return a;
    return b;
}
int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("beri.in");
	ofstream fout("beri.out");
	
	fin >> nBeri >> k;
    fin >> q >> x >> y >> z;
    
    v[0] = q;
    for (int i=1; i<nBeri; i++) {
        v[i] = (v[i-1] * x + y) % z + k;
    }
    sort(v, v+nBeri, sortare);
    ull sol = 0;
    for (ull i=0; i<k; i++) {
        sol += max_ull(0, v[i]-i);
    }
    
    fout << sol << '\n';
	
	fin.close(); fout.close(); return 0;
}