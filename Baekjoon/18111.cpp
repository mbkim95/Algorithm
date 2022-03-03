#include <cmath>
#include <iostream>
using namespace std;

int n, m, b, board[501][501];

int calculate(int h) {
    int tmp_b = b;
    int t = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int diff = abs(h - board[i][j]);

            if (board[i][j] < h) {
                tmp_b -= diff;
                t += diff;
            } else if (board[i][j] > h) {
                tmp_b += diff;
                t += (2 * diff);
            }
        }
    }

    if (tmp_b < 0 || tmp_b > 64000000)
        return 987654321;
    return t;
}

void solve() {
    int t = 987654321;
    int h = 257;
    for (int i = 256; i >= 0; i--) {
        int tmp = dfs(i);
        if (t > tmp) {
            t = tmp;
            h = i;
        }
    }
    cout << t << ' ' << h << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];

    solve();
    return 0;
}