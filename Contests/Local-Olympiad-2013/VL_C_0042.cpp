#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

// EIUCLAP
// subsecvente
// M*1# Lahovari
// VL_C_004

using namespace std;

//Structs

//Constants
const int N = 50005;
const int INF = 0x3f3f3f3f;

//Globals
int nSiruri;
char sol[N];
int lSol;

//Functions
inline void debugVector(char* v, int n){
    for(int i=0; i<n; i++){
        printf("%c", v[i]);
    }
    printf("\n");
}
int main()
{
    freopen("subsecvente.in" , "r", stdin);
    freopen("subsecvente.out", "w", stdout);

    scanf("%d\n", &nSiruri);
    scanf("%s\n", sol); lSol = strlen(sol);
    char deCautat[N];
    int i,j,k, lDeCautat;
    for(i=1; i<nSiruri; i++){
        scanf("%s\n", deCautat); lDeCautat = strlen(deCautat);
        int lmax = 0, startMax = 0, endMax = 0;
        for(j=0; j<lDeCautat; j++){
            for(k=0; k<lSol; k++){
                if(deCautat[j] == sol[k]){
                    int lg = 0; int a=j; int b=k;
                    while(deCautat[a] == sol[b] && a<lDeCautat && b<lSol){
                        lg++;
                        a++; b++;
                    }
                    if(lg>lmax){
                        lmax = lg;
                        startMax = k;
                        endMax = b;
                    }
                }
            }
        }
        char newSol[N];
        for(k=startMax, j=0; k<endMax; k++, j++)
            newSol[j] = sol[k];
        for(j=0; j<lmax; j++)
            sol[j] = newSol[j];
        lSol = lmax;
    }
    //debugVector(sol, lSol);
    printf("%d\n", lSol);

    return 0;
}
