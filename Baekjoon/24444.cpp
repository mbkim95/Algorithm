#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r, num;
vector<int> adj[100001];
int visited[100001];

void bfs() {
    queue<int> q;
    q.push(r);

    visited[r] = ++num;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next: adj[cur]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = ++num;
            }
        }
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());
    bfs();
    for(int i=1; i<=n; i++) cout << visited[i] << '\n';
    return 0;
}