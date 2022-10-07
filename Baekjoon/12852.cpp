#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[1000001], p[1000001];

int main() {
    cin >> n;

    for(int i=0; i<=1000000; i++) dp[i] = 987654321;
    dp[1] = 0;
    p[1] = -1;
    for(int i=2; i<=n; i++) {
        dp[i] = min(dp[i], dp[i-1] + 1);
        p[i] = i-1;
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            p[i] = i/2;
        }
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            p[i] = i/3;
        }
    }
    cout << dp[n] << '\n';

    while(n != -1) {
        cout << n << ' ';
        n = p[n];
    }
    cout << '\n';
    return 0;
}