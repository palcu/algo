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
const int N = 200008;

// Structs
struct Nod{
    bool negru;
    int x;
    Nod * father;
    vector<Nod *> v;
};
Nod varf;
Nod * v[N];

// Globals
int nNoduri, nQuery;

// Functions
int cauta(int x, int y){
    if(x<y) swap(x,y);
    int sol = 0;
    Nod myNod = *v[x];
    while(true){
        sol++;

        if(myNod.negru)
            break;

        if(myNod.x == y){
            return -1;
        }
        else
            myNod = *myNod.father;
    }
    return myNod.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("confuzie.in");
    ofstream fout("confuzie.out");

    fin >> nNoduri >> nQuery;

    varf.x = 1;
    varf.father = NULL;
    v[1] = &varf;

    for(int i=1; i<nNoduri; i++){
        int x,y; fin >> x >> y;
        Nod myNod = *v[x];
        Nod * p = new Nod;
        p->x = y; p->negru = 0;
        p->father = &myNod;
        myNod.v.push_back(p);
        v[y] = p;
    }
    for(int i=0; i<nQuery; i++){
        int x,y,op;
        fin >> op;
        if(op == 0){
            fin >> x;
            Nod myNod = *v[x];
            myNod.negru = !myNod.negru;
        }
        else{
            fin >> x >> y;
            fout << cauta(x, y) << '\n';
        }
    }

    fin.close(); fout.close(); return 0;
}
