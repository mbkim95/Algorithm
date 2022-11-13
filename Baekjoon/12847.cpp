#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s, e;
long long ans, preSum[100001];

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> preSum[i];
        preSum[i] += preSum[i-1];
    }
    s = 0, e = m;
    while(e <= n) ans = max(ans, preSum[e++] - preSum[s++]);
    cout << ans << '\n';
    return 0;
}