#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int chk[10001];
vector<int> r[10001];
vector<int> ans;

int dfs(int idx) {
	int ret = 1;
	chk[idx] = 1;
	for (int i = 0; i < r[idx].size(); i++) {
		int next = r[idx][i];
		if (!chk[next]) {
			ret += dfs(next);
		}
	}
	return ret;
}

void solve() {
	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		int  value = dfs(i);
		if (max_value < value) {
			max_value = value;
			ans.clear();
			ans.push_back(i);
		}
		else if (max_value == value)
			ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		r[tmp2].push_back(tmp1);
	}
	solve();
	return 0;
}