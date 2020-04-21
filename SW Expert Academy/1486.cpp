#include <iostream>
#include <algorithm>
using namespace std;

int n, b, ans;
int h[20];

void dfs(int idx, int sum) {
	if (sum > ans) return;
	if (sum >= b) {
		ans = min(ans, sum);
		return;
	}
	if (idx == n) return;

	for (int i = idx + 1; i < n; i++)
		dfs(i, sum + h[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		ans = 987654321;
		cin >> n >> b;
		for (int i = 0; i < n; i++)
			cin >> h[i];
		dfs(-1, 0);
		cout << "#" << c << ' ' << ans - b << '\n';
	}
	return 0;
}