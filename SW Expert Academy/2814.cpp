#include <iostream>
#include <cstring>
using namespace std;

int n, m, ans;
bool adj[11][11];
bool visited[11];

void dfs(int idx, int cnt) {
	ans = ans > cnt ? ans : cnt;
	visited[idx] = true;

	for (int i = 1; i <= n; i++) {
		if (!visited[i] && adj[idx][i])
			dfs(i, cnt + 1);
	}
	visited[idx] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int c = 1; c <= t; c++) {
		ans = 1;
		cin >> n >> m;
		memset(adj, false, sizeof(adj));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < m; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			adj[tmp1][tmp2] = true;
			adj[tmp2][tmp1] = true;
		}
		for (int i = 1; i <= n; i++) {
			dfs(i, 1);
		}
		cout << "#" << c << ' ' << ans << '\n';
	}
}