#include <iostream>
#define MOD 10007
using namespace std;

int n, dp[1001][10];

int main() {
	cin >> n;	

	for (int i = 0; i <10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}			
		}
	}
	int sum = 0;

	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % MOD;
	cout << sum % MOD << endl;

}