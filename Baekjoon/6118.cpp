#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[20001];
int visited[20001];

void bfs() {
	visited[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			if (visited[next] == -1) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(visited, visited + 1 + n, -1);
	bfs();

	int ans_idx, ans_dist = 0, ans_cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (ans_dist < visited[i]) {
			ans_cnt = 1;
			ans_idx = i;
			ans_dist = visited[i];
		}
		else if (ans_dist == visited[i]) ans_cnt++;
	}
	cout << ans_idx << ' ' << ans_dist << ' ' << ans_cnt << '\n';
	return 0;
}