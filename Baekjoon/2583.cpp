#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, k, t;
int b[101][101], chk[101][101];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vector<int> ans;

void dfs(int x, int y) {
  t++;
  chk[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
    if (!b[ny][nx] && !chk[ny][nx]) dfs(nx, ny);
  }
}

int main() {
  cin >> m >> n >> k;
  for (int i = 0; i < k; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    for (int i = ly; i < ry; i++)
      for (int j = lx; j < rx; j++) b[i][j] = 1;
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (!b[i][j] && !chk[i][j]) {
        dfs(j, i);
        ans.push_back(t);
        t = 0;
      }
    }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
  return 0;
}