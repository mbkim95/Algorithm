#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for(int i=1; i<=50000; i++) dp[i] = 5;
    for(int i=1; i*i <=50000; i++) dp[i*i] = 1;

    for(int i=2; i<=n; i++) {
        for(int j=1; j*j<=i; j++) 
            dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
    cout << dp[n] << '\n';
    return 0;
}