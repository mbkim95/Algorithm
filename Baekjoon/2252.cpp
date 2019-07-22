#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int n, m;

void dfs(vector<list<int>>& adj, vector<int>& visited, vector<int>& order, int idx) {
	visited[idx] = 1;

	for (auto it = adj[idx].begin(); it != adj[idx].end(); it++) {
		int i = *it;
		if (!visited[i]) {
			dfs(adj, visited, order, i);
		}
	}
	order.push_back(idx);
}

void topologicalSort(vector<list<int>>& adj) {
	vector<int> visited = vector<int>(n + 1, 0);
	vector<int> order;
	order.clear();
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs(adj, visited, order, i);

	reverse(order.begin(), order.end());

	for (int i = 0; i < n; i++) {
		cout << order[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<list<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
	}
	topologicalSort(adj);
	return 0;
}