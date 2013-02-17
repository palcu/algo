#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int NMAX = 2<<7;
const int INF = 1001;
 
int matrix[NMAX][NMAX];
int nNoduri;
 
int main()
{
    freopen("royfloyd.in","r",stdin);
    freopen("royfloyd.out","w",stdout);
 
    scanf("%d",&nNoduri);
 
    int i,j,k;
 
    for(i=0;i<nNoduri;++i)
        for(j=0;j<nNoduri;++j){
            scanf("%d",&matrix[i][j]);
            if (!matrix[i][j] && i!=j)
                matrix[i][j] = INF;
        }
 
    for (k=0;k<nNoduri;++k)
        for(i=0;i<nNoduri;++i)
            for (j=0;j<nNoduri;++j)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
 
    for (i=0;i<nNoduri;++i){
        for(j=0;j<nNoduri;++j)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
 
    return 0;
}