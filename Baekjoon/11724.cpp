#include <iostream>
using namespace std;

int n, m, ans;
bool adj[1001][1001], v[1001];

void dfs(int cur) {
  v[cur] = true;

  for(int i=1; i<=n; i++) {
    if(i == cur) continue;
    if(!v[i] && adj[cur][i]) {
      dfs(i);
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u][v] = adj[v][u] = true;
  }

  for(int i=1; i<=n; i++) {
    if(!v[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans << '\n';
  return 0;
}