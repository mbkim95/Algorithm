#include <iostream>
#include <algorithm>
using namespace std;

int n, num[1001], dp[1001], dp2[1001];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  dp[0] = 1;
  dp2[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (num[i] > num[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    dp2[i] = 1;
    for (int j = n - 1; j > i; j--)
      if (num[i] > num[j] && dp2[i] < dp2[j] + 1) dp2[i] = dp2[j] + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i] + dp2[i] - 1);
  cout << ans << '\n';
  return 0;
}
