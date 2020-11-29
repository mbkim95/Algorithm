#include <iostream>
using namespace std;

int dp[80001];

void precalc() {
  int sum = 0;
  for(int i=3; i<=80000; i++) {
    if(i % 3 == 0 || i % 7 == 0)
      sum += i;
    dp[i] = sum;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  precalc();

  while(t--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}
