#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, p1, p2;
vector<int> visited;
vector<vector<int>> adj;

int bfs() {
	queue<int> q;
	q.push(p1);
	visited[p1] = 1;
	int depth = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int tmp = q.front();
			q.pop();

			if (tmp == p2)
				return depth;

			for (int j = 0; j < adj[tmp].size(); j++) {
				int next = adj[tmp][j];
				if (!visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
		depth++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> p1 >> p2;
	cin >> m;
	adj = vector<vector<int>>(n + 1, vector<int>());
	visited = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}	
	cout << bfs() << '\n';
	return 0;
}