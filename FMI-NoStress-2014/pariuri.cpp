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
const int N = 1000000000;
const int INF = 0x3f3f3f3f;

// Globals
int baniLaTimp[N+1];
bool isTimeUsed[N+1]; int noOfTimeUsed;
int nJucatori;

// Functions
int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("pariuri.in");
	ofstream fout("pariuri.out");
	
	fin >> nJucatori;
    for (int i=0; i<nJucatori; i++) {
        int nPariuri;
        fin >> nPariuri;
        for (int j=0; j<nPariuri; j++) {
            int timp, suma;
            fin >> timp >> suma;
            baniLaTimp[timp] += suma;
            if(!isTimeUsed[timp]){
                isTimeUsed[timp] = 1;
                noOfTimeUsed++;
            }
        }
    }
    fout << noOfTimeUsed << '\n';
    for (int i=1; i<=N; i++) {
        if (isTimeUsed[i]) {
            fout << i << " " << baniLaTimp[i] << " ";
        }
    }
    fout << '\n';
	
	fin.close(); fout.close(); return 0;
}