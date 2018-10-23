#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, c[100], dp[10001];

int solve() {
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++)
			if (j >= c[i])
				dp[j] += dp[j - c[i]];
	}
	return dp[k];
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	cout << solve() << '\n';
}