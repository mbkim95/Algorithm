#include <iostream>
#include <queue>
using namespace std;

int n, m, b[101][101], v[101][101];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int bfs() {
  queue<pair<int, int> > q;
  q.push(make_pair(1, 1));
  v[1][1] = 1;
  int cnt = 0;

  while (!q.empty()) {
    int size = q.size();
    cnt++;
    while (size--) {
      pair<int, int> cur = q.front();
      q.pop();

      if (cur.first == m && cur.second == n) return cnt;

      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
        if (!v[ny][nx] && b[ny][nx]) {
          q.push(make_pair(nx, ny));
          v[ny][nx] = 1;
        }
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%1d", &b[i][j]);
  cout << bfs() << '\n';
  return 0;
}
