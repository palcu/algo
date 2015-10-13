#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

vector<int> rows[2], rev_rows[2], passes;

void acumm(vector<int>& v) {
    for (int i=1; i<v.size(); i++) {
        v[i] += v[i-1];
    }
}

int main() {
    // freopen("b.in", "r", stdin);
    int n; cin >> n;
    for (int r=0; r<=1; r++) {
        for (int i=0; i<n-1; i++) {
            int x; cin >> x;
            rows[r].push_back(x);
        }
    }

    for (int i=0; i<n; i++) {
        int x; cin >> x;
        passes.push_back(x);
    }

    for (int i=0; i<=1; i++) {
        rev_rows[i].resize(n-1);
        reverse_copy(rows[i].begin(), rows[i].end(), rev_rows[i].begin());
        acumm(rows[i]);
        acumm(rev_rows[i]);
    }
    
    // do magic
    reverse(rev_rows[1].begin(), rev_rows[1].end());
    rev_rows[1].push_back(0);
    rows[0].insert(rows[0].begin(), 0);

    int ret = numeric_limits<int>::max();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j) {
                int first_walk = rev_rows[1][i] + passes[i] + rows[0][i];
                int second_walk = rev_rows[1][j] + passes[j] + rows[0][j];
                ret = min(ret, first_walk + second_walk);
                // cout << first_walk << " " << i << endl;
            }
        }
    }

    cout << ret;
    
    return 0;
}
