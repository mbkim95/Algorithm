#include <iostream>
using namespace std;

int n, k, dp[31][31];

int comb(int n, int k) {
  if (k == 0 || n == k) return 1;
  if (dp[n][k] != 0) return dp[n][k];
  return dp[n][k] = (comb(n - 1, k - 1) + comb(n - 1, k));
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> k >> n;
    cout << comb(n, k) << '\n';
  }
  return 0;
}
