#include <iostream>
#include <cstring>
using namespace std;

int m, n, k;
bool board[51][51], visited[51][51];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void dfs(int x, int y){
  visited[y][x] = true;

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx > m-1 || ny < 0 || ny > n-1) continue;
    if(!visited[ny][nx] && board[ny][nx]) dfs(nx, ny);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    int ans = 0;
    memset(board, false, sizeof(visited));
    memset(visited, false, sizeof(visited));
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
      int x, y;
      cin >> x >> y;
      board[y][x] = true;
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++) 
      if(!visited[i][j] && board[i][j]){
        ans++;
        dfs(j, i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
