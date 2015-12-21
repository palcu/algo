/***************************************************
 * Alex Palcuie
 * Romania - 2015
 * alex [dot] palcuie [at] gmail [dot] com
 * http://blog.palcu.ro/
****************************************************/

#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Defines
#define NAME(n) #n
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define F first 
#define S second 
#define pb push_back
#define sz size()
#define mp make_pair
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

// Helpers
template <typename T> inline void dbv(const T * v, const char * name, int n){
    fprintf(stderr, "=== %s ===\n", name);
    for(int i=0; i<n; i++)
        cerr << v[i] << " ";
    cerr << '\n';
}
template<typename T> void dbw(const std::vector<T>& t, const char * name){
    fprintf(stderr, "=== %s ===\n", name);
    unsigned n = t.size();
    for(typename std::vector<T>::size_type i=0; i<n; ++i)
        std::cerr << t[i] << ' ';
    cerr << '\n';
}

// Structs
struct Edge {
    int index, value, to;
    Edge(int a, int b, int c): index(a), value(b), to(c) { }
};

struct Compare {
    bool operator() (Edge a, Edge b) {
        return a.value > b.value;
    }
};
// Constants
const int N = 2 * pow(10, 5) + 2;
const int INF = 0x3f3f3f3f;

// Functions
int main(){
    #ifndef ONLINE_JUDGE
    freopen("cde.in", "r", stdin);
    #endif
    
    int nNodes, nEdges; cin >> nNodes >> nEdges;
    vector<vector<Edge>> graph(N);
    for (int i=0; i<nEdges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Edge(i, c, b));
        graph[b].push_back(Edge(i, c, a));
    }

    priority_queue<Edge, vector<Edge>, Compare> pq;
    for (int i=0; i<graph[1].size(); i++)
        pq.push(graph[1][i]);
    
    vector<bool> node_visited(nNodes, 0);
    vector<bool> edge_in_tree(nEdges, 0);
    int nVisited = 1; 
    node_visited[1] = 1;
    int cost = 0;

    while (nVisited < nNodes && !pq.empty()) {
        Edge edge = pq.top(); pq.pop();
        if (!node_visited[edge.to]) {
            nVisited++;
            node_visited[edge.to] = true;
            cost += edge.value;
            edge_in_tree[edge.index] = true;

            for (int i=0; i<graph[edge.to].size(); i++)
                pq.push(graph[edge.to][i]);
        }
    }

    cout << cost << endl;

    return 0;
}

