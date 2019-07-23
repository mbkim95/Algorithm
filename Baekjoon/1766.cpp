#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> inDegree;
priority_queue<int> pq;

void solve() {
	for (int i = 1; i <= n; i++)
		if (!inDegree[i])
			pq.push(-i);

	while (pq.size()) {
		int here = -pq.top();
		pq.pop();
		cout << here << ' ';
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			inDegree[there]--;
			if (!inDegree[there])
				pq.push(-there);
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	inDegree = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
		inDegree[tmp2]++;
	}
	solve();
	return 0;
}