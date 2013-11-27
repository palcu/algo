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

// Globals
int nCazuri, modulo;

// Functions
int MAT[3][3], SOL[3][3];

inline void mult(int A[][3], int B[][3], int C[][3]) {
    int i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % modulo;
    
}

inline void lg_power(int P, int M[][3]) {
    int C[3][3], AUX[3][3], i;
    
    memcpy(C, MAT, sizeof(MAT));
    M[0][0] = M[1][1] = 1;
    
    for (i = 0; (1 << i) <= P; i++) {
        if (P & (1 << i)) {
            memset(AUX, 0, sizeof(AUX));
            mult(M, C, AUX);
            memcpy(M, AUX, sizeof(AUX));
        }
        
        memset(AUX, 0, sizeof(AUX));
        mult(C, C, AUX);
        memcpy(C, AUX, sizeof(C));
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("melodii.in");
	ofstream fout("melodii.out");
	
	fin >> nCazuri >> modulo;
    for (int i=0; i<nCazuri; i++) {
        int N;
        fin >> N;
        MAT[0][0] = 0; MAT[0][1] = 1; MAT[1][0] = 1; MAT[1][1] = 1;
        SOL[0][0] = SOL[0][1] = SOL[1][0] = SOL[1][1] = 0;
        lg_power(N, SOL);
        fout << SOL[1][1] << '\n';
    }
	
	fin.close(); fout.close(); return 0;
}