#include <iostream>
#include <algorithm>
using namespace std;

#define DEV 1000000000
int n, dp[101][10];

void precalc() {
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
}

long long solve() {	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % DEV;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % DEV;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DEV;
		}		
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[n][i];

	return sum % DEV;
}

int main() {
	cin >> n;
	precalc();
	cout << solve() << '\n';
}