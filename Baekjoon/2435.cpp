#include <iostream>
#include <algorithm>
using namespace std;

int n, k, num[101], preSum[101];

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> num[i];
        preSum[i] = preSum[i-1] + num[i];
    }

    int ans = preSum[k] - preSum[0];
    for(int i=k+1; i<=n; i++) {
        ans = max(ans, preSum[i] - preSum[i-k]);
    }
    cout << ans << '\n';
    return 0;
}