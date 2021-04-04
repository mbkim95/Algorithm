#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, total, b[1001][1001], v[1001][1001];
vector<pair<int, int> > t;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int bfs() {
  queue<pair<int, int> > q;
  for (auto i : t) {
    q.push(make_pair(i.first, i.second));
    v[i.second][i.first] = 1;
  }

  int day = 0, cnt = 0;
  while (!q.empty()) {
    int size = q.size();
    if (total == cnt) return day;
    day++;
    while (size--) {
      pair<int, int> cur = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
        if (!v[ny][nx] && b[ny][nx] == 0) {
          cnt++;
          q.push(make_pair(nx, ny));
          v[ny][nx] = 1;
        }
      }
    }
  }
  return -1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      if (b[i][j] == 1)
        t.push_back(make_pair(j, i));
      else if (b[i][j] == 0)
        total++;
    }
  cout << bfs() << '\n';
  return 0;
}
