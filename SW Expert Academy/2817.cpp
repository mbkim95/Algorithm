#include <iostream>
#include <vector>
using namespace std;

int ans, n, k;
vector<int> v;

void dfs(int idx, int cnt, int sum) {
    if (sum > k) return;
    if (sum == k) {
        ans++;
        return;
    }

    for (int i = idx + 1; i < n; i++)
        dfs(i, cnt + 1, sum + v[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        ans = 0;
        cin >> n >> k;
        v = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        dfs(-1, 0, 0);
        cout << '#' << c << ' ' << ans << '\n';
    }
}