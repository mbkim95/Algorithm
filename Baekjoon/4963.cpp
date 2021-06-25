#include <iostream>
#include <vector>
using namespace std;

int w, h, ans;
vector<vector<int> > land, chk;
const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1}, dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

void dfs(int x, int y) {
  chk[y][x] = 1;

  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx > w - 1 || ny < 0 || ny > h - 1) continue;
    if (!chk[ny][nx] && land[ny][nx]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    ans = 0;
    land = vector<vector<int> >(h, vector<int>(w, 0));
    chk = vector<vector<int> >(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) cin >> land[i][j];
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!chk[i][j] && land[i][j]) {
          ans++;
          dfs(j, i);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}