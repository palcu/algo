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
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cstring>

using namespace std;

// Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define X first
#define Y second
#define pb push_back

// Structs

// Constants
const int N = 500005;
const int INF = 0x3f3f3f3f;

// Globals
int v[N], lg[N];
bool isMatched[N];
int nAutobuze, autobuze[N];
int sol;

// Functions
int find(int x){
    int varf = x;
    while(varf != v[varf])
        varf = v[varf];
    while(x != v[x]){
        int next = v[x];
        v[x] = varf;
        x = next;
    }
    return varf;
}

void uneste(int a, int b){
    int varfA = find(a), varfB = find(b);
    if(lg[varfA] < lg[varfB]){
        v[varfA] = varfB;
        lg[varfB] += lg[varfA];
    }
    else{
        v[varfB] = varfA;
        lg[varfA] += lg[varfB];
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("autobuze.in");
	ofstream fout("autobuze.out");
    
    fin >> nAutobuze;
    sol = nAutobuze;
    
    for(int i=1; i<=nAutobuze; i++){
        fin >> autobuze[i];
        v[i] = lg[i] = i;
    }
    
    for(int i=1; i<=nAutobuze; i++){
        if(!isMatched[i]){
            for (int j=i+1; j <= nAutobuze; j++) {
                if(!isMatched[j] && (autobuze[i] % autobuze[j] == 0 || autobuze[j] % autobuze[i] == 0)){
                    isMatched[i] = isMatched[j] = 1;
                    cerr << autobuze[i] << " " << autobuze[j] << "\n";
                    uneste(i, j);
                }
            }
        }
    }
    int sol = 0;
    for (int i=1; i<=nAutobuze; i++) {
        cout << v[i] << " ";
        if(v[i] == i)
            sol++;
    }
    
    fout << sol << '\n';
    
    return 0;
}