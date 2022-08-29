#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r, num;
vector<int> adj[100001];
int visited[100001];

void dfs(int idx) {
    visited[idx] = ++num;

    for(int next: adj[idx]) {
        if(!visited[next]) dfs(next);
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
    dfs(r);
    for(int i=1; i<=n; i++) cout << visited[i] << '\n';
    return 0;
}