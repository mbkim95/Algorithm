#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> visited, passed;
vector<vector<int>> adj;

int numOfVertex(int here) {
	int cnt = 1;
	visited[here] = true;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			cnt += numOfVertex(there);
	}
	return cnt;
}

int numOfEdge(int here) {
	int cnt = adj[here].size();
	passed[here] = true;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!passed[there])
			cnt += numOfEdge(there);
	}
	return cnt;
}

int solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int e = numOfEdge(i);
			int v = numOfVertex(i);
			if (v - 1 == e / 2)
				ans++;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c = 0;
	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;
		c++;
		visited = vector<bool>(n + 1, false);
		passed = vector<bool>(n + 1, false);
		adj = vector<vector<int>>(n + 1);
		for (int i = 0; i < m; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			adj[tmp1].push_back(tmp2);
			adj[tmp2].push_back(tmp1);
		}
		int ans = solve();
		solve();
		cout << "Case " << c << ": ";
		if (ans == 0)
			cout << "No trees.\n";
		else if (ans == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << ans << " trees.\n";
	}
	return 0;
}