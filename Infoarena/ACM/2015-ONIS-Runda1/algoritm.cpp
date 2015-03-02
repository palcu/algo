#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>

using namespace std;

unordered_map<int, int> muchii;

struct Nod{
    int y,val;
    Nod(int a, int b){
        y=a;
        val=b;
    }
};

const int N = 100004;
const int INF = 0x3f3f3f3f;

int nNoduri, nMuchii;
vector<Nod> g[N];
int sol[N];
int deLaVinePrin[N];
bool inQueue[N];
bool isMuchieBuna[N*2];
deque<int> sortTopologica;

void dfs(int k){
    for(int i=0; i<g[k].size(); i++) {
        if(!inQueue[g[k][i].y]){
            inQueue[g[k][i].y] =1;
            dfs(g[k][i].y);
        }
    }
    sortTopologica.push_front(k);
}

int main() {
    ifstream fin("algoritm.in");
    ofstream fout("algoritm.out");

    int t; fin >> t;
    for(int tt=0; tt<t; tt++) {
        int nNoduri, nMuchii;
        fin >> nNoduri >> nMuchii;
        muchii.clear();
        for(int i=1; i<=nNoduri; i++)
            g[i].clear();
        memset(sol, 0, sizeof(sol));
        memset(deLaVinePrin, 0, sizeof(deLaVinePrin));
        memset(inQueue, 0, sizeof(inQueue));
        memset(isMuchieBuna, 0, sizeof(isMuchieBuna));
        sortTopologica.clear();

        int a,b,c, i;
        for(i=0; i<nMuchii; i++){
            fin >> a >> b >> c;
            muchii[a*N+b] = i;
            g[a].push_back(Nod(b,c));
        }

        for(i=1; i<=nNoduri; i++)
            sol[i] = INF;

        queue<int> q;
        q.push(1);
        sol[1] = 0; inQueue[1]=1;

        int x;
        while(!q.empty()) {
            x = q.front(); q.pop(); inQueue[x] = 0;
            for(i=0; i<g[x].size(); i++){
                Nod a = g[x][i];
                if(sol[a.y] > sol[x] + a.val){
                    deLaVinePrin[a.y] = x;
                    sol[a.y] = sol[x] + a.val;
                    // cout << sol[a.y] << endl;
                    if (!inQueue[a.y]) {
                        q.push(a.y);
                        inQueue[a.y] = 1;
                    }
                }
            }
        }

        // for(int i=1; i<=nNoduri; i++){
        //     cout << sol[i] << " " << deLaVinePrin[i] << "\n";
        // }
        memset(inQueue, 0, sizeof(inQueue));
        for(int i=1; i<=nNoduri; i++)
            if(!inQueue[i]){
                inQueue[i] = 1;
                dfs(i);
            }
        for(deque<int>::iterator it = sortTopologica.begin(); it!=sortTopologica.end(); it++) {
            int val = *it;
            if (val != 1) {
                int deUndeVine = deLaVinePrin[val];
                int indexMuchie = muchii[val+deUndeVine*N];
                isMuchieBuna[indexMuchie] = true;
                fout << indexMuchie + 1 << " ";
            }
        }
        for(int i=0; i<nMuchii;i++)
            if(!isMuchieBuna[i])
                fout << i + 1 << " ";
        fout << "\n";
    }


    return 0;
}
