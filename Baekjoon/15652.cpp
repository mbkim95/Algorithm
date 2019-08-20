#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;

void dfs(int idx, int select) {
	if (select == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i <= n; i++) {
		ans.push_back(i);
		dfs(i, select + 1);
		ans.pop_back();
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		ans.push_back(i);
		dfs(i, 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	solve();
	return 0;
}