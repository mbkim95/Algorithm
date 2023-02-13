#include <iostream>
#include <algorithm>
using namespace std;

int n, xi[100];

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> xi[i];

        sort(xi, xi + n);
        int ans = 0, cur = xi[0];
        for(int i=0; i<n; i++) {
            ans += abs(xi[i] - cur);
            cur = xi[i];
        }
        ans += abs(cur - xi[0]);
        cout << ans << '\n';
    }
    return 0;
}