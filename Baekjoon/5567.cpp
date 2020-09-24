#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> adj;

int bfs() {
	queue<int> q;
	vector<bool> visit(n + 1, false);
	q.push(1);
	visit[1] = true;

	int answer = 0;
	int count = 0;

	while (!q.empty()) {
		int size = q.size();

		if (count == 2) break;

		while (size--) {
			int current = q.front();
			q.pop();

			for (int i : adj[current]) {				
				if (!visit[i]) {
					visit[i] = true;
					q.push(i);
					answer++;
				}
			}
		}
		count++;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	adj = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	cout << bfs() << '\n';
	return 0;
}