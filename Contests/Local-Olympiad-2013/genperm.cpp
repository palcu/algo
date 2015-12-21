#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cstdlib>

// EIUCLAP
// PROBLEMA
// M*1# Lahovari
// VL_C_004

using namespace std;

//Structs

//Constants
const int N = 100000;
const int INF = 0x3f3f3f3f;

//Globals
int n=10000, v[N], vals[N], is[N];

//Functions

int main()
{
    freopen("problema.in" , "r", stdin);
    freopen("problema.out", "w", stdout);


    srand( 9 );
    //time(NULL);
    int i;
    for(int i=1, j=1; i<=n*2; i++){
        vals[i] = j;
        if(i%2 == 0) j++;
    }
    for(i=1; i<=n*2; i++){
        int myVal = 0, myPos = 0;
        while(!myVal){
            int x = rand() % (n*n) + 1;
            while(is[x])
                x++;
            myVal = vals[x];
            myPos = x;
        }
        v[i] = myVal;
        is[myPos] = 1;
    }
    for(i=1; i<=n*2; i++){
        printf("%d ", v[i]);
        if(i==n)
            printf("\n");
    }

    return 0;
}
