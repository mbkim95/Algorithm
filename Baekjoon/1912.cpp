#include <iostream>
#include <algorithm>
using namespace std;

int n, num[100001], dp[100001];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  dp[0] = num[0];
  int ans = dp[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(dp[i - 1] + num[i], num[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}
