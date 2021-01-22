#include <iostream>
using namespace std;

int s;
long long dp[100001][4];
const int DIV = 1e9 + 9;

void solve(void) {
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		if (i - 1 >= 0) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % DIV;
		}
		if (i - 2 >= 0) {
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % DIV;
		}
		if (i - 3 >= 0) {
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % DIV;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	dp[1][1] = dp[2][2] = dp[3][3] = dp[3][1] = dp[3][2] = 1;
	solve();
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % DIV << '\n';
	}
	return 0;
}