#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_TIME = 987654321;
const int MAX = 100000;
int n, k;
vector<int> visited;

pair<int, int> bfs() {
    int ans = 0;
    int min_time = MAX_TIME;
    visited = vector<int>(MAX + 1, MAX_TIME);
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 0;

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        int cur = c.first;
        int time = c.second;

        if (min_time < time) continue;

        if (cur == k) {
            if (min_time == time) ans++;
            else if (min_time > time) {
                min_time = time;
                ans = 1;
            }
        }

        if (cur + 1 <= MAX && time + 1 <= visited[cur + 1]) {
            q.push({cur + 1, time + 1});
            visited[cur + 1] = time + 1;
        }
        if (cur - 1 >= 0 && time + 1 <= visited[cur - 1]) {
            q.push({cur - 1, time + 1});
            visited[cur - 1] = time + 1;
        }
        if (cur * 2 <= MAX && time + 1 <= visited[2 * cur]) {
            q.push({2 * cur, time + 1});
            visited[2 * cur] = time + 1;
        }
    }
    return {min_time, ans};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    auto ans = bfs();
    cout << ans.first << '\n' << ans.second << '\n';
    return 0;
}