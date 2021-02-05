#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
  int n;
  cin >> n;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = dp[i + 1] + 1;
    if (i * 2 <= n) dp[i] = min(dp[i], dp[i * 2] + 1);
    if (i * 3 <= n) dp[i] = min(dp[i], dp[i * 3] + 1);
  }
  cout << dp[1] << '\n';
  return 0;
}
