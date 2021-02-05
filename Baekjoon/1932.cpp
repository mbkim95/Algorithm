#include <iostream>
#include <algorithm>
using namespace std;

int n, t[501][501], dp[501][501];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) cin >> t[i][j];

  dp[1][1] = t[1][1];
  for (int i = 2; i <= n; i++) {
    dp[i][1] = dp[i - 1][1] + t[i][1];
    for (int j = 2; j <= i - 1; j++)
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + t[i][j];
    dp[i][i] = dp[i - 1][i - 1] + t[i][i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) cout << dp[i][j] << ' ';
    cout << '\n';
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
  cout << ans << '\n';
  return 0;
}
