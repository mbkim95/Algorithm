#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, x, y, v[101];
vector<vector<int> > adj;

int bfs() {
  queue<int> q;
  q.push(x);
  v[x] = 1;
  int ans = 0;

  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      int cur = q.front();
      q.pop();

      if (cur == y) return ans;

      for (int next : adj[cur]) {
        if (!v[next]) {
          v[next] = 1;
          q.push(next);
        }
      }
    }
    ans++;
  }
  return -1;
}

int main() {
  cin >> n;
  adj = vector<vector<int> >(n + 1);
  cin >> x >> y;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << bfs() << '\n';
  return 0;
}