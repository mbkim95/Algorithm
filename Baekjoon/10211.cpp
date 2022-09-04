#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, num[1001], preSum[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> num[i];
        for (int i = 1; i <= n; i++) preSum[i] = preSum[i - 1] + num[i];
        
        int ans = -987654321;

        for(int i=1; i<=n; i++) for(int j=i; j<=n;  j++) ans = max(ans, preSum[j] - preSum[i - 1]);
        cout << ans << '\n';
    }

    return 0;
}