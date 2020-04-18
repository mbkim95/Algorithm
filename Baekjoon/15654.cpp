#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int num[8];
bool chk[8];
vector<int> ans;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i : ans)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = true;
			ans.push_back(num[i]);
			dfs(i, cnt + 1);
			ans.pop_back();
			chk[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	dfs(-1, 0);
	return 0;
}