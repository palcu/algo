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

using namespace std;

// EIUCLAP

// Constants
const int INF = 0x3f3f3f;
const int N = 100;

// Structs

// Globals
bool m[N][N];
bool newM[N][N];
int nTest;
int nNoduri, nMuchii;
int v[N];

// Functions
void debug(int* v){
    int s = 0;
    for(int i=1; i<=nNoduri; i++){
        printf("%2d ", v[i]);
        s += v[i];
    }
    printf("\n%2d\n\n", s);
}
void solve(){
    int i,j,k, nRelatii = 0;
    cin >> nNoduri >> nMuchii;
    int maxRelatii = nNoduri*(nNoduri-1)/2;
    memset(v, 0, sizeof(v));
    for(i=0; i<nNoduri; i++){
        memset(m[i], 0, sizeof(m[i]));
        memset(newM[i], 0, sizeof(newM[i]));
    }
    for(i=0; i<nMuchii; i++){
        int a,b;
        cin >> a >> b;
        m[a][b] = m[b][a] = 1;
        v[a]++; v[b]++;
        nRelatii++;
    }
    //debug(v);
    int sol = 0;
    memcpy(newM, m, sizeof(m));
    while(nRelatii != maxRelatii){
        sol ++;
        int rel = 0;
        for(i=1; i<=nNoduri; i++){
            for(j=1; j<=nNoduri; j++)
                if(i != j && m[i][j]){
                    for(k=j+1; k<=nNoduri; k++)
                        if(i!=j && i!=k && j!=k && m[j][k] && !m[i][k] && i<k && !newM[i][k] && !newM[k][i]){
                            newM[i][k] = newM[k][i] = 1;
                            v[i]++; v[k]++;
                            nRelatii++;
                            if(nRelatii >= maxRelatii){
                                cout << sol << '\n';
                                return;
                            }
                        }
                }
        }
        memcpy(m, newM, sizeof(m));
        //debug(v);
    }
    cout << sol << '\n';
}
int main()
{
    //ios_base::sync_with_stdio(false);
    freopen("amici.in", "r", stdin);
    freopen("amici.out", "w", stdout);

    cin >> nTest;
    for(int t=0; t<nTest; t++)
        solve();
    return 0;
}
