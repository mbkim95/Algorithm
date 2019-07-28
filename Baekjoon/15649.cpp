#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> chk;
vector<int> list;

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << list[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			chk[i] = true;
			list.push_back(i);
			dfs(i, cnt + 1);
			chk[i] = false;
			list.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	chk = vector<bool>(n + 1, false);

	for (int i = 1; i <= n; i++) {
		chk[i] = true;
		list.push_back(i);
		dfs(i, 1);
		list.pop_back();
		chk[i] = false;
	}
	return 0;
}
