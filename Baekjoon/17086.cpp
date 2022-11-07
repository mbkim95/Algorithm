#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, b[50][50];
vector<pair<int, int>> pos;
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    q.push({x, y});
    visited[y][x] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx]) continue;

            if(b[ny][nx]) return visited[cur.second][cur.first];

            visited[ny][nx] = visited[cur.second][cur.first] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        cin >> b[i][j];
        if(!b[i][j]) pos.push_back({j, i});
    }

    int ans = 0;
    for(auto p : pos) ans = max(ans, bfs(p.first, p.second));
    cout << ans << '\n';
    return 0;
}