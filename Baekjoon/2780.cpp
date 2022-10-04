#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][10];
const int m[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, -1, -1}};
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
const int MOD = 1234567;
const pair<int, int> pos[] = {{0, 3}, {0, 0}, {1, 0}, {2, 0}, {0, 1},
                              {1, 1}, {2, 1}, {0, 2}, {1, 2}, {2, 2}};

int solve(int n, int num) {
    int& ret = dp[n][num];

    if(n == 1) return ret = 1;

    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<4; i++) {
        int nx = pos[num].first + dx[i];
        int ny = pos[num].second + dy[i];

        if(nx < 0 || nx > 2 || ny < 0 || ny > 3 || m[ny][nx] == -1) continue;
        ret += solve(n-1, m[ny][nx]) %  MOD;
        ret %= MOD;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;

    memset(dp, -1, sizeof(dp));

    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for(int i=0; i<10; i++) {
            ans += solve(n, i);        
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}