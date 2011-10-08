/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2011
****************************************************/

#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

//Constants

//Global Vars
int n, same, sol=999999999;
int v[1024];
int vsol[1024];


//Structs

//Solve Functions
inline int myabs(int i){
    if (i<0)
        return -i;
}
bool sorting(pair<int,int> a, pair<int,int> b){
    if (a.first!=b.first)
        return a.first<b.first;
    else
        return a.second<b.second;
}
void solve(int k){
    int i;
    vector<pair<int,int> > myp;

    for(i=0; i<n; i++){
        int alex = v[i]-k;
        if (alex<0)
            alex=-alex;
        myp.push_back(make_pair(alex,i));
    }

    sort(myp.begin(),myp.end(),sorting);

    int moves = 0;
    for(i=0;i<same;i++)
        moves+=myp[i].first;
    //printf("%d %d\n",k,moves);
    if (moves<sol){
        sol=moves;
        for(i=0;i<n;i++)
            vsol[i]=v[i];
        for(i=0;i<same;i++)
            vsol[myp[i].second] = k;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif

    int i;
    char c;
    cin >> n >> same;
    scanf("\n");
    for(i=0; i<n; i++){
        scanf("%c",&c);
        v[i] = c - '0';
    }

    for(i=0; i<=9; i++)
        solve(i);

    printf("%d\n",sol);
    for(i=0;i<n;i++)
        printf("%d",vsol[i]);
    printf("\n");

    return 0;
}
