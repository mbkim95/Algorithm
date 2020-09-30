#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int>> adj;

void floyd_warshall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	adj = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	floyd_warshall();

	int count = INF;
	int idx;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			cnt += adj[i][j];
		if (count > cnt) {
			count = cnt;
			idx = i;
		}
	}
	cout << idx << '\n';
	return 0;
}