#include <iostream>
#include <algorithm>
using namespace std;

int n, h[1001][3], dp[1001][3];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i][0] >> h[i][1] >> h[i][2];
  dp[0][0] = h[0][0];
  dp[0][1] = h[0][1];
  dp[0][2] = h[0][2];

  for(int i=1; i<n; i++){
      dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + h[i][0];
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + h[i][1];
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + h[i][2];
  }
  int ans = min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
  cout << ans << '\n';
  return 0;
}
