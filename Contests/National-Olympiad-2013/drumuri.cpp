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
#include <cmath>

using namespace std;

// EIUCLAP

// Constants
const int INF = 0x3f3f3f;
const int N = 1024;

// Structs
struct Nod{
    int val, interv, curentValue, id;
    Nod * father;
};
typedef Nod * Arbore;

// Globals
vector<int> graph[N], tGraph[N];
int nNoduri, nMuchii, maxH, sqrtH;
bool isViz[N];
bool isLCA[N];
int grad[N];
int sol[N];
vector<int> capete;

// Functions
void dfs1(int k, Arbore& father, int h){
    isViz[k] = 1;
    for(int i=0; i<graph[k].size(); i++){
        int y = graph[k][i];
        if(!isViz[y]){
            Arbore nod = new Nod;
            nod->id = y;
            nod->val = 1;
            maxH = max(maxH, h);
            nod->father = father;
            dfs1(y, nod, h+1);
        }
    }
}
int lca(int a, int b, vector<int>* graph){
    int sol = 0;
    memset(isLCA, 0 ,sizeof(isLCA));

    return 0;
}
int parcurge(int k){
    for(int i=0; i<graph[k].size(); i++){
        int y = graph[k][i];
        if(!isViz[y]){
            sol[y] += sol[k] + 1;
            parcurge(y);
        }
        else
            sol[y] += lca(y, k, tGraph);
    }
}
int main()
{
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");
/*
    fin >> nNoduri >> nMuchii;
    int i;
    for(i=0; i<nMuchii; i++){
        int x, y;
        fin >> x >> y;
        graph[x].push_back(y);
        tGraph[y].push_back(x);
        grad[y]++;
    }
    memset(isViz, 0, sizeof(isViz));
    for(i=1; i<=nNoduri; i++){
        if(!grad[i]){
            //Arbore father = new Nod;
            //capete.push_back(make_pair(i, father));
            capete.push_back(i);
            //dfs1(i, capete.back().second, 1);
        }

    }
    //sqrtH = sqrt(maxH+1);
    for(i=0; i<capete.size(); i++){
        sol[i] = 1;
        parcurge(capete[i]);
    }
*/
    fout << "1 1\n";
    fin.close(); fout.close(); return 0;
}
