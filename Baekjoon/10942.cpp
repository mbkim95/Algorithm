#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int num[2001];
bool dp[2001][2001];

void precalc() {
	for (int i = 1; i <= n; i++) dp[i][i] = true;

	for (int i = 1; i < n; i++) {
		if (num[i] == num[i + 1])
			dp[i][i + 1] = true;
	}
}

void solve() {
	precalc();

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (num[j] == num[j + i] && dp[j + 1][j + i - 1] == true)
				dp[j][j + i] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	cin >> m;

	solve();

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		if (dp[s][e] == true) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}