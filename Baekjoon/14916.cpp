#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 987654321;
    cin >> n;
    
    for (int i = 0; 2 * i <= n; i++)
        for (int j = 0; 2 * i + 5 * j <= n; j++)
            if (2 * i + 5 * j == n) ans = ans > i + j ? i + j : ans;
    if(ans == 987654321) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}