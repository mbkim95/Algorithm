#include <iostream>
#define MAX 2e9
using namespace std;

int v, e;
int adj[401][401];

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			adj[i][j] = MAX;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (adj[i][k] != MAX && adj[k][j] != MAX && adj[i][k] + adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	int ans = MAX;
	for (int i = 1; i <= v; i++)
		if (ans > adj[i][i])
			ans = adj[i][i];
	if (ans == MAX) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}