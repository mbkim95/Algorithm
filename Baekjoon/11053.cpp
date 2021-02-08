#include <iostream>
using namespace std;

int n, num[1001], dp[1001];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  int ans = 1;
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (num[i] > num[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}
