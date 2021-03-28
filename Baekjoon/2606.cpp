#include <iostream>
using namespace std;

int n, m, ans;
bool adj[101][101], visited[101];

void dfs(int cur){
  visited[cur] = true;

  for(int i=1; i<=100; i++){
    if(!visited[i] && adj[cur][i]){
      ans++;
      dfs(i);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a][b] = adj[b][a] = true;
  }
  dfs(1);
  cout << ans << '\n';
  return 0;
}
