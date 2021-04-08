#include <iostream>
#include <queue>
using namespace std;

struct tomato {
  int x, y, z;
};

int n, m, h, mt, map[101][101][101], v[101][101][101];
const int dx[] = {-1, 0, 1, 0, 0, 0}, dy[] = {0, -1, 0, 1, 0, 0}, dz[] = {0, 0, 0, 0, -1, 1};
queue<tomato> q;

int bfs() {
  int day = 0, cnt = 0;
  if(cnt == mt)  return 0;
  while (!q.empty()) {
    int size = q.size();   
    if(cnt == mt)  return day;
    while (size--) {
      tomato cur = q.front();
      q.pop();

      for (int i = 0; i < 6; i++) {
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        int nz = cur.z + dz[i];

        if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || nz < 0 || nz > h - 1) continue;
        if (!v[nz][ny][nx] && !map[nz][ny][nx]) {
          tomato t = {nx, ny, nz};
          q.push(t);
          cnt++;
          v[nz][ny][nx] = 1;
        }
      }
    }
    day++; 
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n >> h;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++) {
        cin >> map[i][j][k];
        if (map[i][j][k] == 1) {
          v[i][j][k] = 1;
          tomato t = {k, j, i};
          q.push(t);        
        }
        if(map[i][j][k] == 0) mt++;
      }
  cout << bfs() << '\n';
  return 0;
}
