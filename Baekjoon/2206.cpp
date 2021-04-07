#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct point{
  int x, y, cnt;
};

int n, m, map[1001][1001], v[1001][1001][2];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int bfs(){
  queue<point> q;
  point p = {1, 1, 0};
  q.push(p);
  v[1][1][0] = 1;

  while(!q.empty()){
    point cur = q.front();
    q.pop();

    if(cur.x == m && cur.y == n) return max(v[cur.y][cur.x][0], v[cur.y][cur.x][1]);

    for(int i=0; i<4; i++){
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      int cnt = cur.cnt;

      if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
      if(!v[ny][nx][cnt] && !map[ny][nx]){
        v[ny][nx][cnt] = v[cur.y][cur.x][cnt] + 1;
        point p = {nx, ny, cnt};
        q.push(p);
      }
      if(cnt == 0 && !v[ny][nx][1] && map[ny][nx]){
        v[ny][nx][1] = v[cur.y][cur.x][0] + 1;
        point p = {nx, ny, 1};
        q.push(p);
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%1d", &map[i][j]);
  printf("%d\n", bfs());
  return 0;  
}
