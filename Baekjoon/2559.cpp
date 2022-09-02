#include <iostream>
#include <vector>
using namespace std;

int num[100001], preSum[100001], ans = -987654321;

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> num[i];

    preSum[1] = num[1];
    for(int i=2; i<=n; i++) preSum[i] = num[i] + preSum[i-1];

    for(int i=k; i<=n; i++) {
        int tmp = preSum[i] - preSum[i-k];
        if(ans < tmp) ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}