#include <iostream>
using namespace std;

int n, m, h, ans = 4;
int line[31][11];

bool checkLine() {
	for (int j = 1; j <= n; j++) {
		int x = j;
		for (int i = 0; i <= h; i++) {
			if (line[i][x]) x++;
			else if (line[i][x - 1]) x--;
		}
		if (x != j) return false;
	}
	return true;
}

void dfs(int x, int y, int cnt) {
	if (ans <= cnt) return;
	if (checkLine()) {
		ans = cnt;
		return;
	}
	if (cnt == 3) return;
	for (int i = y; i <= h; i++) {
		for (int j = x; j <= n; j++) {
			if (!line[i][j] && !line[i][j + 1] && !line[i][j - 1]) {
				line[i][j] = 1;
				dfs(j, i, cnt + 1);
				line[i][j] = 0;
			}
		}
		x = 1;
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		line[a][b] = 1;
	}
	dfs(1, 1, 0);
	if (ans == 4) ans = -1;
	cout << ans << '\n';
	return 0;
}