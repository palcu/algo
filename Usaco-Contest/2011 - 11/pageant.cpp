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
const int NMAX = 64;
const int INF = 1<<30;
const int vx[] = {1,-1,0,0}, vy[]={0,0,1,-1};

//Global Vars
typedef int Matrix[NMAX][NMAX];
int a,b;
int sol = INF;
Matrix m;

//Structs

//Solve Functions
void debug_matrix(Matrix m){
    int i,j;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if (m[i][j] == -2)
                printf("m ");
            else if(m[i][j] == -3)
                printf("x ");
            else
                printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

pair<int,int> findSpot(int startx, int starty){
    int i,j;
    for(i=startx; i<a; i++)
        for(j=starty; j<b; j++)
            if(m[i][j] == -1)
                return pair<int,int>(i,j);
    //There is only one spot
    printf("0\n");
    exit(0);
}

inline bool in(int x, int y){
    return 0<=x && x<a && 0<=y && y<b;
}

void fill_matrix(pair<int,int> start, int etiquete){
    queue<pair<int,int> > coada;
    coada.push(start);
    while(!coada.empty()){
        pair<int,int> current = coada.front();
        coada.pop();
        for(int i=0;i<4;i++){
            int newx = current.first + vx[i];
            int newy = current.second + vy[i];
            if(in(newx,newy) && m[newx][newy] == -1){
                m[newx][newy] = etiquete;
                coada.push(make_pair(newx,newy));
            }
        }
    }
}

bool isMargin(int x, int y){
    for(int i=0;i<4;i++){
        int newx = x+vx[i];
        int newy = y+vy[i];
        if(in(newx,newy) && !m[newx][newy]);
            return true;
    }
    return false;
}

void calcCost(int startx, int starty){
    int i,j;

    Matrix mym;
    for(i=0;i<a;i++)
        memcpy(mym[i], m[i], sizeof(m[i]));

    queue<pair<int,int> > coada;
    mym[startx][starty] = 1;
    coada.push(make_pair(startx,starty));
    while(!coada.empty()){
        int x = coada.front().first, y = coada.front().second;
        coada.pop();
        for(int i=0;i<4;i++){
            int newx = x+vx[i];
            int newy = y+vy[i];
            if(in(newx,newy)){
                if(mym[newx][newy]==-3){
                    //printf("%d %d --- %d\n", x, y, mym[x][y]);
                    int kkk = mym[x][y] - 1;
                    sol = min(sol, kkk);
                }
                else if(!mym[newx][newy]){
                    mym[newx][newy] = mym[x][y] + 1;
                    //debug_matrix(mym);
                    coada.push(make_pair(newx, newy));
                }
            }
        }
    }
}

int main(){
    freopen("pageant.in","r",stdin);
    freopen("pageant.out","w",stdout);

    int i,j;
    char c;
    scanf("%d %d\n", &a, &b);
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            scanf("%c", &c);
            if (c == 'X')
                m[i][j] = -1;
        }
        scanf("\n");
    }

    pair<int,int> startPosition = findSpot(0,0);
    fill_matrix(startPosition, -2);

    startPosition = findSpot(startPosition.first+1, startPosition.second);
    fill_matrix(startPosition, -3);

    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            if(m[i][j] == -2 && isMargin(i,j)){
                calcCost(i,j);
            }
    printf("%d\n", sol);
    return 0;
}

