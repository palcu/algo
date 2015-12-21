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
const int N = 1<<10;
const int NLINII = 276997;
const int NLINII_PROASTE = 10;
const int INF = 0x3f3f3f3f;

// Globals
char x[N];
int v[5] = {2,3,5,7,11};

// Functions
int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("dtcsu.in");
	ofstream fout("dtcsu.out");
	
	for (int i=0; i<NLINII; i++) {
        fin.getline(x, N);
    }
    
    int n;
    fin >> n; int sol = 0;
    for (int i=0; i<n; i++) {
        int k; fin >> k;
        for(int j=0; j<5; j++){
            while(k % v[j] == 0)
                k /= v[j];
        }
        if(k==1) sol++;
    }
    fout << sol << '\n';
	
	fin.close(); fout.close(); return 0;
}