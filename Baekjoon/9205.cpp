#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool canArrive;
vector<vector<int>> adj;
vector<bool> visited;

int getDistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int idx) {
	if (idx == n + 1) {
		canArrive = true;
		return;
	}
	visited[idx] = true;

	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!visited[next])
			dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	
	while (t--) {
		cin >> n;
		canArrive = false;
		adj = vector<vector<int>>(n + 2);
		visited = vector<bool>(n + 2, false);
		vector<pair<int, int>> point(n + 2);
		for (int i = 0; i < n + 2; i++) 
			cin >> point[i].first >> point[i].second;
		
		for (int i = 0; i < n + 1; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (getDistance(point[i].first, point[i].second, point[j].first, point[j].second) <= 1000) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		dfs(0);

		if (canArrive)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}