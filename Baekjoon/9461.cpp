#include <iostream>
using namespace std;

long long dp[101];

int main(){
  int t;
  cin >> t;

  dp[1] = dp[2] = dp[3] = 1;
  for(int i=4; i<=100; i++) dp[i] = dp[i-2] + dp[i-3];
  while(t--){
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}
