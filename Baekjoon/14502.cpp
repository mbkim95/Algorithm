#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ans, b[8][8], b2[8][8];
vector<pair<int, int> > blank, tmp, virus;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int bfs() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) b2[i][j] = b[i][j];

  for (int i = 0; i < 3; i++) b2[tmp[i].second][tmp[i].first] = 1;

  queue<pair<int, int> > q;
  for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || b2[ny][nx] != 0)
        continue;

      q.push(make_pair(nx, ny));
      b2[ny][nx] = 2;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (b2[i][j] == 0) cnt++;
  return cnt;
}

void dfs(int idx) {
  if (tmp.size() == 3) {
    ans = max(ans, bfs());
    return;
  }

  for (int i = idx + 1; i < blank.size(); i++) {
    tmp.push_back(blank[i]);
    dfs(i);
    tmp.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
      if (b[i][j] == 0)
        blank.push_back(make_pair(j, i));
      else if (b[i][j] == 2)
        virus.push_back(make_pair(j, i));
    }
  }
  dfs(-1);
  cout << ans << '\n';
  return 0;
}