#include <iostream>
#include <climits>
using namespace std;

int n, dp[501][501], mat[501][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> mat[i][0] >> mat[i][1];

    for(int i=1; i<n; i++) {
        for(int s=1; s+i<=n; s++) {
            int e = s+i;

            dp[s][e] = INT_MAX;
            for(int m=s; m<e; m++) 
                dp[s][e] = min(dp[s][e], dp[s][m] + dp[m+1][e] + mat[s][0] * mat[m][1] * mat[e][1]);
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}