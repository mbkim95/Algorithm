#include <iostream>
#include <algorithm>
using namespace std;

int ans, n, num[100001], dp[100001][2];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];

    ans = dp[0][0] = num[0];
    for(int i=1; i<n; i++) {
        dp[i][0] = max(num[i], dp[i-1][0] + num[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + num[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << '\n';
    return 0;
}