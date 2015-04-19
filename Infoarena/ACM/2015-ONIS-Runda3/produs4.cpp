#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 30001;

long long v[N];

long long solve() {
    int n;
    cin >> n;
    int nNegative = 0, nPozitive = 0;

    for(int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] < 0)
            nNegative++;
        else
            nPozitive++;
    }

    sort(v, v+n);
    if (!nPozitive)
        return v[n-1] * v[n-2] * v[n-3];
    else
        return max(v[n-1] * v[n-2] * v[n-3], v[0] * v[1] * v[n-1]);
}

int main() {
    freopen("produs4.in", "r", stdin);
    freopen("produs4.out", "w", stdout);

    int nTeste;
    cin >> nTeste;
    for(int i=0; i<nTeste; i++) {
        cout << solve() << "\n";
    }
    return 0;
}
