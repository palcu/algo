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
const int NMAX = 100001;

//Global Vars
int nPahare, nMutari;
vector<int> v[NMAX];
bool isChecked[NMAX];
vector<pair<int,int> > sol;

//Structs

//Solve Functions
void change(int& a, int& b){
    int c;
    c = a;
    a = b;
    b = c;
}

int dfs(int k){
    int sol = 0;
    for(int i=0; i<v[k].size(); i++)
        if(!isChecked[v[k][i]]){
            isChecked[v[k][i]] = true;
            sol += 1 + dfs(v[k][i]);
        }
    return sol;
}

bool cmp(pair<int, int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("turn1.in","r",stdin);
    freopen("turn1.out","w",stdout);
    #endif

    scanf("%d%d", &nPahare, &nMutari);
    int i;

    int a,b;
    for(i=0; i<nMutari; i++){
        scanf("%d%d", &a, &b);
        if (a!=b){
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    for(i=1; i<=nPahare; i++)
        if(!isChecked[i]){
            sol.push_back(make_pair(i,dfs(i)));
        }

    vector<pair<int,int> >::iterator it;
    it = max_element(sol.begin(), sol.end(), cmp);
    cout << it->first << " ";
    sol.erase(it);
    it = max_element(sol.begin(), sol.end(), cmp);
    cout << it->first << '\n';

    return 0;
}
