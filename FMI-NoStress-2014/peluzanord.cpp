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
const int INF = 0x3f3f3f3f;

// Globals
ull a, b;

// Functions
int digitsSum(ull x){
    int sol = 0;
    while(x){
        sol += x%10;
        x /= 10;
    }
    return sol;
}
int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("peluzanord.in");
	ofstream fout("peluzanord.out");
	
	fin >> a >> b;
    int sol = 0;
    int currentSum = digitsSum(a-1);
    for (ull i = a; i<=b; i++) {
        if(i%10 == 0)
            currentSum = digitsSum(i);
        else
            currentSum += 1;
            
        if(i % currentSum == 0)
            sol ++;
    }
    
    fout << sol;
	
	fin.close(); fout.close(); return 0;
}