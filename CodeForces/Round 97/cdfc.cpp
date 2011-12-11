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

//Global Vars
int v[100005];

//Structs

//Solve Functions

int main(){
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif

    int n; cin >> n;
    int m = 0, poz, i;
    for(i=0;i<n;i++){
        cin >> v[i];
        if (v[i] > m){
            m = v[i];
            poz = i;
        }
    }
    v[poz]=1;
    sort(v, v+n);
    for(i=0;i<n;i++)
        printf("%d ",v[i]);

    return 0;
}
