#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<bool> visited;
vector<int> order, inDegree;
vector<vector<int>> adj;


bool isDAG() {
	int size = order.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int a = order[i];
			int b = order[j];
			for(int k=0; k<adj[b].size(); k++){
				int tmp = adj[b][k];
				if (tmp == a) {
					return false;
				}
			}
		}
	}
	return true;
}

void dfs(int here) {
	visited[here] = true;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
	order.push_back(here);
}

void topologicalSort() {
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i] && !visited[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());

	if (isDAG())
		for (int i = 0; i < order.size(); i++) {
			cout << order[i] << '\n';
		}
	else
		cout << 0 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	visited = vector<bool>(n + 1, false);
	inDegree = vector<int>(n + 1, 0);
	adj = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		vector<int> v = vector<int>(tmp);
		for (int j = 0; j < tmp; j++) {
			cin >> v[j];
		}
		for (int j = 0; j < tmp-1; j++) {
			adj[v[j]].push_back(v[j + 1]);
			inDegree[v[j + 1]]++;
		}
	}
	topologicalSort();
	return 0;
}