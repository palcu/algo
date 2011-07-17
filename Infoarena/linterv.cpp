/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2011
 * http://infoarena.ro/problema/linterv
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

typedef vector<int> VI;
typedef vector<pair<int,int> > VPI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

//Constants
const int NMAX = 5000;

//Global Vars
int n;
PII v[NMAX];

//Structs

//Solve Functions
inline void debug_vector(){
        for(int i=0;i<n;++i)
                printf("%d %d\n",v[i].first,v[i].second);
        printf("\n");
}

inline bool cmp(PII a, PII b){
        if (a.first != b.first)
                return a.first<b.first;
        return a.second>b.second;
}

void solve(){
        int i, a, b, sol=0;
        scanf("%d",&n);

        for(i=0;i<n;++i)
                scanf("%d%d",&v[i].first,&v[i].second);

        sort(v,v+n,cmp);

        //debug_vector();

        a = v[0].first;
        b = v[0].second;

        for(i=1; i<n; ++i){
                if (b < v[i].first){
                        sol += b-a;
                        a = v[i].first;
                        b = v[i].second;
                }
                else if (v[i].second > b)
                        b = v[i].second;
        }

        sol += b-a;
        printf("%d\n",sol);
}

int main()
{
        #ifndef ONLINE_JUDGE
        freopen("linterv.in","r",stdin);
        freopen("linterv.out","w",stdout);
        #endif

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
                solve();


        return 0;
}
