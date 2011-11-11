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
const int NMAX = 1000;

//Global Vars
int n,k;
int m[NMAX][NMAX];

//Structs
struct Tup{
    int t1,t2;
    double t;
};

Tup make_tup(int t1, int t2, double t){
    Tup tup;
    tup.t1 = t1;
    tup.t2 = t2;
    tup.t = t;
    return tup;
}

//Solve Functions
vector<Tup> v;

bool sorting(Tup a, Tup b){
    if (a.t==b.t)
        return a.t1+a.t2>b.t1+b.t2;
    return a.t < b.t;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    #endif

    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    int i,j;
    double t;
    for(i=1;i<=x1;i++){
        cout << "";
        for(j=1;j<=x2;j++){
            t = (double) (t1 * i + t2 * j) / (double)(i + j);
            if (t>=t0)
                v.push_back(make_tup(i,j,t));
        }
    }

    sort(v.begin(),v.end(),sorting);

    for(i=0;i<v.size();i++)
        if(v[i].t == t0)
            cout << v[i].t1 << " " << v[i].t2 << " " << v[i].t <<'\n';
    return 0;
}

