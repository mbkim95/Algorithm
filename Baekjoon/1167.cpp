#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, ans;
vector<vector<pair<int, int>>> tree;
vector<int> dist;
vector<bool> visited;
queue<int> q;

void bfs(int start) {
	q.push(start);
	visited[start] = true;
	dist[start] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < tree[here].size(); i++) {
			int next = tree[here][i].first;
			int len = tree[here][i].second;
			if (!visited[next]) {
				q.push(next);
				dist[next] = dist[here] + len;
				visited[next] = true;
			}
		}
	}
}

void solve() {
	bfs(1);
	int start = 1;
	for (int i = 2; i <= v; i++) {
		if (dist[start] < dist[i])
			start = i;
	}
	fill(visited.begin(), visited.end(), false);
	fill(dist.begin(), dist.end(), 0);
	bfs(start);
	for (int i = 1; i <= v; i++) {
		if (dist[start] < dist[i])
			start = i;
	}
	cout << dist[start] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v;
	tree = vector<vector<pair<int, int>>>(v + 1);
	visited = vector<bool>(v + 1, false);
	dist = vector<int>(v + 1, 0);
	for (int i = 0; i < v; i++) {
		int tmp, a, b;
		cin >> tmp;
		while (true) {
			cin >> a;
			if (a == -1) break;
			cin >> b;
			tree[tmp].push_back(make_pair(a, b));
		}
	}
	solve();
	return 0;
}