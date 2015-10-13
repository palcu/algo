#include <iostream>
#include <cstdio>

using namespace std;

const int N = 102;
int v[N];

int main() {
    int n; cin >> n;
    int ret = 0;
    for (int i=1; i<=n; i++)
        cin >> v[i];

    for (int i=1; i<=n; i++) {
        if (v[i]) {
            ret++;
        } else {
            if (v[i-1] && v[i+1])
                ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}
