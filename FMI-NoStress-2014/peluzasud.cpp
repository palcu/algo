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
ull MAX_BILET = 1000000000000000L;

// Globals
ull nBilete, xBigger;

// Functions
bool isPrim(ull k){
    if(k == 2) return true;
    if(k%2 == 0) return false;
    ull rad = sqrt(k);
    for(ull i=3; i<=rad; i+=2)
        if(k%i == 0)
            return false;
    return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("peluzasud.in");
	ofstream fout("peluzasud.out");
    
    fin >> nBilete >> xBigger;
	
    //for(int bilet=xBigger; bilet <= MAX_BILET; bilet++)
    //    if(!is_prim(bilet))
    
    ull lastNonPrim = 0;
    
    for (ull i=xBigger + 1; i<=MAX_BILET; i++) {
        if(!isPrim(i)){
            if(!lastNonPrim)
                lastNonPrim = i;
            else{
                if(i - lastNonPrim + 1 > nBilete){
                    fout << lastNonPrim << '\n';
                    break;
                }
            }
        }
        else
            lastNonPrim = 0;
    }
	
	
	fin.close(); fout.close();
    return 0;
}