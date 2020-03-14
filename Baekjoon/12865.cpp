#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> w = vector<int>(n + 1);
	vector<int> v = vector<int>(n + 1);
	vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << dp[n][k] << '\n';
	return 0;
}