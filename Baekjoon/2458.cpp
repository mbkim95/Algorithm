#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<bool>> adj;

void floyd_warshall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][k] && adj[k][j])
					adj[i][j] = true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	adj = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = true;
	}

	floyd_warshall();

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++)
			if (adj[i][j] || adj[j][i]) count++;
		if (count == n - 1) answer++;
	}
	cout << answer << '\n';
	return 0;
}