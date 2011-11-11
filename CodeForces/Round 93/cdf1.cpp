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
const int NMAX = 100;

//Global Vars
int n,k;
int v[NMAX];

//Structs

//Solve Functions


int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif

    int vx0, vy0, vx1, vy1, x, y;
    double s = 0;

    scanf("%d%d",&n,&k);
    scanf("%d%d",&vx0,&vy0);

    for (int i=1;i<n;i++){
        scanf("%d%d",&vx1, &vy1);
        x = vx0 - vx1;
        y = vy0 - vy1;

        s += sqrt(x*x + y*y);

        vx0 = vx1;
        vy0 = vy1;
    }
    cout << setprecision(8) <<  s*k / 50 << '\n';

    return 0;
}

