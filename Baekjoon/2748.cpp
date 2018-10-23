#include <iostream>
using namespace std;

long long dp[91];

int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << '\n';
}