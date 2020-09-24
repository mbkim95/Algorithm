#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_possible;
int n, m, s, e, answer;
vector<vector<pair<int, int>>> adj;

void bfs(int weight) {	
	queue<int> q;
	vector<bool> visited(n + 1, false);
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == e) {
			is_possible = true;
			answer = answer > weight ? answer : weight;
		}

		for (auto i : adj[current]) {
			int j = i.first;
			int w = i.second;
			if (!visited[j] && w >= weight) {
				q.push(j);
				visited[j] = true;
			}
		}
	}	
}

void binary_search() {
	int left = 1;
	int right = 1e9;

	while (left <= right) {
		int mid = (left + right) / 2;

		is_possible = false;
		bfs(mid);

		if (is_possible) left = mid + 1;
		else right = mid - 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	adj = vector <vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> s >> e;
	binary_search();
	cout << answer << '\n';
	return 0;
}