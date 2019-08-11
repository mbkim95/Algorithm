#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<bool> members;
vector<vector<int>> team;

void dfs(int cnt, int idx) {
	if (cnt == n / 2) {
		int a = 0, b = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (members[i] && members[j])
					a += (team[i][j] + team[j][i]);
				else if (!members[i] && !members[j])
					b += (team[i][j] + team[j][i]);
			}
		}
		ans = min(ans, abs(a - b));
		return;
	}
	
	if (idx == n)
		return;

	for (int i = idx + 1; i < n; i++) {
		members[i] = true;
		dfs(cnt + 1, i);
		members[i] = false;
	}
}

void solve() {
	ans = 987654321;
	for (int i = 0; i < n; i++) {
		members[i] = true;
		dfs(1, i);
		members[i] = false;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	team = vector<vector<int>>(n, vector<int>(n));
	members = vector<bool>(n, false);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> team[i][j];
	solve();
	return 0;
}