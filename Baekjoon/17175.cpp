#include <iostream>
using namespace std;

int dp[51];
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + 1;
        dp[i] %= MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}