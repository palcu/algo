/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2011
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
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//Constants
const int NMAX = 301;
typedef int Matrix[NMAX][NMAX];

//Global Vars
int nBile, nCantariri;
int maxCantariri;
vector<int> from[NMAX], to[NMAX];
int sol, veciniCurenti;
bitset<NMAX> vecini;

//Structs


//Solve Functions
void dfs(int x, vector<int>* v){
    for(int i=0; i<v[x].size(); i++){
            if(!vecini[v[x][i]]){
                vecini[v[x][i]] = true;
                ++veciniCurenti;
                if(veciniCurenti >= maxCantariri)
                    return;
                dfs(v[x][i], v);
            }
        }
}

bool dfs_direction(int x, vector<int>* v){
    vecini.reset(); veciniCurenti = 0;
    dfs(x, v);
    if (veciniCurenti >= maxCantariri){
        ++sol;
        return true;
    }
    else
        return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("bile1.in","r",stdin);
    freopen("bile1.out","w",stdout);
    #endif

    scanf("%d%d", &nBile, &nCantariri);
    maxCantariri = nBile/2+1;

    int i,j;
    int a,b;

    for(i=0; i<nCantariri; i++){
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        to[b].push_back(a);
    }

    for(int i=1; i<=nBile; i++){
        if (!dfs_direction(i, from))
            dfs_direction(i, to);
    }

    printf("%d\n",sol);

    return 0;
}
