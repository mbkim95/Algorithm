#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int v, e, c[20001];
vector<vector<int> > adj;

bool bfs(int start){
  queue<int> q;
  q.push(start);
  c[start] = 1;

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for(int i : adj[cur]) {
      if(!c[i]){
        q.push(i);
        if(c[cur] == 1) c[i] = 2;
        else c[i] = 1;
      }
      else if(c[cur] == c[i]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> k;
  while (k--) {
    cin >> v >> e;
    adj = vector<vector<int> >(v+1);
    memset(c, 0, sizeof(c));
    for (int i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    bool ans = true;
    for(int i=1; i<=v; i++){
      if(!c[i]) ans &= bfs(i);
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
