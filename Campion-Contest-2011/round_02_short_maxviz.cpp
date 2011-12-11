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
const int NMAX = 302;

//Structs
struc Segment{
    int x,y,l;
}
Segment make_segment(int x, int y, int l){
    Segment s;
    s.x = x; s.y = y; s.l=l;
    return s;
}

//Global Vars
int n;
Segment v[NMAX];

//Solve Functions

int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    #endif

    scanf("%d",&n);
    int a,b;
    for(int i=0; i<n; i++){
        scanf("%d %d\n", &a,&b);
        v[i].x = a; v[i].y = b; v[i].l = b-a;
    }



    return 0;
}
