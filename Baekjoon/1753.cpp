#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, e, k, chk[20001];
vector<pair<int, int> > adj[20001];

void dijkstra() {
  priority_queue<pair<int, int> > pq;
  pq.push(make_pair(0, k));
  chk[k] = 0;

  while (!pq.empty()) {
    int cur = pq.top().second;
    int cost = -pq.top().first;
    pq.pop();

    if(cost > chk[cur]) continue;

    for (auto it : adj[cur]) {
      int next = it.first;
      int w = it.second;
      if (chk[next] > cost + w) {
        chk[next] = cost + w;
        pq.push(make_pair(-chk[next], next));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;
  cin >> k;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
  }

  fill(chk, chk + v + 1, 987654321);
  dijkstra();
  for (int i = 1; i <= v; i++) {
    if (chk[i] == 987654321) cout << "INF\n";
    else cout << chk[i] << '\n';
  }
  return 0;
}