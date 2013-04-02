#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <stack>
#include <limits>

using namespace std;

// EIUCLAP

// Constants
const int INF = 0x3f3f3f;
const int N = 1508;

// Structs

    // Globals
int a, b;
vector<int> v;
int m[N][N];
bool l[N]; /// Daca as fi pus N*N, solutia de 50 de puncte

// Functions
void minMatrix(int x1, int y1, int x2, int y2){
    int i,j;

    if(x1 == x2){
        for(i=y1; i<=y2; i++)
            if(!l[m[x1][i]]){
                v.push_back(m[x1][i]);
                l[m[x1][i]] = 1;
            }
        return;
    }
    else if (y1 == y2){
        for(i=x1; i<=x2; i++){
            if(!l[m[i][y1]]){
                v.push_back(m[i][y1]);
                l[m[i][y1]] = 1;
            }
        }
        return;
    }
    int myMin = INF, pozx, pozy;

    for(i=x1; i<=x2; i++)
        for(j=y1; j<=y2; j++)
            if(myMin > m[i][j] && !l[m[i][j]]){
                myMin = m[i][j];
                pozx = i;
                pozy = j;
            }
    l[m[pozx][pozy]] = 1;
    minMatrix(x1, y1, pozx, pozy);
    v.push_back(m[pozx][pozy]);
    minMatrix(pozx, pozy, x2, y2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("bemo.in");
    ofstream fout("bemo.out");

    int i,j;
    fin >> a >> b;
    for(i=0; i<a; i++)
        for(j=0; j<b; j++)
            fin >> m[i][j];
    minMatrix(0,0,a-1, b-1);
    for(i=0; i<a+b-1; i++)
        fout << v[i] << ' ';
    fout <<'\n';
    fin.close(); fout.close();
    return 0;
}
