#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int adj[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) adj[i][j] = INT_MAX;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (adj[i][j] == INT_MAX ? 0 : adj[i][j]) << ' ';
		cout << '\n';
	}
}