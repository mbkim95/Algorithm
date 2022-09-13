#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r;

void bfs(int cur, const vector<vector<int>> &adj, vector<int> &visited) {
    int cnt = 1;
    visited[r] = cnt++;
    queue<int> q;
    q.push(r);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next: adj[cur]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), greater<int>());
    bfs(r, adj, visited);
    for(int i=1; i<=n; i++) cout << visited[i] << '\n';
    return 0;
}