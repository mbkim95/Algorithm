#include <iostream>
#include <algorithm>
using namespace std;

int n, s[301], dp[301];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];

  dp[1] = s[1];
  dp[2] = dp[1] + s[2];
  for (int i = 3; i <= n; i++)
    dp[i] = max(dp[i - 3] + s[i - 1], dp[i - 2]) + +s[i];

  cout << dp[n] << '\n';
  return 0;
}
