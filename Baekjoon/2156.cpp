#include <iostream>
#include <algorithm>
using namespace std;

int n, g[10001], dp[10001];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> g[i];

  dp[1] = g[1];
  dp[2] = g[1] + g[2];
  for (int i = 3; i <= n; i++)
    dp[i] = max(dp[i - 1], max(dp[i - 3] + g[i - 1] + g[i], dp[i - 2] + g[i]));
  cout << dp[n] << '\n';
  return 0;
}
