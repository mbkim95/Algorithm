#include <iostream>
using namespace std;

int n, h[1001][3], dp[1001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<3; j++)
            cin >> h[i][j];

    int ans = 987654321;
    for (int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i == j) dp[0][i] = h[0][i];
            else dp[0][j] = 987654321;
        }
        for (int j=1; j<n; j++) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + h[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + h[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + h[j][2];
        }
        for(int j=0; j<3; j++) 
            if(i != j) ans = min(ans, dp[n-1][j]);
    }
    cout << ans << '\n';
    return 0;
}