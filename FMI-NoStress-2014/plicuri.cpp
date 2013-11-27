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
const int N = 100002;
const int INF = 0x3f3f3f3f;

// Globals
pair<int,int> v[N];
int n;

// Functions
int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("plicuri.in");
	ofstream fout("plicuri.out");
	
	fin >> n;
    for (int i=0; i<n; i++) {
        int x,y;
        fin >> x >> y;
        if(x>y) swap(x,y);
        v[i].first = x;
        v[i].second = y;
    }
    sort(v, v+n); int sol = 1;
    pii current = v[0];
    for (int i=1; i<n; i++) {
        if(v[i].first >= current.first && v[i].second >= current.second){
            sol++;
            current = v[i];
        }
    }
    
    fout << sol << '\n';
	
	fin.close(); fout.close(); return 0;
}