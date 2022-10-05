#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[1001], p[10001];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];

    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = 987654321;
        for(int j=1; j<=i; j++) dp[i] = min(dp[i], p[j] + dp[i-j]);
    }
    cout << dp[n] << '\n';
    return 0;
}