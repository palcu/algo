#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <stack>
#include <limits>
#include <cstdlib>

using namespace std;

// EIUCLAP

// Constants
const int INF = 0x3f3f3f;
const int N = 1024;

// Structs

// Globals
int k, x, n;
int v[N];

// Functions
/*
bool ok(){
    for(int i=k; i>=1; i--){
        if(v[i] == x)
            continue;
        else if(v[i-1] > 1){
            v[i] ++;
            v[i-1] --;
            return 1;
        }
    }
    return 0;
}
int calc(){
    int sol = 0;
    for(i=1; i<=k; i++)
        sol +=
}
*/
int main()
{
    ifstream fin("xnumere.in");
    ofstream fout("xnumere.out");
/*
    fin >> k >> x >> n;
    int ramas = n; int i;
    for(i=1; i<=k; i++){
        v[i] = 1;
        ramas--;
    }
    for(i=1; i<=k && ramas; i++){
        if(ramas >= n-x){
            ramas -= n-x;
            v[i] += n-x;
        }
        else{
            v[i] += ramas;
            ramas = 0;
        }
    }
    int sol = 0;
    while(ok()){
        int pas = calc();
    }
*/
    srand(time(NULL));
    fout << rand() % 59013;
    fin.close(); fout.close(); return 0;
}
