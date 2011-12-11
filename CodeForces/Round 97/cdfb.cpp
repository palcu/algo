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
int v[128], w[128], myv[128], myw[128];
int nv, nw;

//Structs

//Solve Functions

void inbase(int x, int * v, int &n){
    while(x){
        v[n++] = x%3;
        x/=3;
    }
}

void palcu(int * v, int * myv, int n){
    for(int i=n-1, j=0; i>=0; i--,j++)
        myv[j] = v[i];
}

int tor(int a, int b){
}

int main(){
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int a, b;
    cin >> a >> b;

    inbase(a, v, nv);
    inbase(b, w, nw);

    int n = max(nv, nw);
    palcu(v, myv, n);
    palcu(w, myw, n);

    int i;
    for(i=0; i<n; i++){
        v[i] = 0;
        while(myw[i] != myv[i]){
            v[i] ++;
            myw[i] --;
            if (myw[i] == -1)
                myw[i] = 2;
        }
    }

    int sol=0; int j;
    for(i=0, j=n-1; i<n;i++,j--){
        sol += v[i] * pow(3, j);
    }
    cout << sol;
    return 0;
}
