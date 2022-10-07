#include <iostream>
using namespace std;

int dp[1000001];
const int MOD = 1000000009;

int main() {
    int t;
    cin >> t;
    dp[0] = 1;

    for(int i=1; i<=1000000; i++) {
        for(int j=1; j<=3; j++) {
            if(i - j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }

    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}