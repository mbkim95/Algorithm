#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
int dp[1001][1001];

int main() {
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < a.length(); i++) {
    for (int j = 0; j < b.length(); j++) {
      if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
      else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      ans = max(ans, dp[i+1][j+1]);
    }
  }
  cout << ans << '\n';
  return 0;
}
