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
const int N = 100000;
 
//Global Vars
int n, nOperatii;
int v[N];
 
//Structs
 
//Solve Functions
void update(int poz, int val){
    int bit=0;
 
    while(poz <= n){
        v[poz] += val;
        poz += (poz & -poz);
    }
}
int sum(int poz){
    int bit = 0, sol = 0;
    while(poz > 0){
        sol += v[poz];
        poz -= (poz & -poz);
    }
    return sol;
}
 
void query(int st, int dr){
    int s1 = sum(st-1);
    int s2 = sum(dr);
 
    //cout << s2 - s1 << '\n';
    printf("%d\n", s2 - s1);
}
void pozmin(int val){
    int bitmask, i;
    for(bitmask=1; bitmask<n; bitmask<<=1);
    for(i=0; bitmask!=0; bitmask >>= 1){
        if (i + bitmask <= n){
            if (val >= v[i+bitmask]){
                i += bitmask;
                val -= v[i];
                if (!val){
                    printf("%d\n", i);
                    return;
                }
            }
        }
    }
    printf("-1\n");
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("aib.in","r",stdin);
    freopen("aib.out","w",stdout);
 
    #endif
 
    //cin >> n >> nOperatii;
    scanf("%d%d",&n,&nOperatii);
    int c, val, poz, st, dr;
    for(int i=1; i<=n; i++){
        cin >> val;
        update(i, val);
    }
    for(int op=0; op<nOperatii; op++){
        //cin >> c;
        scanf("%d",&c);
        switch(c){
            case 0:
                //cin >> poz >> val;
                scanf("%d%d",&poz,&val);
                update(poz, val);
                break;
            case 1:
                //cin >> st >> dr;
                scanf("%d%d",&st,&dr);
                query(st, dr);
                break;
            case 2:
                //cin >> val;
                scanf("%d",&val);
                pozmin(val);
                break;
        }
    }
 
    return 0;
}
