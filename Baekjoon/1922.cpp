#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, p[1001];
vector<pair<int, pair<int, int> > > adj;

int find(int u) {
  if(u == p[u]) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v){ 
  int a = find(u);
  int b = find(v);

  if(a != b) {
    if(u > v) swap(u, v);
    p[v] = u;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> m;

  for(int i=0; i<=n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj.push_back(make_pair(c, make_pair(a, b)));
  }

  sort(adj.begin(), adj.end());
  int ans = 0;
  for(auto i : adj) {
    int a = find(i.second.first);
    int b = find(i.second.second);
    if(a != b) {
      ans += i.first;
      merge(a, b);
    }
  }
  cout << ans << '\n';
  return 0;
}