#include <iostream>
#include <algorithm>
using namespace std;

int t, k, f[501], sum[501], dp[501][501];

int main() {
    cin >> t;
    while(t--) {
        cin >> k;
        for(int i=1; i<=k; i++) {
            cin >> f[i];
            sum[i] = sum[i-1] + f[i];
        }

        for(int g=1; g<k; g++) {
            for(int s=1; s+g<=k; s++) {
                int e = s+g;

                dp[s][e] = 987654321;

                for(int m=s; m<e; m++)
                    dp[s][e] = min(dp[s][e], dp[s][m] + dp[m+1][e] + sum[e] - sum[s-1]);
            }
        }
        cout << dp[1][k] << '\n';
    }
    return 0;
}