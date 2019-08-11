#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int>ans;

void dfs(int cnt, int num) {
	if (cnt == m) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num + 1; i <= n; i++) {
		ans.push_back(i);
		dfs(cnt + 1, i);
		ans.pop_back();
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		ans.push_back(i);
		dfs(1, i);
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