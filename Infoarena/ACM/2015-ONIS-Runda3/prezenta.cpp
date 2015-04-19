#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 128;
const int MODULO = 10007;

int dp[N][N];

int count(int n, int k)
{
  if(n == 0)
    return 0;
  if(k == 0)
    return 1;
  if(dp[n][k] != -1)
    return dp[n][k];
  int val = 0;
  for(int i = 0; i < n && k-i >= 0; i++)
    val += count(n-1, k-i) % MODULO;
  return (dp[n][k] = val);
}

int solve() {
  int n, k;
  cin >> n >> k;
  return count(n, k);
}

int main() {
    freopen("prezenta.in", "r", stdin);
    freopen("prezenta.out", "w", stdout);

    int nTeste;
    cin >> nTeste;
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
          dp[i][j] = -1;
    for(int i=0; i<nTeste; i++) {
        cout << solve() << "\n";
    }
    return 0;
}
