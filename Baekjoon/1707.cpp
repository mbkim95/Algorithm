#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<int> adj[20001];
int visited[20001];
bool visited2[20001];
bool is_possible = true;

void dfs(int idx, int chk) {
	visited[idx] = chk;

	for (int next : adj[idx]) {
		if (visited[next] == 0) {
			if (chk == 1) dfs(next, 2);
			else dfs(next, 1);
		}
	}
}

void bfs(int start) {
	queue<pair<int, int>> q;	
	q.push({ start, visited[start] });
	
	visited2[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int chk = q.front().second;
		q.pop();

		for (int next : adj[cur]) {
			int next_chk = visited[next];
			if (chk == next_chk) {
				is_possible = false;
				return;
			}
			if (!visited2[next]) {
				visited2[next] = true;
				q.push({ next, next_chk });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	while (k--) {
		cin >> v >> e;
		is_possible = true;
		for (int i = 0; i < 20001; i++) adj[i].clear();
		fill(visited, visited + 20001, 0);
		fill(visited2, visited2 + 20001, false);
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if (!visited[i])
				dfs(i, 1);
		}
		for (int i = 1; i <= v; i++) {
			if (is_possible && !visited2[i])
				bfs(i);
		}
		if (is_possible) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}