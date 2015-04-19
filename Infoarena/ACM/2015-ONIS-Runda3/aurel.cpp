#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MODULO = 666013;
int min_partition;

int sum(int k, int n)
{
    if(k == 1 || n == 1)
        return 1;
    if(k < n)
        return sum(k, k);
    else if (k == n)
        return (1 + sum (k, k-1)) % 666013;
    else
        return (sum (k,n-1) + sum (k-n, n)) % 666013;
}

int solve() {
  int n, s;
  cin >> n >> s;
  min_partition = n;
  int gauss = n  * (n+1) / 2;
  int ramas = s - gauss;
  return sum(ramas, ramas);
}

int main() {
    freopen("aurel.in", "r", stdin);
    freopen("aurel.out", "w", stdout);

    int nTeste;
    cin >> nTeste;
    for(int i=0; i<nTeste; i++) {
        cout << solve() << "\n";
    }
    return 0;
}
