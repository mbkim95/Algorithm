#include <iostream>
#define MOD 9901
using namespace std;

int n, dp[100001][3];

int main() {
  cin >> n;
  dp[0][2] = 1;
  for(int i=1; i<=n; i++) {
    dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
    dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
    dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
  }
  cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << '\n';
  return 0;
}