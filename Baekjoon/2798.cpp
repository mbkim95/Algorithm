#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int> card;

void dfs(int idx, int cnt, int sum) {
	if (sum > m)
		return;

	if (idx == n)
		return;

	if (cnt == 3) {
		if (sum == m){
			cout << m << '\n';
			exit(0);
		}
		else if (sum < m)
			ans = max(ans, sum);
		return;
	}

	for (int i = idx + 1; i < n; i++)
		dfs(i, cnt + 1, sum + card[i]);
}

void solve() {
	for (int i = 0; i < n - 2; i++)
		dfs(i, 1, card[i]);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	card = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());
	solve();
	return 0;
}