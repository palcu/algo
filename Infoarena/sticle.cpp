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

typedef vector<int> VI;
typedef vector<pair<int,int> > VPI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

//Constants

//Global Vars
int v[100];

//Structs

//Solve Functions

int main()
{
        #ifndef ONLINE_JUDGE
        freopen("sticle.in","r",stdin);
        freopen("sticle.out","w",stdout);
        #endif

        int n, i, j; v[0] = 1;

        scanf("%d",&n);

        for(i=1;v[i-1]<50000;++i)
                v[i] = v[i-1]*2;

        int x;
        for(i=0;i<n;++i){
                scanf("%d",&x);
                if (!x){
                        printf("0");
                        continue;
                }
                for(j=0; v[j]<x; ++j)
                        ;
                printf("%d\n",j);
        }

        return 0;
}
