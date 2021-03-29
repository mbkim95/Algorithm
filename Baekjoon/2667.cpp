#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, board[26][26], cnt;
bool visited[26][26];
vector<int> ans;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void dfs(int x, int y) {
  visited[y][x] = true;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;

    if (!visited[ny][nx] && board[ny][nx]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%1d", &board[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!visited[i][j] && board[i][j]) {
        dfs(j, i);
        ans.push_back(cnt);
        cnt = 0;
      }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i : ans) printf("%d\n", i);
  return 0;
}
