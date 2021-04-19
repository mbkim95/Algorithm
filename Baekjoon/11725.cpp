#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> parent, adj[100001];

void dfs(int cur) {
  for (int next : adj[cur]) {
	  if(parent[next] == 0) {
      parent[next] = cur;
      dfs(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  parent = vector<int>(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  for(int i=2; i<=n; i++) cout << parent[i] << '\n';
  return 0;
}