#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l, m[301][301];
pair<int, int> k, e;
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(){
  queue<pair<int, int> > q;
  q.push(make_pair(k.first, k.second));
  m[k.second][k.first] = 1;

  while(!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();

    if(cur.first == e.first && cur.second == e.second) return m[e.second][e.first] - 1;

    for(int i=0; i<8; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || nx > l-1 || ny < 0 || ny > l-1) continue;
      if(!m[ny][nx]){
        q.push(make_pair(nx, ny));
        m[ny][nx] = m[cur.second][cur.first] + 1;
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    cin >> l;
    cin >> k.first >> k.second;
    cin >> e.first >> e.second;

    memset(m, 0, sizeof(m));
    cout << bfs() << '\n';
  }
  return 0;
}
