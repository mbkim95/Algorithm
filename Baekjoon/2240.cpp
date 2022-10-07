#include <iostream>
#include <algorithm>
using namespace std;

int pos[1001], dp[1001][31][3];

int main() {
    int t, w;
    cin >> t >> w;

    for(int i=1; i<=t; i++) cin >> pos[i];

    if(pos[1] == 1) dp[1][0][1] = 1;
    else dp[1][1][2] = 1;
    
    for(int i=2; i<=t; i++) {
        for(int j=0; j<=w; j++) {
            if(pos[i] == 1) {
                if(j == 0) dp[i][j][1] = dp[i-1][j][1] + 1;
                else {
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]) + 1;
                    dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]);
                }
            } else {
                if(j == 0) dp[i][j][2] = dp[i-1][j][2];
                else {
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]);
                    dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]) + 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=w; i++) ans = max(ans, max(dp[t][i][1], dp[t][i][2]));
    cout << ans << '\n';
    return 0;
}