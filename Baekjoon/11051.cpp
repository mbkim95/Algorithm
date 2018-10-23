#include <iostream>
#define MOD 10007
using namespace std;

int n, k, dp[1001][1001];

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[n][k] << endl;
}