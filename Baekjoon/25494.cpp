#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) for (int k = 1; k <= c; k++) if (i % j == j % k && j % k == k % i) ans++;
        cout << ans << '\n';
    }
    return 0;
}