#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

// EIUCLAP
// biperm
// M*1# Lahovari
// VL_C_004

using namespace std;

//Structs

//Constants
const int N = 10008;
const int INF = 0x3f3f3f3f;

//Globals
int n, p1[N], p2[N];
int multimi[N], nMultimi;
vector<int> conflicte;
vector<pair<int,int> > pozitii[N];
bool isInFirst[N], isInSecond[N];
int fatherConflict[N];
bool solvedConflict[N];

//Functions
int father(int a){
    while(a != multimi[a])
        a = multimi[a];
    return a;
}
void uneste(int a, int b){
    int heightA=0, heightB=0;
    while(a != multimi[a]){
        heightA++;
        a = multimi[a];
    }
    while(b != multimi[b]){
        heightB++;
        b = multimi[b];
    }
    if(a != b){
        nMultimi--;
        if(heightA < heightB) multimi[a] = b;
        else multimi[b] = a;
    }
}
inline void schimba(int& a){
    if (a==1)
        a=2;
    else
        a=1;
}
inline void debugVector(){
    for(int i=1; i<=n; i++)
        printf("%d ", p1[i]);
    printf("\n");
    for(int i=1; i<=n; i++)
        printf("%d ", p2[i]);
    printf("\n\n");
}
int main()
{
    freopen("biperm.in" , "r", stdin);
    freopen("biperm.out", "w", stdout);

    int i, j, k, l;
    scanf("%d", &n); nMultimi = n;
    for(i=1;i<=n;i++){
        scanf("%d", &p1[i]);
        pozitii[p1[i]].push_back(make_pair(i,1));
        if(isInFirst[p1[i]])
            conflicte.push_back(p1[i]);
        else
            isInFirst[p1[i]] = true;
    }
    for(i=1;i<=n;i++){
        scanf("%d", &p2[i]);
        pozitii[p2[i]].push_back(make_pair(i,2));
        if(isInSecond[p2[i]])
            conflicte.push_back(p2[i]);
        else
            isInSecond[p2[i]] = true;
    }

    for(i=1;i<=n;i++) multimi[i] = i;

    int nAsemenea = 0;
    for(i=1;i<=n;i++){
        if(p1[i] != p2[i])
            uneste(p1[i], p2[i]);
        else
            nAsemenea++;
    }
    int sol = 1;
    for(i=0; i<nMultimi-nAsemenea; i++)
        sol *= 2;

    /*for(unsigned i=1; i<=n; i++)
        fatherConflict[i] = father(conflicte[i]);*/

    int nMoves = 0;
    const int LIMIT = 1500005;
    for(i=1; i<=n && nMoves < LIMIT; i++)
        if(pozitii[i][0].second == pozitii[i][1].second){
            ++nMoves;
            /*
            for(j=0; j<conflicte.size(); j++)
                if(!solvedConflict[j] && fatherConflict[i] = fatherConflict[j]){
                    int a = conflicte[i];
                    int b = conflicte[j];
                    for(k=0; k<2; k++)
                        for(l=0; l<2; l++)
                            if(pozitii[a][k])
                }
            */
            int a = i, partener;
            //gaseste partener
            if(pozitii[a][0].second == 1)
                partener = p2[pozitii[a][0].first];
            else
                partener = p1[pozitii[a][0].first];
            //schimba in permutari
            swap(p1[pozitii[a][0].first], p2[pozitii[a][0].first]);
            //schimba pozitia primului in hash
            schimba(pozitii[a][0].second);
            //schimba pozitia celui de-al doilea
            //debugVector();
            int oldSchimbare;
            for(j=0; j<2; j++)
                if(pozitii[partener][j].first == pozitii[a][0].first){
                    schimba(pozitii[partener][j].second);
                    oldSchimbare = j;
                }
            //verifica al doilea
            while(pozitii[partener][0].second == pozitii[partener][1].second && nMoves<LIMIT){
                ++nMoves;
                a = partener;
                if(!oldSchimbare)
                    oldSchimbare=1;
                else
                    oldSchimbare=0;
                     //gaseste partener
                if(pozitii[a][oldSchimbare].second == 1)
                    partener = p2[pozitii[a][oldSchimbare].first];
                else
                    partener = p1[pozitii[a][oldSchimbare].first];
                //schimba in permutari
                swap(p1[pozitii[a][oldSchimbare].first], p2[pozitii[a][oldSchimbare].first]);
                //schimba pozitia primului in hash
                schimba(pozitii[a][oldSchimbare].second);
                //schimba pozitia celui de-al doilea
                for(j=0; j<2; j++)
                    if(pozitii[partener][j].first == pozitii[a][0].first){
                        schimba(pozitii[partener][j].second);
                        oldSchimbare = j;
                    }
                //debugVector();
            }
        }








    printf("%d %d\n", sol, nMoves);
    for(i=1; i<=n; i++)
        printf("%d ", p1[i]);
    printf("\n");
    for(i=1; i<=n; i++)
        printf("%d ", p2[i]);
    printf("\n");

    return 0;
}
