#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

ifstream in("algoritm.in");
ofstream out("algoritm.out");

const int Nmax = 100005;
const int Mmax = 200010;
const int inf = 2000000000;

struct edge {
  int y, c;
  int nr;
  edge(int p1, int p2, int p3) : y(p1), c(p2), nr(p3) {}
};

int t;
int n, m;
int x1, x2;
vector<vector<edge>> graph;
vector<vector<int>> graph2;
int path[Nmax];
int edges[Mmax][2];
int visited[Mmax];
int finish[Mmax];

void bellman() {
  queue<int> q;
  vector<edge>::iterator it;
  finish[1] = 0;
  visited[1] = 1;
  q.push(1);

  while (!q.empty()) {
    int t = q.front();
    q.pop();
    visited[t] = 0;
    for (it = graph[t].begin(); it != graph[t].end(); ++it) {
      if (finish[t] + it->c < finish[it->y]) {
        finish[it->y] = finish[t] + it->c;
        path[it->y] = it->nr;
        if (!visited[it->y])
          q.push(it->y);
      }
    }
  }
}

void add_path(int y) {
  int x;
  while (y != 1) {
    x = edges[path[y]][0];
    graph2[path[x]].push_back(path[y]);
    y = x;
  }
}

void dfs(int node) {
  visited[node] = 1;
  vector<int>::iterator it;
  for (it = graph2[node].begin(); it != graph2[node].end(); ++it)
    if (!visited[*it])
      dfs(*it);
  finish[++finish[0]] = node;
}

int main() {
  int a, b, c;
  in >> t;
  for (int i = 1; i <= t; ++i) {
    in >> n >> m;
    graph.resize(n + 1);
    graph2.resize(m + 1);
    for (int j = 1; j <= n; ++j)
      graph[j].clear();

    for (int j = 1; j <= n; ++j) {
      finish[j] = inf;
      visited[j] = 0;
    }

    for (int j = 1; j <= m; ++j) {
      in >> a >> b >> c;
      edges[j][0] = a;
      edges[j][1] = b;
      graph[a].push_back(edge(b, c, j));
    }

    bellman();
    for (int i = 2; i <= n; ++i)
      if (finish[i] != inf)
        add_path(i);

    for (int i = 1; i <= m; ++i)
      visited[i] = 0;
    finish[0] = 0;

    for (int i = 1; i <= m; ++i)
      if (!visited[i])
        dfs(i);

    for (int i = m; i > 0; --i)
        out << finish[i] << ' ';
  }
}
