/***************************************************
 * Alex Palcuie
 * Romania - 2013
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
 * FeMei fara stres
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
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cstring>
#include <climits>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Constants
const int N = 50001;
const int INF = 0x3f3f3f3f;

// Defines
#define F first
#define S second
#define pb push_back
#define sz size()
#define mp make_pair
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

int d[N];
bitset<N> inQueue;

struct comp{
    bool operator () (int a, int b){
        return d[a] > d[b];
    }
};

// Globals
priority_queue<int, vector<int>, comp> pq;
int nNoduri, nMuchii, greutateMinima;

vector<pair<int,bool> > graph[N];

// Functions
int main(){
    ios_base::sync_with_stdio(false);
    ifstream fin("camionas.in");
    ofstream fout("camionas.out");
    
    fin >> nNoduri >> nMuchii >> greutateMinima;
    
    for (int i=0; i<nMuchii; i++) {
        int a, b, val;
        fin >> a >> b >> val;
        bool weight;
        if (val < greutateMinima) {
            weight = 1;
        }
        else
            weight = 0;
        graph[a].push_back(make_pair(b, weight));
        graph[b].push_back(make_pair(a, weight));
    }
    
    fill_n(d+1, nNoduri, INF);
    d[1] = 0;
    pq.push(1);
    
    
    while(!pq.empty()){
        int nod = pq.top();
        pq.pop();
        inQueue[nod] = false;
        for(unsigned i=0; i<graph[nod].size(); i++){
            pair<int,int> x = graph[nod][i];
            if(d[x.first] > d[nod] + x.second){
                d[x.first] = d[nod] + x.second;
                if(!inQueue[x.first])
                    pq.push(x.first);
            }
        }
    }
    
    fout << d[nNoduri] << '\n';
    
    fin.close(); fout.close(); return 0;
}