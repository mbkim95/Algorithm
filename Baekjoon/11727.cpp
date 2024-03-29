#include <iostream>
using namespace std;

int n, dp[1001];

int main(){ 
  cin >> n;
  dp[0] = dp[1] = 1;
  for(int i=2; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
  cout << dp[n] << '\n';
  return 0;
}