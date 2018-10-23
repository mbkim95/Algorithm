#include <iostream>
#include <cstring>
using namespace std;

int m, n, ans, v[50][50], chk[50][50];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < m && ny >= 0 && ny < n && v[ny][nx] != 0 && chk[ny][nx] == 0){
			chk[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] == 1 && chk[i][j] == 0) {
				ans++;
				dfs(i, j);
			}
}

int main() {
	int t, c;
	cin >> t;
	while (t--) {
		cin >> m >> n >> c;
		ans = 0;
		memset(v, 0, sizeof(v));
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < c; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			v[tmp2][tmp1] = 1;
		}
		solve();
		cout << ans << endl;
	}
}