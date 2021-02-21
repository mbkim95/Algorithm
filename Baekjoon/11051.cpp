#include <iostream>
using namespace std;

int n, k, dp[1001][1001];

int comb(int n, int k){
  if(k == 0 || n == k) return 1;
  if(dp[n][k] != 0) return dp[n][k];
  return dp[n][k] = (comb(n-1, k-1) + comb(n-1, k)) % 10007;
}

int main() {
  cin >> n >> k;
  cout << comb(n, k) << '\n';
  return 0;
}
