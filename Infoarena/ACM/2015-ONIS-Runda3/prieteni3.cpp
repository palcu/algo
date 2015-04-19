#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100001;

int v1[N], v2[N];

unsigned long long solve() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> v1[i];
    for(int i=0; i<m; i++)
        cin >> v2[i];

    unsigned long long sol = 0;
    sort(v1, v1+n);
    sort(v2, v2+m, std::greater<int>());

    int x = min(n, m);
    for(int i=0; i<x; i++)
        if (v1[i] < v2[i])
            sol += v2[i] - v1[i];
    return sol;
}

int main() {
    freopen("prietenie3.in", "r", stdin);
    freopen("prietenie3.out", "w", stdout);

    int nTeste;
    cin >> nTeste;
    for(int i=0; i<nTeste; i++) {
        cout << solve() << "\n";
    }
    return 0;
}
